#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void checkkey(char *s);
char *cipher(char *s, char *p);

int main(int ac, string av[])
{
    char *p;

    if (ac != 2)
    {
        printf("Usage: ./substitution key\n");
        exit(1);
    }
    else
    {
        char d[strlen(av[1]) + 1];
        memcpy(d, av[1], strlen(av[1]) + 1);
//check lenght repeated chars , and just chars
        checkkey(d);
        p = get_string("plaintext:  ");
//cipher the text
        p = cipher(d, p);
    }
}

void checkkey(char *s)
{
    int i = 0;
    int ln = strlen(s);

    if (ln != 26)
    {
        printf("Key must contain 26 characters.");
        exit(1);
    }
    while (s[i])
    {
        s[i] = toupper(s[i]);
        i++;
    }
    i = 0;
    while (s[i])
    {
        if (!isalpha(s[i]))
        {
            printf("Usage: ./substitution key");
            exit(1);
        }
        for (int j = i + 1; j < ln; j++)
        {
            if (s[i] == s[j])
            {
                printf("klkhuuu");
                exit(1);
            }
        }
        i++;
    }

}

char *cipher(char *av, char *p)
{
    int i = 0;
    int c = 0;
    char pu[strlen(p) + 1];

    memcpy(pu, p, strlen(p) + 1);
    while (pu[i])
    {
        if (islower(pu[i]))
        {
            pu[i] = toupper(pu[i]);
        }
        i++;
    }
    i = 0;
    while (pu[i])
    {
        if (isalpha(pu[i]))
        {
            pu[i] = av[pu[i] - 65];
        }
        i++;
    }
    i = 0;
    while (p[i])
    {
        if (isalpha(p[i]))
        {
            if (islower(p[i]))
            {
                pu[i] = tolower(pu[i]);
            }
        }
        i++;
    }
    p = pu;
    printf("ciphertext: %s\n", p);
    return (p);
}