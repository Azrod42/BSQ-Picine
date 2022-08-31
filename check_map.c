/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 09:34:34 by lfantine          #+#    #+#             */
/*   Updated: 2022/08/31 10:14:08 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_atoi.c"
#include "ft_strlen_bis.c"
int	check_exist(char **map);
int	check_line(char **map);
int	check_char(char **map, int idxl, int idxc);
int	check_valid(char **map);
int	ft_atoi(char *str);
int	ft_strlen_bis(char **str);

int check_global(char **map)
{
	int	error;

	error = 0;
	if (check_exist(map) == 1)
		return (1);
	else if (check_line(map) == 1)
		return (1);
	else if (check_valid(map) == 1)
		return (1);
	else if (check_char(map, 0, 1) == 1)
		return (1);
	return (0);
}

int	check_exist(char **map)
{
	if(ft_strlen_bis(map) > 1)
	{
		if (map[1][0] != '\0' && (map[1][0] >= 32 && map[1][0] <= 126))
			return (0);
	}
	return (1);
}

int	check_line(char **map)
{
	int	i;

	i = 2;
	if (ft_strlen_bis(map) - 1 == ft_atoi(map[0]))
	{
		while (map[i])
		{
			if (ft_strlen(map[i]) != ft_strlen(map[1]))
				return (1);
			i++;
		}
		return (0);
	}
	return (1);
}

int	check_valid(char **map)
{
	int		i;
	char	ept;
	char	obst;
	char	full;

	i = 0;
	if (ft_strlen(map[0]) < 4)
		return (1);
	ept = map[0][ft_strlen(map[0]) - 3];
	obst  = map[0][ft_strlen(map[0]) - 2];
	full = map[0][ft_strlen(map[0]) - 1];
	if (ept == obst || ept == full || obst == full)
		return (1);
	return (0);
}

int	check_char(char **map, int idxl, int idxc)
{
	char	ept;
	char	obst;
	char	full;

	if (ft_strlen(map[0]) < 4)
		return (1);
	ept = map[0][ft_strlen(map[0]) - 3];
	obst  = map[0][ft_strlen(map[0]) - 2];
	full = map[0][ft_strlen(map[0]) - 1];
	idxl = 0;
	while (map[idxc])
	{
		while (map[idxc][idxl])
		{
			if ((map[idxc][idxl] != ept) 
					&& (map[idxc][idxl] != obst)
					&& (map[idxc][idxl] != full))
				return (1);
			idxl++;
		}
		idxl = 0;
		idxc++;
	}
	return (0);
}
