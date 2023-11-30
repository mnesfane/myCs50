from flask import Flask, render_template, request, redirect
from cs50 import sql


app = Flask(__name__)

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
         titlenote = request.form.get("titlenote")
         note = request.form.get("note")
         pomo = request.form.get("pomodoro")
         short = request.form.get("short")
         longt = request.form.get("long")
         interval = request.form.get("interval")
        #  print(f"\n\n\n{titlenote}\n\n")
        #  print(f"\n\n\n{note}\n\n")
        #  print(f"\n\n\n{pomo}\n\n")
        #  print(f"\n\n\n{short}\n\n")
        #  print(f"\n\n\n{longt}\n\n")
        #  print(f"\n\n\n{interval}\n\n")
         if not titlenote and not note:
            if not pomo or not short or not longt or not interval:
                return render_template("layout.html", pomo="45", short="15", longt="30", interval="4")
            return render_template("layout.html", pomo=pomo, short=short, longt=longt, interval=interval)
         else:
            if not titlenote or not note:
                return render_template("layout.html")
            return render_template("layout.html", titlenote=titlenote, note=note)
        # return render_template("layout.html")
    else:
        return render_template("layout.html")

@app.route('/login', methods=['GET', 'POST'])
def login():
    if request.method == 'POST':
        print("fuckoff")
    else:
        return render_template("login.html")