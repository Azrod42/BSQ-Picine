/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfantine <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/31 19:14:39 by lfantine          #+#    #+#             */
/*   Updated: 2022/08/31 20:35:05 by tsorabel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	**line_user_tab(char **map)
{
	int		j;
	int		i;
	char	buf[BUF_SIZE];

	j = 1;
	i = 0;
	while (j <= ft_atoi(map[0]))
	{
		i = 0;
		read(0, buf, BUF_SIZE);
		while (buf[i] && buf[i] != '\n')
			i++;
		map[j] = malloc(sizeof(char) * (i + 1));
		map[j][0] = '\0';
		i = 0;
		while (buf[i] && buf[i] != '\n')
		{
			map[j][i] = buf[i];
			i++;
		}
		map[j][i] = '\0';
		j++;
	}
	return (map);
}

char	**user_tab(char **map, int j)
{
	char	firstline[10];
	char	buf[BUF_SIZE];

	read(0, buf, BUF_SIZE);
	while (buf[j] && buf[j] != '\n')
	{
		firstline[j] = buf[j];
		j++;
	}
	firstline[j] = '\0';
	j = 0;
	if (ft_atoi(firstline) == 0)
		return (0);
	map = malloc(sizeof(char *) * (ft_atoi(firstline) + 3));
	map[0] = malloc(sizeof(char) * ft_strlen(firstline) + 1);
	map[0][0] = '\0';
	while (firstline[j])
	{
		map[0][j] = firstline[j];
		j++;
	}
	map[0][j] = '\0';
	map = line_user_tab(map);
	return (map);
}

char	**open_read_close(char **argv, int i)
{
	int		fd;
	int		ret;
	char	**map;
	char	buf[BUF_SIZE];

	map = NULL;
	if (i == 0)
		map = user_tab(map, 0);
	else
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
			return (0);
		ret = read(fd, buf, BUF_SIZE);
		if (ret == -1)
			return (0);
		buf[ret] = '\0';
		map = ft_split(buf, "\n");
		if (close(fd) == -1)
			return (0);
	}
	return (map);
}	
