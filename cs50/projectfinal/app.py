
from flask import Flask, flash, redirect, render_template, request, session
from flask_session import Session
from cs50 import SQL
from werkzeug.security import check_password_hash, generate_password_hash


app = Flask(__name__)

app.config["SESSION_PERMANENT"] = False
app.config["SESSION_TYPE"] = "filesystem"
Session(app)

db= SQL("sqlite:///users.db")

# @app.route('/', methods=['GET', 'POST'])
# def index():
#     if request.method == 'POST':
#          if 'pomodoro' in request.form and 'short' in request.form and 'long' in request.form and 'interval' in request.form:
#             pomo = request.form.get("pomodoro")
#             short = request.form.get("short")
#             longt = request.form.get("long")
#             interval = request.form.get("interval")
#             if not pomo or not short or not longt or not interval:
#                 return render_template("layout.html", pomo="45", short="15", longt="30", interval="4")
#             return render_template("layout.html", pomo=pomo, short=short, longt=longt, interval=interval)
#          print(f"\n\n\n{titlenote}\n\n")
#          print(f"\n\n\n{note}\n\n")
#          print(f"\n\n\n{pomo}\n\n")
#          print(f"\n\n\n{short}\n\n")
#          print(f"\n\n\n{longt}\n\n")
#          print(f"\n\n\n{interval}\n\n")
#          elif 'titlenote' in request.form and 'note' in request.form:
#             titlenote = request.form.get("titlenote")
#             note = request.form.get("note")
#             if not titlenote:
#                 return render_template("layout.html")
#             return render_template("layout.html", titlenote=titlenote, note=note)
#     else:
#         return render_template("layout.html", pomo="45", short="15", longt="30", interval="4")


@app.route('/', methods=['GET', 'POST'])
def index():
    if request.method == 'POST':
        user = session['user_id']
        if 'pomodoro' in request.form and 'short' in request.form and 'long' in request.form and 'interval' in request.form:
            pomo =     int(request.form.get("pomodoro"))
            short =    int(request.form.get("short"))
            longt =    int(request.form.get("long"))
            interval = int(request.form.get("interval"))
            db.execute("UPDATE users3 SET pomo=? , short=?, longt=?, interval=? WHERE id=?", pomo, short, longt, interval, user)
            data = db.execute("SELECT * FROM users3 WHERE id=?", user)
            return redirect("/")

        if 't' in request.form:
            t = request.form.get("t")
            n = request.form.get("n")
            db.execute("DELETE FROM note WHERE user_id=? AND titlenote= ? AND note= ? ", user, t, n)
            return redirect("/")
            # if n == "":
            #     print(f"\n\n\ndfbdbadfbad{n}\n\n")
            # index = request.form.get("index")

        if 'titlenote' in request.form and 'note' in request.form and request.form['titlenote']:
            titlenote = request.form.get("titlenote")
            note = request.form.get("note")
            db.execute("INSERT INTO note (note, titlenote, user_id) VALUES (?, ?, ?)", note, titlenote, user)
            data = db.execute("SELECT * FROM users3 WHERE id=?", user)
            notedata = db.execute("SELECT note, titlenote FROM note WHERE user_id = ?", user)
            # print(f"\n\n\n{notedata}\n\n")
            return redirect("/")
    else:
        if session:
            user = session['user_id']
            data = db.execute("SELECT * FROM users3 WHERE id=?", user)
            notedata = db.execute("SELECT note, titlenote FROM note WHERE user_id = ?", user)
            return render_template("layout.html", pomo=data[0]['pomo'], short=data[0]['short'], longt=data[0]['longt'], interval=data[0]['interval'], notedata=notedata)
        return render_template("layout.html", pomo=45, short=15, longt=30, interval=4)

@app.route('/login', methods=['GET', 'POST'])
def login():
    session.clear()
    if request.method == 'POST':
        username = request.form.get("username")
        password = request.form.get("password")
        if not username:
            return render_template("login.html", error="not username")
        if not password:
            return render_template("login.html", error="not password")
        data = db.execute("SELECT * FROM users3 WHERE username=?", username)
        if len(data) != 1 or not check_password_hash(data[0]['hash'], password):
            return render_template("login.html", error="len(data) != 1 or not check_password_hash(data[0]['hash'], password)")
        session['user_id'] = data[0]['id']
        return redirect("/")

    else:
        return render_template("login.html")

@app.route('/register', methods=['GET', 'POST'])
def register():
    if request.method == 'POST':
        if not request.form.get("username") or  not request.form.get("password") or not request.form.get("confirm"):
            return redirect("/")
        password = request.form.get("password")
        username = request.form.get("username")
        confirm = request.form.get("confirm")
        if password != confirm:
            print("\n\n\n\dmsfijnasodifnoan\n\n\n")
            return render_template("register.html", error="password != confirm")
        data = db.execute("SELECT * FROM users3")
        for d in data:
            if d['username'] == username:
                return render_template("register.html", error="d['username'] in username")
        hpassword = generate_password_hash(password, method='pbkdf2:sha256', salt_length=8)
        db.execute("INSERT INTO users3 (username, hash) VALUES(?, ?)", username, hpassword)
        row = db.execute("SELECT * FROM users3 WHERE username = ?", username)
        session["user_id"] = row[0]['id']



        return redirect("/")


        # if not request.form.get()
    else:
        return render_template("register.html")

@app.route('/logout')
def logout():
    session.clear
    session.pop('user_id', None)
    return redirect("/")

