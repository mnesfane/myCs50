#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <math.h>

void count(char *text, float *w, float *l, float *s);

int main(void)
{
    char *text;
    float w = 1;
    float l = 0;
    float s = 0;
    float L = 0;
    float S = 0;
    float n = 0;
//get texxt
    text = get_string("Text: ");
//count letters ,words , sentences
    count(text, &w, &l, &s);
//average
    L = l / w * 100;
    S = s / w * 100;
//count the index
    n = round(0.0588 * L - 0.296 * S - 15.8);
//print results
    if (n >= 16)
    {
        printf("Grade 16+\n");
    }
    else if (n < 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %d\n", (int)n);
    }
}

void count(char *text, float *w, float *l, float *s)
{
    int i = 0;

    while (text[i])
    {
        if (isalpha(text[i]))
        {
            *l += 1;
        }
        if (text[i] == ' ')
        {
            *w += 1;
        }
        if (text[i] == '?' || text[i] == '.' || text[i] == '!')
        {
            *s += 1;
        }
        i++;
    }
}