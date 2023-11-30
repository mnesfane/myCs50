// Write a function to replace vowels with numbers
// Get practice with strings
// Get practice with command line
// Get practice with switch

#include <cs50.h>
#include <stdio.h>

void vowels(char *leet)
{
    int i = 0;

    while (leet[i])
    {
        switch (leet[i])
        {
            case 'e':
                leet[i] = '3';
                break;
            case 'a':
                leet[i] = '6';
                break;
            case 'i':
                leet[i] = '1';
                break;
            case 'o':
                leet[i] = '0';
                break;
            case 'l':
                leet[i] = '1';
                break;
            case 't':
                leet[i] = '7';
                break;
        }
        i++;
    }
    printf ("//%s//\n", leet);
}

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("another one");
    }
    else
        vowels(argv[1]);
}
