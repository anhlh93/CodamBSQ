#include "bsq.h"

char    *ft_read_map(char *file)
{
    int bytesRead;
    char	buf[BUF_SIZE + 1];
	char	*str;
	int	fd;
    
    fd = open(file, O_RDONLY);
	if (fd == -1) 
        return (NULL);
    if (!(str = (char *)malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
    bytesRead = read(fd, buf, BUF_SIZE);
    while (bytesRead >= 1)
    {
        buf[bytesRead] = '\0';
		str = ft_strjoin(str, buf);
        bytesRead = read(fd, buf, BUF_SIZE);
    }
    bytesRead = close(fd);
    if (bytesRead == -1)
        return (NULL);
    return (str);
}

int start_bsq(char *filename)
{
    char    *map;
    t_par   *par;

    if (!(map = ft_read_map(filename)))
        return (ft_display_error());
    if (!(par = (t_par *)(malloc(sizeof(t_par)))) || !col_limit(par, map))
        return (ft_display_error());
    else
    {
        par->max = 0;
        par->max_i = 0;
        par->max_j = 0;
        if (!init_grid(par))
            return (0);
        print_bsq(par);
    }
    return (1);
}

int    ft_display_input(void)
{
    char    buf[BUF_SIZE + 1];
    char    *map;
    int r;
    t_par   *par;

    if (!(map = (char *)malloc(sizeof(char))))
        return (0);
    map[0] = '\0';
    while ((r = read(0, buf, BUF_SIZE)))
    {
        buf[r] = '\0';
        map = ft_strjoin(map, buf);
    }
    if (!(par = (t_par *)(malloc(sizeof(t_par)))) || !col_limit(par, map))
        return (ft_display_error());
    par->max = 0;
    par->max_i = 0;
    par->max_j = 0;
    if (!init_grid(par))
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
