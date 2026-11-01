#include <stdio.h>
#include <unistd.h>
#include <string.h>

void clear_screen();
int absolute_value(int value);
double ceil(double value);
double floor(double value);
int get_int_num();
double get_double_num();

int main(void)
{
    // 22

    int choice, value, result;

    choice = 0;
    value = 0;
    result = 0;

    double d_value, d_result;
    d_value = 0.0;
    d_result = 0.0;

    int flag = 1;

    while (flag)
    {
        clear_screen();
        printf("Калькулятор модуля\n1. Модуль числа\n2. Знак числа\n3. Округление вверх\n4. Округление вниз\n5. Выход\n");

        choice = get_int_num();

        if (choice < 1 || choice > 5)
        {
            printf("Неверный ввод. Введите число (1-5)\n");
            sleep(3);
            continue;
        }

        switch (choice)
        {
        case 1:
            clear_screen();
            printf("Введите число для вычисления модуля.\n");

            value = get_int_num();

            result = absolute_value(value);

            printf("Модуль числа: %d равен %d\n", value, result);

            printf("Введите ENTER для возврата в главное меню\n");

            getchar();

            break;

        case 2:
            clear_screen();
            printf("Введите число для проверки знака.\n");

            value = get_int_num();

            if (value < 0)
            {
                printf("Число %d отрицательное. Знак (-)\n", value);
            }
            else
            {
                printf("Число %d положительное знак (+)\n", value);
            }

            printf("Введите ENTER для возврата в главное меню\n");

            getchar();

            break;

        case 3:
            printf("Введите число для округления вверх.\n");

            d_value = get_double_num();

            d_result = ceil(d_value);

            printf("Число %.2f округленное верх равно %.0f\n", d_value, d_result);

            printf("Введите ENTER для возврата в главное меню\n");

            getchar();

            break;

        case 4:
            printf("Введите число для округления вниз.\n");

            d_value = get_double_num();

            d_result = floor(d_value);

            printf("Число %.2f округленное вниз равно %.0f\n", d_value, d_result);

            printf("Введите ENTER для возврата в главное меню\n");

            getchar();

            break;

        case 5:
            clear_screen();
            printf("До свидания!.\n");
            flag = 0;
            break;
        }
    }

    return 0;
}

void clear_screen()
{
    printf("\033[H\033[2J\033[3J");
}

int absolute_value(int value)
{
    if (value < 0) return value * -1;

    return value;
}

double ceil(double value)
{
    long long compare = (long long)value;

    if (value == compare) return value;

    return (value > 0.0) ? (double)(compare + 1) : (double)compare;
}

double floor(double value)
{
    long long compare = (long long)value;

    if (value == compare) return value;

    return (value > 0.0) ? (double)compare : (double)(compare - 1);
}

int get_int_num()
{
    int number = 0;

    while (1)
    {
        if (scanf("%d", &number) == 1)
        {
            getchar();
            return number;
        }

        while (getchar() != '\n');
        printf("Введите корректное число\n");
    }
}

double get_double_num()
{
    double number = 0;

    while (1)
    {
        if (scanf("%lf", &number) == 1)
        {
            getchar();
            return number;
        }

        while (getchar() != '\n');
        printf("Введите корректное число\n");
    }
}