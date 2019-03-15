#include "ft_printf.h"

static void     reverse_string(char *str, int len)
{
    int         i;
    int         j;
    int         t;

    i = 0;
    j = i - 1;
    while (i < j)
    {
        t = str[i];
        str[i] = str[j];
        str[j] = t;
        i++;
        j--;
    }
}

static char     *fpart_to_print(float x, char *str, int d)
{
    int         i;
    int         l;
    char        *s;

    l = 0;
    i = 0;
    while (x)
    {
        x = x * 10;
        i += (int)x;
        i *= 10;
        x = (int)x % 10;
    }
    while (d--)
        i = i * 10;
    while (i)
    {
        s[l++] = (i % 10) + '0';
        i = i / 10;
    }
    reverse_string(s, l);
    return (ft_strcat(str, s));
}

static int      ipart_to_print(int x, int d, char *str)
{
    int         i;

    i = 0;
    while(x)
    {
        str[i] = (x % 10) + '0';
        i++;
        x = x / 10;
    }
    reverse_string(str, i);
    return (i);    
}

void            ft_ftoa(float n, int afterpoint)
{
    int         ipart;
    float       fpart;
    char        *str;
    int         i;

    ipart = (int)n;
    fpart = n - (float)ipart;
    i = ipart_to_print(ipart, 0, str);
    if (fpart > 0)
    {
        str[i] = '.';
        str = fpart_to_print(fpart, str, afterpoint);
    }
    ft_putstr(str);
}