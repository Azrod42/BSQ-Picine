/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_tab.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 14:03:39 by lfantine          #+#    #+#             */
/*   Updated: 2022/08/31 20:28:05 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	check_sqr(t_pos pos, int len, char **map)
{
	int		ic;
	int		il;
	char	obst;

	ic = 0;
	il = 0;
	obst = map[0][ft_strlen(map[0]) - 2];
	while (ic < len)
	{
		while (il < len)
		{
			if (map[pos.y + ic][pos.x + il] == obst)
				return (0);
			il++;
		}
		il = 0;
		ic++;
	}
	return (1);
}
