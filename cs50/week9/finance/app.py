import os

from cs50 import SQL
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from tempfile import mkdtemp
from werkzeug.security import check_password_hash, generate_password_hash

from helpers import apology, login_required, lookup, usd

#
from colorama import Fore, Style
import sys
#

# Configure application
app = Flask(__name__)

# Custom filter
app.jinja_env.filters["usd"] = usd

# Configure session to use filesystem (instead of signed cookies)
app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)
id = 0

# Configure CS50 Library to use SQLite database
db = SQL("sqlite:///finance.db")

# Make sure API key is set
if not os.environ.get("API_KEY"):
    raise RuntimeError("API_KEY not set")


@app.after_request
def after_request(response):
    """Ensure responses aren't cached"""
    response.headers["Cache-Control"] = "no-cache, no-store, must-revalidate"
    response.headers["Expires"] = 0
    response.headers["Pragma"] = "no-cache"
    return response


@app.route("/")
@login_required
def index():
    """Show portfolio of stocks"""
    user = session['user_id']
    data = db.execute("SELECT symbol, name, SUM(shares) as totalshares, price FROM transac WHERE user_id=? GROUP BY symbol", user)
    cash = db.execute("SELECT cash FROM users WHERE id=?", user)[0]['cash']
    total = cash
    for stock in data:
        total += stock['totalshares'] * stock['price']
    return render_template("index.html", sdata=data, cash=cash, total= total, usd=usd)


@app.route("/buy", methods=["GET", "POST"])
@login_required
def buy():
    if request.method == "POST":
        symbol = request.form.get("symbol").upper()
        stockdata = lookup(symbol)
        if not request.form.get("shares"):
            return apology ("w9ef 3nd 7eddek", 400)
        try:
            shares = int(request.form.get("shares"))
        except:
                return apology("must be int")
        if not symbol:
            return apology("enter symbol", 400)
        if not stockdata:
            return apology("invalid symbol", 400)
        if shares < 1:
            return apology ("w9ef 3nd 7eddek", 400)
        user = session['user_id']
        cash = db.execute("SELECT (cash) FROM users WHERE id= ? ", user)[0]['cash']
        total = stockdata['price'] * shares
        if total < cash:
            db.execute("UPDATE users SET cash =? WHERE id=?", cash - total, user)
            db.execute("INSERT INTO transac (user_id, name, shares, price, type, symbol) VALUES(?, ?, ?, ?, ?, ?)", user, stockdata['name'], shares, stockdata['price'], "buy", symbol)
            return redirect('/')
        else:
            return apology("ur broke", 400)
    else:
        return render_template("buy.html")

    """Buy shares of stock"""


@app.route("/history")
@login_required
def history():
    """Show history of transactions"""
    user = session['user_id']
    cash = db.execute("SELECT cash FROM users WHERE id=?", user)[0]['cash']
    data = db.execute("SELECT symbol, shares, price, time FROM transac WHERE user_id=?", user)
    return  render_template("history.html", data=data, cash=cash, usd=usd)


@app.route("/login", methods=["GET", "POST"])
def login():
    """Log user in"""
    # Forget any user_id
    session.clear()

    # User reached route via POST (as by submitting a form via POST)
    if request.method == "POST":

        # Ensure username was submitted
        if not request.form.get("username"):
            return apology("must provide username", 400)

        # Ensure password was submitted
        elif not request.form.get("password"):
            return apology("must provide password", 400)

        # Query database for username
        rows = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))

        # Ensure username exists and password is correct
        if len(rows) != 1 or not check_password_hash(rows[0]["hash"], request.form.get("password")):
            return apology("invalid username and/or password", 400)

        # Remember which user has logged in
        session["user_id"] = rows[0]["id"]

        # Redirect user to home page
        return redirect("/")

    # User reached route via GET (as by clicking a link or via redirect)
    else:
        return render_template("login.html")


@app.route("/logout")
def logout():
    """Log user out"""

    # Forget any user_id
    session.clear()

    # Redirect user to login form
    return redirect("/")


@app.route("/quote", methods=["GET", "POST"])
@login_required
def quote():
    """Get stock quote."""
    if request.method == "POST":
        stockdata = lookup(request.form.get("symbol").upper())
        if not stockdata:
            return apology("Invalid Symbol WOOOWO2OOOW", 400)
        return render_template("quote2.html", Data=stockdata, usd=usd)
    else:
        return render_template("quote.html")


@app.route("/register", methods=["GET", "POST"])
def register():
    """Register user"""
    if request.method == "POST":
            # must provide username PASS AND CHECK PASS
        if not request.form.get("username") or not request.form.get("password") or not request.form.get("confirmation"):
            return apology("Camera WOOOWOOOOW", 400)
        if request.form.get("password") != request.form.get("confirmation"):
            return apology("Camera WOOOWOOOOW", 400)
        data = db.execute("SELECT * FROM users")
        for dt in data:
            if dt['username'] == request.form.get("username"):
                return apology("used name WOOOWOOOOW", 400)
        password = request.form.get("password")
        hpassword = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)
        db.execute("INSERT INTO users (username, hash) VALUES(?, ?)", request.form.get("username"), hpassword)
        row = db.execute("SELECT * FROM users WHERE username = ?", request.form.get("username"))
        session["user_id"] = row[0]['id']
        return redirect("/")

    else:
        return render_template("register.html")




@app.route("/sell", methods=["GET", "POST"])
@login_required
def sell():
    """Sell shares of stock"""
    user = session["user_id"]
    if request.method == "POST":
        try:
            shares = int(request.form.get("shares"))
        except:
            return apology ("must be int")
        if shares < 1:
            return apology ("w9ef 3nd 7eddekkkkkkk", 400)
        symbol = request.form.get("symbol")
        if not symbol:
            return apology ("w9ef 3nd 7eddekkkkkkk", 400)
        cash = db.execute("SELECT cash FROM users WHERE id=?", user)[0]['cash']
        data = db.execute("SELECT symbol, SUM(shares) as totalshares, price, name FROM transac WHERE user_id=? AND symbol=? GROUP BY symbol", user, symbol)
        if not data:
            return apology ("w9ef 3nd 7eddekkkkkkk no data", 400)
        if data[0]['totalshares'] <= 0:
            return apology ("w9ef 3nd 7eddekkkkkkk", 400)
        if shares > data[0]['totalshares']:
            return apology("more than u have", 400)
        else:
            total = shares * data[0]['price']
            sellshares = shares * -1
            db.execute("INSERT INTO transac (user_id, name, shares, price, type, symbol) VALUES(?, ?, ?, ?, ?, ?)", user, data[0]['name'], sellshares, data[0]['price'], "sell", symbol)
            db.execute("UPDATE users SET cash =? WHERE id=?", cash + total, user)
            return redirect('/')

    else:
        symb = db.execute("SELECT symbol FROM transac WHERE user_id=? GROUP BY symbol", user)
        return render_template("sell.html", symb=symb)

@app.route("/password", methods=["GET","POST"])
@login_required
def passw():
    if request.method == "POST":
        user = session['user_id']
        old = request.form.get("oldpass")
        new = request.form.get("newpass")
        pwordhash = db.execute("SELECT hash FROM users WHERE id=?", user)[0]['hash']
        if not old or not new:
            return apology("code", 400)
        if old == new:
            return apology("same", 400)
        if check_password_hash(pwordhash, old):
            newhash = generate_password_hash(new, method='pbkdf2:sha256', salt_length=8)
            db.execute("UPDATE users SET hash=? WHERE id=?",newhash , user)
        else:
            return apology("w9ef 3nd 7eddek , enter old pass", 400)
        return redirect("/")

    else:
        return render_template("password.html")