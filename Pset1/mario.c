#include <stdio.h>
#include <cs50.h>

void pyramid(int i, int height);

int main(void)
{
    int height;
    do {
        printf("Height: ");
        height = get_int();
    } while (height < 0 || height >23);
    
    for (int i = 0; i < height; i ++)
    {
        pyramid(i, height);
    }
}

void pyramid(int i, int height)
{
    for (int x = 1; x < height - i; x ++)
    {
        printf(" ");
    }
    for (int n = 0; n <= i; n ++)
    {
        printf("#");
    }
    printf("#\n");
}