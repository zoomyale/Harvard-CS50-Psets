#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

char cipher(char c, int k);

int main(int argc, string argv[])
{
    //check if it takes just one command-line argument
    if (argc != 2)
    {
        printf("Error! Usage: ./caesar k\n");
        return 1;
    }
    
    //get integer from the string
    int k = atoi(argv[1]);
    
    printf("plaintext:");
    string plain = get_string();
    
    printf("ciphertext:");
    for (int i = 0, n = strlen(plain); i < n; i++)
    {
        printf("%c", cipher(plain[i],k));
    }
    printf("\n");
}

char cipher(char c, int k)
{
    int rel;
    int p = (int) c;
    k = k % 26;
    
    if (p > 64 && p < 91 )
    {
        //if the cipher integer is out of alphabet, wrap to A
        if ((p + k) > 90) rel = (p + k) % 90 + 64;
        else rel = p + k;
    }
    else if (p > 96 && p < 123)
    {
        //if the cipher integer is out of alphabet, wrap to a
        if ((p + k) > 122) rel = (p + k) % 122 + 96;
        else rel = p + k;
    }
    else
    {
        rel = p;
    }
    return (char) rel;
}