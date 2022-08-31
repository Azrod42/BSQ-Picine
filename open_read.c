char **open_read_close(int bsize, char **argv, int i)
{
	int	fd;
	int	ret;
	char **map;
	char buf[bsize + 1];
	int	j;
	char	firstline[10];

	map = NULL;
	if (i == 0)
	{
		j = 0;
		read(0, buf, bsize);
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
		if (!map)
			return (0);
		map[0] = malloc(sizeof(char) * ft_strlen(firstline) + 1);
		if (!map[0])
			return (0);
		map[0][0] = '\0';
		while (firstline[j])
		{
			map[0][j] = firstline[j];
			j++;
		}
		map[0][j] = '\0';
		j = 1;
		while (j <= ft_atoi(map[0]))
		{
			i = 0;
			read(0, buf, bsize);
			while (buf[i] && buf[i] != '\n')
				i++;
			map[j] = malloc(sizeof(char) * (i + 1));
			if (!map[j])
				return (0);
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
	}
	else
	{
		fd = open(argv[i], O_RDONLY);
		if (fd == -1)
		{
			write(1, "open failed\n", 12);
			return (0);
		}
		ret = read(fd, buf, bsize);
		if (ret == -1)
		{
			write(1, "read() failed\n", 14);
			return (0);
		}
		buf[ret] = '\0';
		map = ft_split(buf, "\n");
		if (close(fd) == -1)
		{
			write(1, "close failed\n", 13);
			return (0);
		}
	}
	return (map);
}	
