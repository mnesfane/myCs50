// Check that a password has at least one lowercase letter, uppercase letter, number and symbol
// Practice iterating through a string
// Practice using the ctype library

#include <cs50.h>
#include <stdio.h>
#include <ctype.h>

bool valid(string password);

int main(void)
{
    string password = get_string("Enter your password: ");
    if (valid(password))
    {
        printf("Your password is valid!\n");
    }
    else
    {
        printf("Your password needs at least one uppercase letter, lowercase letter, number and symbol\n");
    }
}

// TODO: Complete the Boolean function below
bool valid(string password)
{
    int i = 0;
    int n = 0;
    bool up  = false;
    bool low = false;
    bool num = false;
    bool sym = false;

    while (password[i])
    {
        if(isupper(password[i]))
            up = true;
        else if(isdigit(password[i]))
            num = true;
        else if(islower(password[i]))
            low = true;
        else if(!isalpha(password[i]))
            sym = true;
        i++;
    }
    if (up == true && num == true && low == true && sym == true)
        return (true);
    return false;
}
