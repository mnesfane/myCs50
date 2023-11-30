#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

char *cipher(char *s, int k);

int main(int argc, string argv[])
{
    int i = 0;
    int     n;
    char   *s;
    if (argc != 2)
    {
        return (printf("Usage: ./caesar key\n"), 1);
    }
    else
    {
        while (argv[1][i])
        {
            if (!isdigit(argv[1][i]))
            {
                return (printf("Usage: ./caesar key"), 1);
            }
            i++;
        }
        n = atoi(argv[1]);
        // get data
        s = get_string("plaintext:  ");
        s = cipher(s, n);
        printf("ciphertext: %s\n", s);
    }

}

char *cipher(char *s, int k)
{
    int i = 0;
    while (s[i])
    {
        if (isupper(s[i]))
        {
            if (k > 26)
            {
                while (k > 26)
                {
                    k -= 26;
                }
            }
            if (s[i] + k > 90)
            {
                s[i] = s[i] + k - 91 + 65;
            }
            else
            {
                s[i] = s[i] + k;
            }
        }
        else if (islower(s[i]))
        {
            if (k > 26)
            {
                while (k > 26)
                {
                    k -= 26;
                }
            }
            if (s[i] + k > 122)
            {
                s[i] = s[i] + k - 123 + 97;
            }
            else
            {
                s[i] = s[i] + k;
            }
        }
        i++;
    }
    return (s);
}