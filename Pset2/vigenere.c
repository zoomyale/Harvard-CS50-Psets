#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int letters_only(string s);
char cipher(char c, string k, int i);

int main(int argc, string argv[])
{
    //check if it takes just one alphabetical command-line argument
    if (argc != 2 || letters_only(argv[1]) == 0)
    {
        printf("Error! Usage: ./caesar k\n");
        return 1;
    }
    
    string k = argv[1];
    
    printf("plaintext:");
    string plain = get_string();
    
    printf("ciphertext:");
    for (int i = 0, j = 0, n = strlen(plain); i < n; i++)
    {
        int p = (int) plain[i];
        //if i'th char is a letter
        if ((p > 64 && p < 91 ) || (p > 96 && p < 123))
        {
            //print the letter ciphered by j'th char of keyword
            printf("%c", cipher(plain[i],k,j));
            j++;
        }
        //if i'th char is not a letter
        else
        {
            //j doesn't increment, so j'th char of keyword will be used to next letter
            printf("%c", plain[i]);
        }
    }
    printf("\n");
}

char cipher(char c, string k, int j)
{
    int rel;
    int p = (int) c;
    
    //reuse the keyword cyclically
    j = j % strlen(k);
    
    //get the keyword value
    int key = toupper(k[j]) - 65;
    
    if (p > 64 && p < 91 )
    {
        //if the cipher integer is out of alphabet, wrap to A
        if ((p + key) > 90) rel = (p + key) % 90 + 64;
        else rel = p + key;
    }
    else
    {
        //if the cipher integer is out of alphabet, wrap to a
        if ((p + key) > 122) rel = (p + key) % 122 + 96;
        else rel = p + key;
    }
    return (char) rel;
}

int letters_only(string s)
{
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        int x = (int) s[i];
        if ((x < 65) || (x > 90 && x < 97) || (x > 122))
        {
            return 0;
        }
    }

    return 1;
}