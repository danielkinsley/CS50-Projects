#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, string argv[])
{
    if (argc != 2)  //command line argument check
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }


    string key = argv[1];


    for (int i = 0; i < strlen (argv[1]); i++) //key input check
    {
        if (!isdigit(argv[1][i]))
        {
            printf("Usage: ./caesar key\n"); // error message
            return 1;
        }
    }
    printf("Success\n%s\n", key);

    string plaintext = get_string("plaintext: ");

    int k = atoi(key);    //key to int
    printf("ciphertext: ");

    for (int i = 0; i <strlen(plaintext); i++)
    {
        if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 65) + k) %26) + 65);
        }

        else if(islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 97) + k) %26) + 97);
        }

        else
        {
            printf("%c", plaintext[i]);
            }
    }
    printf("\n");
}

