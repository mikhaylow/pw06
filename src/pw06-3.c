#include <stdio.h>
#include <stdbool.h>

int get_char_to_int(void);
bool isPalindrome(int x);

int main(void)
{
    // 12

    int number = 0;

    int numbers[5] = {0};

    size_t i = 0;

    while ((number = get_char_to_int()) != 0)
    {
        if (isPalindrome(number))
        {
            numbers[i] = number;
            printf("palindrome number: %d\n", number);
        }
        else 
        {
            numbers[i] = number;
            printf("other number: %d\n", number);
        }
        i++;
        if (i == 5)
        {
            break;
        }
    }

    int sum = 0;

    int numbers_len = sizeof(numbers) / sizeof(numbers[0]);

    for (size_t i = 0; i < numbers_len; i++)
    {
        sum += numbers[i];
    }

    int average = sum / numbers_len;

    printf("average: %d\n", average);

    return 0;
}

int get_char_to_int(void)
{
    int ch, number, sign;

    ch = 0;
    number = 0;
    sign = 1;

    while ((ch = getchar()) != EOF && (ch < '0' || ch > '9') && ch != '-'){}

    if (ch == '-')
    {
        sign = -1;
        ch = getchar();
    }

    while (ch != EOF && ch >= '0' && ch <= '9')
    {
        number = number * 10 + (ch - '0');
        ch = getchar();
    }
    
    return number * sign;
}

bool isPalindrome(int x)
{
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;

    int original, reversed, remainder;

    original = x;
    reversed = 0;
    remainder = 0;

    while (x > 0)
    {
        remainder = x % 10;
        reversed = reversed * 10 + remainder;
        x = x / 10;
    }

    if (original == reversed) return true;
    else return false;
}