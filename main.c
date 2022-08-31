/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:00:39 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 19:06:26 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"function.h"

void ft_free(char **map)
{
	int i;
	
	i = 0;
	while (i < ft_strlen_bis(map) + 1)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

void	make(char **map, int i, s_max_sqr posmax, char **argv)
{
	s_pos		pos;
	s_max_sqr	sqr;
	int 		lenfind;

	pos.x = 0;
	pos.y = 1;
	sqr.lgt = 0;
	lenfind = 0;
	map = open_read_close(BUF_SIZE, argv, i);
	if (map == 0)
	{
		write(1, "map error\n", 10);
		return ;
	}
	if (check_global(map) == 1)
	{
		write(1, "map error\n", 10);
		ft_free(map);
		return ;
	}
	posmax = ft_loop_sq(map, &pos, &lenfind, &sqr);
	replace_tab(&posmax, map);
	print(map);
	ft_free(map);
}

int	main(int argc, char **argv)
{
	char **map;
	int	i;
	s_max_sqr posmax;
	
	map = NULL;
	posmax.lgt = 0;
	if (argc < 2)
		make(map, 0, posmax, argv);
	else
	{
		i = 1;
		while (argv[i])
		{
			make(map, i, posmax, argv);
			i++;
			if (argv[i])
				write(1, "\n", 1);
		}
	}
	//system( "leaks bsq");
	return (0);
}
