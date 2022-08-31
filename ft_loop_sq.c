/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop_sq.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:09:28 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 19:12:08 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	set_max_sqr(s_max_sqr *sqr, int lgt, s_pos pos, char *c)
{
	sqr->x = pos.x;
	sqr->y = pos.y;
	sqr->lgt = lgt;
	sqr->start = c;
}

s_max_sqr	ft_loop_sq(char **map, s_pos *pos, int *lenfind, s_max_sqr *sqr)
{
	int			len;

	while ((map[pos->y] != '\0')
		&& (((ft_strlen_bis(map)) - (pos->y - 1)) >= sqr->lgt))
	{
		while (map[pos->y][pos->x] != '\0'
				&& ((ft_strlen(map[pos->y]) - (pos->x - 1) >= sqr->lgt)))
		{
			len = 0;
			while ((len < ft_strlen(map[pos->y]) - (pos->x - 1))
				&& (len < (ft_strlen_bis(map)) - (pos->y - 1)))
			{
				*lenfind = check_sqr(*pos, len, map);
				if (*lenfind == 1 && len > sqr->lgt)
					set_max_sqr(sqr, len, *pos, &map[pos->y][pos->x]);
				*lenfind = 0;
				len++;
			}
			pos->x++;
		}
		pos->x = 0;
		pos->y++;
	}
	return (*sqr);
}
