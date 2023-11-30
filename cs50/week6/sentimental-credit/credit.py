# promt the user for a card numb
from cs50 import get_int


def main():
    cn2 = 0
    while True:
        n = get_int("Number: ")
        strn = str(n)
        ln = len(strn)
        if ln >= 1 and ln <= 16:
            break
        # print("INVALID")

    fn = int(strn[0])
    len2 = ln - 2
    len1 = ln - 1
    if (fn >= 3 and fn <= 5) and (ln == 13 or ln == 15 or ln == 16):
        while len2 >= 0:
            cn = int(strn[len2]) * 2
            if cn >= 10:
                cn -= 9
            cn2 += cn
            len2 -= 2
        # print(cn2)
        while len1 >= 0:
            cn2 += int(strn[len1])
            len1 -= 2
        # print(cn2)
        if cn2 % 10 == 0:
            which_card(strn)
        else:
            print("INVALID")
    else:
        print("INVALID")


def which_card(strn):
    n = int(strn[:2])
    if n == 34 or n == n == 37:
        print("AMEX")
    elif n >= 51 and n <= 55:
        print("MASTERCARD")
    elif int(strn[:1]) == 4:
        print("VISA")
    else:
        print(n / 10)
        print("INVALID")


main()