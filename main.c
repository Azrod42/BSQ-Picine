/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:00:39 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 13:24:44 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"function.h"

void	make(char **map, int i, s_max_sqr posmax, char **argv)
{
	map = open_read_close(BUF_SIZE, argv, i);
	if (check_global(map) == 1)
	{
		write(1, "map error\n", 10);
		return ;
	}
	posmax = ft_loop_sq(map);
	printf("%d = x, %d = y, %d = len\n", posmax.x, posmax.y, posmax.lgt);
	replace_tab(&posmax, map);
	print(map);
	free(map);
}

int	main(int argc, char **argv)
{
	char **map;
	int	i;
	s_max_sqr posmax;
	
	map = NULL;
	posmax.lgt = 0;
	if (argc < 2)
	{
		make(map, 0, posmax, argv);
	}
	else
	{
		i = 1;
		while (argv[i])
		{
			make(map, i, posmax, argv);
			i++;
			if (argv[i])
			{
				write(1, "\n", 1);
			}
		}
	}
	return (0);
}
