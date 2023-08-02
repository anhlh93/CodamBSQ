#include "bsq.h"

int start_bsq(char *filename)
{
    char    *map;
    struct t_par   *par;

    if (!(map = ft_read_map(filename)))
        return (ft_error_message());
    if (!(par = (t_par *)malloc(sizeof(t_par))) || !is_valid(par, map))
        return (ft_error_message());
    else
    {
        par->max = 0;
        par->max_i = 0;
        par->max_j = 0;
        if (!parse_map(par))
            return (0);
        display_bsq(par);
    }
    return (1);
}

int    ft_display_input(void)
{
    char    buf[BUFFER_SIZE + 1];
    char    *map;
    int r;
    struct t_par   *par;

    if (!(map = (char *)malloc(sizeof(char))))
        return (0);
    map[0] = '/0';
    while ((r = read(0, buf, BUFFER_SIZE)))
    {
        buf[r] = '\0';
        map = ft_strjoin(map, buf);
    }
    if (!(par = (t_par *)malloc(sizeof(t_par))) || !is_valid(par, map))
        return (ft_error_message());
    par->max = 0;
    par->max_i = 0;
    par->max_j = 0;
    if (!parse_map(par))
        return (0);
    print_bsq(par);
    return (1);
}

int main(int ac, char **av)
{
    int i;

    i = 1;
    if (ac == 1)
        ft_display_input();
    else
        while (i < ac)
        {
            start_bsq(av[i++]);
            if (i != ac)
                ft_putstr("\n");
        }
    return (0);
}
