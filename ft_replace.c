/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_replace.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 17:48:33 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 13:23:04 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int replace_tab(s_max_sqr *pos, char **map)
{
	int i;
	int j;
	int k;
	int lgt;

	i = pos->y;
	k = 0;
	j = 0;
	lgt = 1;
	while (lgt < atoi(map[0]))
	{	
		while (k <= lgt && k < pos->lgt)
		{
			while (j <= lgt && j < pos->lgt)
			{
				map[i+k][pos->x + j] = map[0][ft_strlen(map[0]) - 1];
				j++;
			}
			j = 0;
			k++;
		}
		k = 0;
		lgt++;
	}
	return (0);
}
