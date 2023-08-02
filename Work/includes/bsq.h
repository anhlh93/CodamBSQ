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
# define BUFFER_SIZE 1024
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
    char    p;
    char    ;
    char    ;
    char    *map;
    int **tab;
}   t_par;

#endif
