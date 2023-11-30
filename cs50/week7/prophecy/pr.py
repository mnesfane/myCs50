import csv
from cs50 import SQL
students = []
houseslst = []
relat = []

def cr_houses(house, houseslst, head):
        cnt = 0
        for h in houseslst:
            cnt = 0
            if h['house'] == house:
                cnt = 1
        if cnt == 0:
            houseslst.append({"house": house, "head": head})

def cr_stdutent(name, students):
     students.append({"student_name": name})

def cr_relat(name, house, relat):
     relat.append({"student_name": name, "house": house})

data = SQL("sqlite:///roster.db")

with open("students.csv", 'r') as file:
    read = csv.DictReader(file)
    for row in read:
        name = row['student_name']
        house = row['house']
        head = row['head']
        cr_houses(house, houseslst, head)
        cr_stdutent(name, students)
        cr_relat(name, house, relat)

for std in students:
     data.execute("INSERT INTO new_student (student_name) VALUES (?)", std['student_name'])
 
for house in houseslst:
     data.execute("INSERT INTO house (house, head) VALUES (?,?)", house['house'], house['head'])

for r in relat:
     data.execute("INSERT INTO relat (student_name,house) VALUES (?,?)", r['student_name'], r['house'])