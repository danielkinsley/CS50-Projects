#include <cs50.h>
#include <stdio.h>

int main(void)
{
    // Initialize int variables
    int height, row, column, space;
    do
    {
        height = get_int("Enter Height 8 or lower: "); // Prompt for input
    }
    while (height < 1 || height > 8);

    for (row =0; row < height; row++)
    {
        for (space =0; space < height - row - 1; space++) // Formula for #
        {
            printf(" ");
        }
        for(column = 0; column <= row; column++)
        {
            printf("#");
        }
        printf("  "); /// spacing
        for (column = 0; column <=row; column++) // reuse logic and print!
        {
            printf("#");
        }
        printf("\n");
    }

}