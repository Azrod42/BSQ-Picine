/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tsorabel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 18:26:02 by tsorabel          #+#    #+#             */
/*   Updated: 2022/08/31 20:10:26 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	print(char **map)
{
	int	i;

	i = 1;
	while (map[i])
	{
		write(1, map[i], ft_strlen(map[i]));
		write(1, "\n", 1);
		i++;
	}
}
