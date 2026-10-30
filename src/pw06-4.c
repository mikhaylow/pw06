#include <stdio.h>

int main(void)
{
    // 18

    double salary = 0.0;

    if (scanf("%lf", &salary) == 0) return -1;

    printf("Salary: %.2f\n", salary);

    if (salary >= 1000.0)
    {
        salary *= 0.85;
        printf("Salary over 1000: Discount 15%% - Total: %.2f\n", salary);
    }
    else if (salary >= 500.0)
    {
        salary *= 0.90;
        printf("Salary over 500: Discount 10%% - Total: %.2f\n", salary);
    }
    else if (salary >= 100.0)
    {
        salary *= 0.95;
        printf("Salary over 100: Discount 5%% - Total: %.2f\n", salary);
    }

    return 0;
}