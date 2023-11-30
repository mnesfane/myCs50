#include <cs50.h>
#include <stdio.h>




void draw(int n)
{
    if (n <= 0)
        return;
    
    draw (n - 1);

    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
    printf("\n");
}

int main()
{
    int n = get_int("n: ");
    draw(n);
}


// int main(void)
// {
//     int n;
//     int j;
//     int i = 0;
// //check start and end data if correct
//     do
//     {
//         n = get_int("Start size : ");
//     }
//     while (n < 9);
//     do
//     {
//         j = get_int("End size: ");
//     }
//     while (j < n);
// //count how many years will it take until reaching the end size
//     while(n < j)
//     {
//         n = n + n/3 - n/4;
//         i++;
//     }
//     printf ("Years: %i", i);
// }