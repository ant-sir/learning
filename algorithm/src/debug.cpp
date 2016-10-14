#include <stdarg.h>
#include <stdio.h>

#define DEBUG(ftm, args...)                                                    \
    debug("%s,%d,%s" ftm, __FILE__, __LINE__, __FUNCTION__, ##args)

typedef struct
{
    int type;
    int ipaddress[4];
} IPADDRESS;

typedef IPADDRESS GROUP, SOURCE;

void debug(const char *fmt, const char *file_name, int line,
           const char *func_name, ...)
{
    char *str;
    char buf[1024];
    int qualifier;
    va_list args;

    va_start(args, fmt);

    for (str = buf; *fmt; fmt++)
    {
        if (*fmt != '%')
        {
            *str++ = *fmt;
            continue;
        }
    repeat:
        fmt++;
        switch (*fmt)
        {
        case '-':
        case '+':
        case ' ':
        case '#':
        case '0':
			*str++ = '%';
			*str++ = *fmt;
            goto repeat;
        }

        if (*fmt == '*')
        {
            fmt++;
            va_arg(args, int);
        }

        if (*fmt == '.')
        {
            ++fmt;
            if (*fmt == '*')
            {
                ++fmt;
                va_arg(args, int);
            }
        }

        qualifier = -1;
        if (*fmt == 'h' || *fmt == 'l' || *fmt == 'L')
        {
            qualifier = *fmt;
            fmt++;
        }

        switch (*fmt)
        {
        case 'c':
            va_arg(args, int);
            continue;
        case 's':
            va_arg(args, char *);
            continue;
        case 'p':
            va_arg(args, void *);
            continue;
        case 'n':
            if (qualifier == 'l')
                va_arg(args, long *);
            else
                va_arg(args, int *);
            continue;
        case 'A':
        case 'a':
            if (qualifier == 'l')
                va_arg(args, unsigned char *);
            else
                va_arg(args, unsigned char *);
            continue;
        case 'o':
        case 'X':
        case 'x':
        case 'd':
        case 'i':
        case 'u':
            break;
        case 'E':
        case 'G':
        case 'e':
        case 'f':
        case 'g':
            va_arg(args, double);
            continue;
        default:
            if (*fmt != '%')
                ;
            /* custom type. */

            if (*fmt)
                *str++ = *fmt;
            else
                --fmt;
            continue;
        }

        if (qualifier == 'l')
            va_arg(args, unsigned long);
        else if (qualifier == 'h')
            va_arg(args, unsigned short);
        else
            va_arg(args, unsigned int);
    }
    *str = '\0';
    return str - buf;
}

int main() { return 0; }
