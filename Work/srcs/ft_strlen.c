/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: hale <marvin@codam.nl>                       +#+                     */
/*                                                   +#+                      */
/*   Created: 2023/07/15 15:57:03 by hale          #+#    #+#                 */
/*   Updated: 2023/07/19 14:06:14 by hale          ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		i++;
	}
	return (i);
}
