#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //prompts the user for their card number
    long num = get_long("Number: ");

    //counts the number of digits in the number using the while loop
    long dig = 0;

    long blank = num;

    while (blank > 0)
    {
        blank /= 10;
        dig++;
    }

    //beginning of checksum
    int part1 = 0;
    int part2 = 0;
    long copy = num;
    long total = 0;
    int mod;
    int mods;
    int dig1;
    int dig2;

    do
    {
        //adding un-underined digits together
        mod = copy % 10;
        copy /= 10;
        part2 = part2 + mod;

        //manipulating underlined digits
        mods = copy % 10;
        copy /= 10;

        //doubling underlined digits
        mods = mods * 2;
        dig1 = mods % 10;
        dig2 = mods / 10;
        part1 = part1 + dig1 + dig2;
    }
    while (copy > 0);

    total = part1 + part2;

    // separating beginning digits
    long n = num;

    do
    {
        n /= 10;
    }
    while (n > 100);

    //checks number of digits
    if (dig != 13 && dig != 15 && dig != 16)
    {
        printf("INVALID\n");
    }

    //checks if number passes checksum
    else if (total % 10 != 0)
    {
        printf("INVALID\n");
    }

    //checks if card is American Express
    else if ((n / 10 == 3) && (n % 10 == 4 || n % 10 == 7))
    {
        printf("AMEX\n");
    }

    //checks if card is Mastercard
    else if (n / 10 == 5 && 0 < n % 10 && n % 10 < 6)
    {
        printf("MASTERCARD\n");
    }

    //checks if card is Visa
    else if (n / 10 == 4)
    {
        printf("VISA\n");
    }

    // if none of the requirements for the types of cards are met, prints invalid
    else
    {
        printf("INVALID\n");
    }
}