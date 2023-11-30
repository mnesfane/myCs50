// Practice writing a function to find a max value

#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int max(int array[], int n);

int main(void)
{
    int n;
    do
    {
        n = get_int("Number of elements: ");
    }
    while (n < 1);

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        arr[i] = get_int("Element %i: ", i);
    }

    printf("The max value is %i.\n", max(arr, n));
}

// TODO: return the max value
int max(int array[], int n)
{
    int i = 0;
    int max = 0;
    int j = i + 1;

    while (i < n)
    {
        max = array[i];
        if (array[i + 1] > array[i])
        {
            max = array[i + 1];
        }
        i++;
    }
    return max;
}
