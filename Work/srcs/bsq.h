/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   bsq.h                                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: hale <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/08/02 10:34:23 by hale          #+#    #+#                 */
/*   Updated: 2023/08/02 10:36:18 by hale          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef BSQ_H
# define BSQ_H
# define BUF_SIZE 1024
# include <unistd.h>//write
# include <stdlib.h>//malloc; free
# include <fcntl.h>//open; close; read

typedef struct s_par
{
    int row;
    int col;
    int max;
    int max_i;
    int max_j;
    char    e;
    char    o;
    char    f;
    char    *map;
    int **tab;
}   t_par;

int	first_line(t_par *par, char *buffer);
int	col_limit(t_par *par, char *buffer);
int	init_grid(t_par *par);
void	new_max(t_par *par, int i, int j);
int solve(t_par *par);
char    *ft_read_map(char *file);
int start_bsq(char *filename);
int    ft_display_input(void);
void    print_bsq(t_par *par);
int	is_char_number(char c);
int	ft_strlen_nl(char *str);
int		ft_min(int a, int b, int c);
char	*ft_strjoin(char *str1, char *str2);
void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_err(char *str);
int		ft_display_error(void);
int	ft_strlen(char *str);






#endif
