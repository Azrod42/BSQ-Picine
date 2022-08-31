char **open_read_close(int bsize, char **argv, int i)
{
	int	fd;
	int	ret;
	char **map;
	char buf[bsize + 1];

	map = NULL;
	if (i == 0)
	{
		while (read(0, buf, bsize))
		{
			write(1, &buf, ft_strlen(buf));
			buf[0] = '\0';
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
