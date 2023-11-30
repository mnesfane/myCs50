import sys
from cs50 import get_int
def main():
    n = 0
    j = 0
    while n < 1 or n > 8:
        n = get_int("Height: ")
    for i in range(n):
        for j in range(n):
            if i + j >= n - 1:
                print("#", end="")
            else:
                print(" ", end="")
            #   end of this above for loop
        print("  ", end="")
        for k in range(i + 1):
            print("#", end="")
        print()


main()