/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/28 04:39:09 by lfantine          #+#    #+#             */
/*   Updated: 2022/08/28 14:44:54 by lfantine         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

void	ft_write(int len, char *str, char **tab, int w)
{
	int	i;
	int	j;

	i = 0;
	if (w == 0)
		i = -1;
	j = 0;
	while (i < len)
	{
		tab[w][j] = str[i];
		i++;
		j++;
	}
	tab[w][j] = '\0';
}

int	check_charset(char *cst, char *c, int j)
{
	int	i;

	i = 0;
	while (cst[i])
	{
		if (cst[i] == c[j] || c[j] == '\0')
			return (1);
		i++;
	}
	return (0);
}

int	ft_wcount(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (check_charset(charset, str, i) == 1)
		{
			count++;
			i++;
			while (check_charset(charset, str, i) == 1 && str[i])
				i++;
		}
		else
			i++;
	}
	if (check_charset(charset, str, i - 1) == 1)
		return (count);
	return (count + 1);
}

void	makew(char *str, char *charset, char **tab, int idx[3])
{
	while (idx[1] < ft_wcount(str, charset))
	{
		if (check_charset(charset, str, idx[0]) == 1)
		{
			tab[idx[1]] = malloc(sizeof(char) * (idx[0] - idx[2]));
			ft_write((idx[0] - idx[2] - 1), &str[idx[2] + 1], tab, idx[1]);
			idx[1]++;
			while (check_charset(charset, str, idx[0]) == 1)
				idx[2] = idx[0]++;
		}
		else if (str[idx[0]] == '\0')
		{
			tab[idx[1]] = malloc(sizeof(char) * (idx[0] - idx[2]));
			ft_write((idx[0] - idx[2] - 1), &str[idx[2] + 1], tab, idx[1]);
			idx[1]++;
		}
		else
			idx[0]++;
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**tab;
	int		index[3];

	index[0] = 0;
	index[1] = 0;
	index[2] = 0;
	if (str[0] == '\0')
		tab = malloc(sizeof(char *) * 1);
	else
	{
		while (check_charset(charset, str, index[0]) == 1 && str[0])
			str = (str + 1);
		if (str[0] == '\0')
			tab = malloc(sizeof(char *) * 1);
		else
		{
			tab = malloc((ft_wcount(str, charset) + 1) * sizeof(char *));
			makew(str, charset, tab, index);
		}
	}
	tab[index[1]] = 0;
	return (tab);
}
