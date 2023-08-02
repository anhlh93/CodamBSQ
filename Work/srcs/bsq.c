/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bsq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yessers <yessers@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 13:41:37 by yessers           #+#    #+#             */
/*   Updated: 2023/08/02 18:51:52 by yessers          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "bsq.h"

int	first_line(t_par *par, char *buffer)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (buffer[i] && buffer[i] == '\n') 
		i++;
	if (i < 4)
			return (0);
	par->e = buffer[i - 3];
	par->o = buffer[i - 2];
	par->f = buffer[i - 1];
	if (par->e == par->o || par->e == par->f || par->o == par->f)
		return (ft_display_error());
	par->row = 0;
	while (++j < i - 3) 
	{
		if (!is_char_number(buffer[j]))
			return (ft_display_error());
		par->row = (par->row * 10) + buffer[j] - '0';
	}
	return (i);
}

int	col_limit(t_par *par, char *buffer) 
{
	int	i;
	int	length;
	
	par->col = 0;
	length = 0;
	i = first_line(par, buffer);
	while (buffer[i])
	{
		if (buffer[i] == '\n') 
		{
			if (par->col == 0) 
				par->col = ft_strlen_nl(buffer + first_line(par, buffer) + 1);
			if (par->col != ft_strlen_nl(buffer + i + 1)) 
				return (ft_display_error());
			length++;
		}
		i++;
	}
	return (length == par->row);
}

int	init_grid(t_par *par) 
{
	int i;
	int j;

	i = -1;
	par->tab = (int **)malloc((par->row + 1) * sizeof(int *));
	if (par->tab)
		return (0);
	while (++i < par->row + 1)
	{
        par->tab[i] = (int *)malloc((par->col + 1) * sizeof(int));
		if (par->tab[i])
			return (0);
		j = -1; 
		while (++j < par->col + 1)
            par->tab[i][j] = 0;
    }
	if (!(solve(par)))
		return (0);
	return (1);
}

void	new_max(t_par *par, int i, int j)
{
	par->max = par->tab[i][j];
	par->max_i = i;
	par->max_j = j;
}

int solve(t_par *par)
{
	int map_i;
	int	i;
	int	j;

	map_i = 0;
	i = 0;
	while (++i <= par->row)
	{
        j = 0;
		while (++j <= par->col)
		{
			if (par->map[map_i] == par->e) 
			{
				par->tab[i][j] = 1 + ft_min(par->tab[i - 1][j], par->tab[i][j - 1], par->tab[i - 1][j - 1]);
				if (par->max < par->tab[i][j])
					new_max(par, i, j);
			}
			else if (par->map[map_i] == par->o)
				par->tab[i][j] = 0;
			map_i++;
        }
	}
	return (1);
}
