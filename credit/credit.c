#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    long creditcardnumber;

    do
    {
        printf("PLease enter CC number: \n");
        scanf("%ld", &creditcardnumber);
    }
    while (creditcardnumber <= 0);

    long workingcc = creditcardnumber; //variables
    int sum = 0;
    int count = 0;
    long divisor = 10;
    char result[11];

    while (workingcc > 0)
    {
        int lastdigit = workingcc % 10;
        sum = sum + lastdigit;
        workingcc = workingcc / 100;
    }

    workingcc = creditcardnumber / 10;
    while (workingcc > 0)
    {
        int lastdigit = workingcc % 10;
        int timestwo = lastdigit * 2;
        sum = sum + (timestwo % 10) + (timestwo / 10);
        workingcc = workingcc / 100;
    }

    workingcc = creditcardnumber;     // Number length
    while (workingcc != 0)
    {
        workingcc = workingcc / 10;
        count++;

    }
    for (int i = 0; i < count - 2; i++)
    {
        divisor = divisor * 10;
    }

    int firstdigit = creditcardnumber / divisor;
    int firsttwodigits = creditcardnumber / (divisor / 10);

    if (sum % 10 == 0)                // Final checks
    {
        if (firstdigit == 4 && (count == 13 || count == 16))
        {
            strcpy(result, "VISA");
        }
        else if ((firsttwodigits == 34 || firsttwodigits == 37) && count == 15)
        {
            strcpy(result, "AMEX");
        }
        else if ((50 < firsttwodigits && firsttwodigits < 56) && count == 16)
        {
            strcpy(result, "MASTERCARD");
        }
        else
        {
            strcpy(result, "INVALID");
        }
    }
    else
    {
        strcpy(result, "INVALID");
    }
    printf("%s\n", result);

}