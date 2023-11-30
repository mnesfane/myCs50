from cs50 import SQL

db = SQL('sqlite:///ph.db')
name = input("name: ")

rows = db.execute("SELECT COUNT(*) AS N FROM ph WHERE name = ?", name)

# for row in rows:
#     print(row["N"])
print(rows[0])