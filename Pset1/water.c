#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    int min = get_int();
    printf("bottles: %i\n", min * 12);
}