#include "bsq.h"

void    print_bsq(t_par *par)
{
    int i;
    int b;

    i = par->max_i - par->max;
    while (i < par->max_i)
    {
        j = par->max_j - par->max;
        while (j < par->max_j)
        {
            par->map[i * (par->col + 1) + j] = par->x;
            j++;
        }
        i++;
    }
    ft_putstr(par->map);
}