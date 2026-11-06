#include <stdio.h>
#include <unistd.h>

int absolute_value(int value);
double my_ceil(double value);
double my_floor(double value);
int get_int_num();
double get_double_num();
void enter_to_main_menu();
void clear_screen();

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

            enter_to_main_menu();

            break;

        case 2:
            clear_screen();

            printf("Введите число для проверки знака.\n");

            value = get_int_num();

            if (value < 0)
            {
                printf("Число %d отрицательное. Знак (-)\n", value);
            }
            else if (value == 0)
            {
                printf("Число %d не имеет знака\n", value);
            }
            else
            {
                printf("Число %d положительное знак (+)\n", value);
            }

            enter_to_main_menu();

            break;

        case 3:
            clear_screen();

            printf("Введите число для округления вверх.\n");

            d_value = get_double_num();

            d_result = my_ceil(d_value);

            printf("Число %.2f округленное верх равно %.0f\n", d_value, d_result);

            enter_to_main_menu();

            break;

        case 4:
            clear_screen();

            printf("Введите число для округления вниз.\n");

            d_value = get_double_num();

            d_result = my_floor(d_value);

            printf("Число %.2f округленное вниз равно %.0f\n", d_value, d_result);

            enter_to_main_menu();

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


int absolute_value(int value)
{
    if (value < 0) return value * -1;

    return value;
}

double my_ceil(double value)
{
    long long compare = value;

    if (value == compare) return value;

    return (value > 0.0) ? (compare + 1) : compare;
}

double my_floor(double value)
{
    long long compare = value;

    if (value == compare) return value;

    return (value > 0.0) ? compare : (compare - 1);
}

int get_int_num()
{
    int number = 0;

    while (1)
    {
        if (scanf("%d", &number) == 1)
        {
            while (getchar() != '\n');
            return number;
        }

        while (getchar() != '\n');
        printf("Введите корректное число\n");
    }
}

double get_double_num()
{
    double number = 0.0;

    while (1)
    {
        if (scanf("%lf", &number) == 1)
        {
            while (getchar() != '\n');
            return number;
        }

        while (getchar() != '\n');
        printf("Введите корректное число\n");
    }
}

void enter_to_main_menu()
{
    printf("Введите ENTER для возврата в главное меню\n");

    while (getchar() != '\n');
}

void clear_screen()
{
    printf("\033[H\033[2J\033[3J");
}
