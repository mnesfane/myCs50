#include <cs50.h>
#include <stdio.h>

void all_side(int n);

int main(void)
{
    int n;

    //promt user until write number
    do
    {
        n = get_int("height? ");
    }
    while (n < 1 || n > 8);
    //draw that shit whit while loops
    all_side(n);


}

void all_side(int n)
{
    int i = 1;
    int j = 1;
    int k = 1;
    int f = 1;

    f = n;
    while (i <= n)
    {
        while (k < f)
        {
            printf(" ");
            k++;
        }
        k = 1;
        f--;
        while (j <= i * 2)
        {
            while (j <= i)
            {
                printf("#");
                j++;
            }
            printf("  ");
            while (j <= i * 2)
            {
                printf("#");
                j++;
            }
        }
        j = 1;
        printf("\n");
        // left_side(n);
        i++;
    }
}