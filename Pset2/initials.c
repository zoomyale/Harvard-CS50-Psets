#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    string name = get_string();
    if (name != NULL)
    {
        //print the first character as uppercase
        printf("%c", toupper(name[0]));
        
        for (int i = 0, n = strlen(name); i < n; i++)
        {
            //once found ' ' then print the next character
            if ( name[i] == ' ' && i + 1 < n)
            {
                printf("%c", toupper(name[i+1]));
            }
        }
    }
    printf("\n");
}