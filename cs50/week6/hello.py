# from cs50 import get_string
# str = input("write something bitch ")

# for i in range(10):
#     print(f"hello vitches{str}")
# str = str.lower()
# if str.lower() in ['y']:
#     print("yeesssss")
# elif str in ['n']:
#     print("noooooo")


# while True:
#     n = int(input('enter numb: '))
#     if n > 0:
#         break
# for i in range(n):
    # print('#')

# from sys import argv

# for arg in argv[0:1]:
#     print(arg)

import sys

# if len(sys.argv) != 2:
#     print("fuck of retard")
#     sys.exit(1)
# else:
#     print("khdem ula 9")
#     sys.exit(0)

# name = ['javi','montif','hmida']

# n = input("write a name")

# if n in name:
#     print("3ada 3ada")
# else:
#     print("retard")

# people ={
#     'javi': '06550050302',
#     'montif': '06777777777'
# }

# n = input("enter:")

# if n in people:
#     print(f"/{people[n]}/")

# n1 = input("f name ")
# n2 = input("s name ")

    # for row in read:
    # print(row['name'])
# with open("ph.csv", "r") as file:
#     read = csv.DictReader(file)
#     for r in sorted(read):
#         print(f"{row['name']}: {row['phone']}")

    # writer = csv.writer(file)
    # writer.writerow([n1, n2])
import csv

# Open CSV file
# with open("ph.csv", "r") as file:

#     # Create DictReader
#     reader = csv.DictReader(file)

#     # Counts
#     counts = {}

#     # Iterate over CSV file, counting favorites
#     for row in reader:
#         favorite = row["name"]
#         if favorite in counts:
#             counts[favorite] += 1
#         else:
#             counts[favorite] = 1

# def value(name):
#     return counts[name]
# Print counts
# for favorite in counts:
    # print(f"{favorite}: {counts[favorite]}")
# for favorite in sorted(counts, key=value, reverse=True):
#     print(f"{favorite}: {counts[favorite]}")

# for favorite in sorted(counts, key=lambda name: counts[name], reverse=True):
#     print(f"{favorite}: {counts[favorite]}")

from cs50 import SQL

db = SQL('sqlite:///ph.db')
name = input("name: ")

rows = db.execute(SELECT * FROM ph WHERE name = 'waejo')

for row in rows:
    print(row['phone'])