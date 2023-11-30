import pyfiglet
import sys

# print(len(sys.argv))
# print(sys.argv[1])
# sys.exit(0)

if len(sys.argv) != 1 and len(sys.argv) != 3:
    print("Invalid usage1")
    sys.exit(1)
else:
    if len(sys.argv) == 3:
        if sys.argv[1] != '-f' and sys.argv[1] != '--font':
            print("Invalid usage2")
            sys.exit(1)
    s = input("text: ")
    if len(sys.argv) == 3:
        try:
            print(pyfiglet.figlet_format(s, font=sys.argv[2]))
        except pyfiglet.FontNotFound:
            sys.exit(1)
            # print("Invalid usage3")
    else:
        print(pyfiglet.figlet_format(s))




    # if len(sys.argv) == 1:





