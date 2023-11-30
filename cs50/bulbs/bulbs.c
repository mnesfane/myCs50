#include <stdlib.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

const int BITS_IN_BYTE = 8;

void print_bulb(int bit);
void tobinary(char *txt);
void bitchar(int n);
int  intlen(int n);
char *ft_itoa(int n);

int main(void)
{
    // TODO
    //get an input
    char *text = get_string("Message: ");
    //to binary
    tobinary(text);
}

void print_bulb(int bit)
{
    if (bit == 0)
    {
        // Dark emoji
        printf("\U000026AB");
    }
    else if (bit == 1)
    {
        // Light emoji
        printf("\U0001F7E1");
    }
}

void tobinary(char *txt)
{
    int n = 0;
    int i = 0;
    int j = 7;
    int k = 1;

    while (txt[i])
    {
        while (txt[i])
        {
            if (txt[i] % 2 == 1)
            {
                n += k;
            }
            txt[i] = txt[i] / 2;
            k *= 10;
        }
//send bit per bit to print bulbs
        bitchar(n);
        k = 1;
        n = 0;
        i++;
    }
}

void bitchar(int n)
{
    int k;
    int len;
    char *p;
    int i = 0;

    p = ft_itoa(n);
    len = strlen(p);
    while (8 - len)
    {
        print_bulb(0);
        len++;
    }
    while (p[i])
    {
// printf("//%s//", p);
        if (p[i] == '0')
        {
            print_bulb(0);
        }
        if (p[i] == '1')
        {
            print_bulb(1);
        }
        i++;
    }
    printf("\n");
    free(p);
}

int intlen(int n)
{
    int len = 0;

    if (n < 0)
    {
        n *= -1;
        len++;
    }
    while (n > 0)
    {
        n /= 10;
        len++;
    }
    return (len);
}

char *ft_itoa(int n)
{
    long int a;
    char *p;
    int len;

    a = n;
    len = intlen(n);
    if (a == 0)
    {
        len++;
    }
    p = (char *)malloc(len + 1);
    if (!p)
    {
        return (NULL);
    }
    p[len--] = '\0';
    if (a == 0)
    {
        p[0] = '0';
    }
    if (a < 0)
    {
        a = a * -1;
        p[0] = '-';
    }
    while (a > 0)
    {
        p[len--] = (a % 10) + '0';
        a = a / 10;
    }
    return (p);
}