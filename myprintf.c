#include <stdio.h>
#include <stdarg.h>
void myprintf(const char *format, ...);
void printint(int n);
void printdouble(double x);
void printstring(const char*);
int main(void)
{
    myprintf("%d %d %f %c %s\n", 123, 456, 432.14156789, 'M', "abcdefg");
    return 0;
}

void myprintf(const char *format, ...)
{
    va_list va;
    va_start(va, format);
    while (*format) {
        if (*format != '%') {
            putchar(*format);
            format++;
        }
        else {
            format++;
            switch (*format) {
                case 'd':
                    printint(va_arg(va, int));
                    break;
                case 'f':
                    printdouble(va_arg(va, double));
                    break;
                case 'c':
                    putchar(va_arg(va, int));
                    break;
                case 's':
                    printstring(va_arg(va, char*));
                    break;
            }
            format++;
        }
    }
}

void printint(int n)
{
    char digits[20];
    int p = 0;
    while (n) {
        digits[p++] = n % 10 + '0';
        n /= 10;
    }
    while (p > 0) {
        putchar(digits[--p]);
    }
}

void printdouble(double x)
{
    int intpart = (int) x, digit;
    double fractionpart = x - intpart;
    printint(intpart);
    putchar('.');
    int time;
    for (time = 0; time < 6; time++) {
        fractionpart *= 10;
        digit = (int)fractionpart;
        putchar(digit + '0');
        fractionpart -= (int)fractionpart;
    }
}

void printstring(const char* str)
{
    while (*str) {
        putchar(*str);
        str++;
    }
}
