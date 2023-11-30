#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

long prompt_card(void);
void check_sum(long n, int sn);
int count_numb(long n);
int start_numb(long n);
void which_card(long n);

int main(void)
{
    long   n;
    int   nb;
    int   sn;
    //prompt a card nub
    n = prompt_card();
    //count numb
    nb = count_numb(n);
    sn = start_numb(n);
    //calculate the checksum
    if ((nb == 13 || nb == 15 || nb == 16) && (sn >= 3 && sn <= 5))
        check_sum(n, sn);
    else
    {
       return(printf("INVALID\n"), 0);
    }
    which_card(n);
}

long prompt_card(void)
{
    long n;
    do
    {
        n = get_long("card numb? ");
    }
    while (n <= 0 || n >= 10000000000000000);
    return (n);
}

void check_sum(long n, int sn)
{
    long x = 10;
    long y1 = 0;
    long y2 = 0;
    long y3 = 0;
    long y4 = 0;
    long m  = 0;

    m = n;
    while (m / x != 0)
    {
        m = m / x;
        y1 = (m % 10) * 2;
        if (y1 >= 10)
            y1 = y1 - 9;
        y2 = y2 + y1;
        x = 100;
    }
    m = n;
    x = 1;
    while (m / x != 0)
    {
        m = m / x;
        y3 = (m % 10);
        y4 = y4 + y3;
        x = 100;
    }
    if ((y4 + y2) % 10 != 0)
    {
        printf("INVALID\n");
        exit(0);
    }
}

int start2_numb(long n)
{
    int i = 1;
    while (n >= 100)
    {
        i++;
        n = n / 10;
    }
    return (n);
}
int start_numb(long n)
{
    int i = 1;
    while (n / 10 != 0)
    {
        i++;
        n = n / 10;
    }
    return (n);
}

int count_numb(long n)
{
    int i = 1;
    while (n / 10 != 0)
    {
        i++;
        n = n / 10;
    }
    return (i);
}

void which_card(long n)
{
    int s2n;

    s2n = start2_numb(n);
    if (s2n == 34 || s2n == 37)
        printf("AMEX\n");
   else if (s2n >= 51 && s2n <= 55)
        printf("MASTERCARD\n");
    else if (s2n / 10 == 4)
        printf("VISA\n");
    else
         printf("INVALID\n");
}