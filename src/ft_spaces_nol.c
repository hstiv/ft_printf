#include "ft_printf.h"

void             ft_spaces_nol(t_pf_list *base)
{
    if (0 < base->width)
        while (base->width)
        {
            ft_putchar(32);
            base->len_str++;
            base->width--;
        }
    else if (0 < base->acc)
        while(base->acc)
        {
            ft_putchar(48);
            base->len_str++;
            base->acc--;
        }
}
