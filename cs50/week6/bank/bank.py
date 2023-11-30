from sys import exit

p = input("greeting: ")

if 'hello' in p.lower() or p.lower() == 'hello':
    print("$0", end="")
elif p[0].lower() == 'h':
    print("$20", end="")
else:
    print("$100", end="")
