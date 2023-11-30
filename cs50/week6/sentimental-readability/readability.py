from cs50 import get_string


def main():
    c = 0.0
    w = 1.0
    s = 0.0
    # prompt the user for a string txt
    txt = get_string("Text: ")
    # count chars words sentences
    c, w, s = count(txt, c, w, s)
    c = (c / w) * 100
    s = (s / w) * 100
    n = round(0.0588 * c - 0.296 * s - 15.8)
    if n >= 16:
        print("Grade 16+")
    elif n < 1:
        print("Before Grade 1")
    else:
        print(f"Grade {n}")


def count(txt, c, w, s):
    i = 0
    # iterate over the txt
    while i < len(txt):
        if txt[i].isalpha():
            c += 1
        if txt[i] == ' ':
            w += 1
        if txt[i] == '?' or txt[i] == '.' or txt[i] == '!':
            s += 1
        i += 1
    return c, w, s


main()