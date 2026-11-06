#include <wchar.h>
#include <locale.h>

int main(void)
{
    // 6

    setlocale(LC_ALL, "");

    wchar_t w_ch = '0';
    unsigned int a_count, e_count;

    a_count = 0;
    e_count = 0;

    while ((w_ch = getwchar()) != L'#' && w_ch != WEOF)
    {
        switch (w_ch)
        {
        case L'a':
            a_count++;
            break;

        case L'e':
            e_count++;
            break;
        }
    }

    wprintf(L"count a: %u\ncount e: %u\n", a_count, e_count);

    return 0;
}
