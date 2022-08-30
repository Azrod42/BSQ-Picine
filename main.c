/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 23:00:39 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/30 20:15:18 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"function.h"

int	main(int argc, char **argv)
{
	(void)argc;
	char **map;
	
	s_max_sqr posmax;
	map = open_read_close(BUF_SIZE, argv);
	if (check_global(map) == 1)
	{
		write(1, "map error", 9);
		return (1);
	}
	/*if (check_empty == 1)
		return(0);*/
	posmax = ft_loop_sq(map);
	printf("%d = x, %d = y, %d = len\n", posmax.x, posmax.y, posmax.lgt);
	replace_tab(&posmax, map);
	print(map);
	return (0);
}
