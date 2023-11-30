from flask import Flask, render_template, request

app = Flask(__name__)

@app.route('/', methods=['GET','POST'])
def index1():
    if request.method == 'GET':
        return "wa ta 9ra 3la cyber sec chwia"
    else:
        print("choice submitted")
        car = request.form.get("car")
        return render_template("car.html", car=car)