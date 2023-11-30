#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int convert(string input);

int main(void)
{
    string input = get_string("Enter a positive integer: ");

    for (int i = 0, n = strlen(input); i < n; i++)
    {
        if (!isdigit(input[i]))
        {
            printf("Invalid Input!\n");
            return 1;
        }
    }

    // Convert string to int
    printf("%i\n", convert(input));
}

int convert(string input)
{
    // TODO
    if (input[1] == '\0')
    {
    // printf("//f%df//", input[0] - '0');
        return input[0] - '0';
    }
    int n;
    int r;
    int rs = 0;

    n = input[strlen(input) - 1] - '0';
    input[strlen(input) - 1] = '\0';
    rs = convert(input);
//    printf("//%s//", input);
//     exit (0);
   rs = rs * 10 + n;
    // printf("//%d//", rs);
    // exit (0);
   return (rs);
}