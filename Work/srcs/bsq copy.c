<<<<<<< HEAD
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
=======
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

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#include "bsq.h"

char	*read_file(char *file_name)
{
	char buffer[1024];
}

int	is_char_number(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

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

int	ft_strlen_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		i++;
	}
	return (i);
}

int max(int a, int b) {
    return (a > b) ? a : b;
}

int min(int a, int b) {
    return (a < b) ? a : b;
}



int	get_grid(char *buffer)
{
	int	i;
	int	j;
	int	dot;
	int num;
	int size;

	i = 0;
	j = 0;
	dot = 0;
	num = 0;
	size = 0;



	int	breaks = 0;

	char empty_;
	char obstacle_;
	char fill_;

	int param_len = 0;
	int testing = 0;
	int testing2 = 0;
	int limit_col = 0;

	while (buffer[i]) {
		if (buffer[i] == '\n') {
			// less than 4 chars in first line+
			if (i < 4) {
				return 0;
			}
			
			empty_ = buffer[i - 3];
			obstacle_ = buffer[i - 2];
			fill_ = buffer[i - 1];

			if (empty_ == obstacle_ || empty_ == fill_ || obstacle_ == fill_) {
				printf("mappie errorrie\n");
				return 0;
			}

			while (j < i - 3) {
				// not a number
				if (!is_char_number(buffer[j])) {
					return 0;
				}

				num = (num * 10) + buffer[j] - '0';
				j++;
			}

			param_len = i;

			break;
		}

		i++;
	}

	int col_limit = 0;
	int cols = 0;
	int rows = 0;

	while (buffer[i]) {
		if (buffer[i] == '\n') 
		{
			if (col_limit == 0) {
				col_limit = ft_strlen_nl(buffer + param_len + 1);
			}
			
			if (col_limit != ft_strlen_nl(buffer + i + 1)) {
				return (0);
			}

			cols += ft_strlen_nl(buffer + i + 1);
			rows++;
		}
		i++;
	}

	printf("cols: %d rows: %d\n", cols, rows);

    // Allocate memory for the grid
    int **asdasd = (int **)malloc((rows + 1) * sizeof(int *));
    for (int i = 0; i < rows + 1; i++) {
        asdasd[i] = (int *)malloc((col_limit + 1) * sizeof(int));
    }

    // Initialize the asdasd with 0s
    for (int i = 0; i < rows + 1; i++) {
        for (int j = 0; j < col_limit + 1; j++) {
            asdasd[i][j] = 0;
        }
    }

	int map_i = 0;
	char *map = (char*)malloc(cols * sizeof(char) + 1);

	i = param_len + 1;

	while (buffer[i]) {
		if (buffer[i] != '\n') {
			if (buffer[i] != empty_ && buffer[i] != obstacle_) {
				return 0;
			}

			map[map_i] = buffer[i];
			map_i++;
		}
		
		i++;
	}

	int largest = 0;

	map_i = 0;
    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= col_limit; j++) {
			if (map[map_i] == empty_) {
				asdasd[i][j] = 1 + min(asdasd[i - 1][j], min(asdasd[i][j - 1], asdasd[i - 1][j - 1]));

				if (largest < asdasd[i][j]) {
					largest = asdasd[i][j];

					printf("row: %d col: %d\n", i, j);
				}
			}
			
			map_i++;
        }
    }

	printf("largest: %d - %d\n", largest, largest * largest);

}

int	first_line(char *buffer)
{

}

void	bsq_main(char *buffer)
{
	t_params	*par;

	if (!(par = (t_params *)malloc(sizeof(t_params))))
		return ;

	if (!first_line(par, buffer))
		return ;
}

int main(int argc, char **argv) {
	if (argc != 2)
		return (0);

	int	fd = open(argv[1], O_RDONLY);

	if (fd == -1) {
		printf("failed to open file %s\n", argv[1]);
		return 0;
	}

	char buffer[1024 * 1024];
	// char buffer[2502 * 5502];
	size_t bytesRead;

	bytesRead = read(fd, buffer, sizeof(buffer));

	if (bytesRead == -1)  {
		printf("failed to read bytes in file %s\n", argv[1]);
		close(fd);
		return 0;
	}

	buffer[bytesRead] = '\0';

	bsq_main(buffer);
	close(fd);

	// if (!first_line())
	// 	return (0);

	// printf("read: %d\n", bytesRead);

	// printf("%d\n", get_grid(buffer));

	// int test = 0;
	// int dot = 0;

	// int i = 0;
	// while (buffer[i]) {
	// 	if (buffer[i] == '.') {
	// 		for (int j = 0; j < i; j++) {
	// 			test = (test * 10) + buffer[j] - '0';
	// 		}
	// 		if (dot != 0)
	// 			dot = i;
	// 	}

	// 	// printf("%d\n", buffer[dot]);

	// 	// if (buffer[i] == '\n') {
	// 	// 	// printf("%d\n", dot);
	// 	// 	// if (i - dot != 1) {
	// 	// 	// 	printf("failed to find empty or filled chars\n");

	// 	// 	// 	return 0;
	// 	// 	// }

	// 	// 	printf("??\n");

	// 	// 	// break;
	// 	// }
	// 	i++;
	// }

	// printf("test: %d\n", test);

	// close(fd);

	return 0;
}

// 
>>>>>>> 60b7ff2eaba2bb68079a9a1ccd900c6f159bc483
