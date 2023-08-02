/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putstr.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hale <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/12 11:23:03 by hale          #+#    #+#                 */
/*   Updated: 2023/07/14 08:45:27 by hale          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>//write

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (*(str + i) != '\0')
	{
		ft_putchar(*(str + i));
		i++;
	}
}

