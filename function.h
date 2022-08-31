/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 08:59:59 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 18:09:12 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef FUNCTION_H
# define FUNCTION_H

typedef struct s_pos
{
	int x;
	int y;
}s_pos;

typedef struct s_max_sqr
{
	int x;
	int y;
	int lgt;
	char *start;
}s_max_sqr;

# include<sys/types.h>
# include<sys/stat.h>
# include<fcntl.h>
# include<unistd.h>
# include<stdio.h>
# include<stdlib.h>
# include"ft_strlen.c"
# include"ft_split.c"
# include"ft_atoi.c"
# include"open_read.c"
# include"ft_strlen_bis.c"
# include"check_map.c"
# include"check_tab.c"
# include"ft_loop_sq.c"
# include"ft_replace.c"
# include"print.c"

# define BUF_SIZE 200000


char		**ft_split(char *str, char *charset);
int			ft_strlen(char *str);
char		**open_read_close(int bsize, char **argv, int i);
int     	check_global(char **map);
int			check_sqr(s_pos pos, int len, char ** map);
s_max_sqr	ft_loop_sqr(char **map);
int			replace_tab(s_max_sqr *pos, char **map);
void		print(char** map);

#endif
