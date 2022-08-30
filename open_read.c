char **open_read_close(int bsize, char **argv)
{
	int	fd;
	int	ret;
	char **map;
	char buf[bsize + 1];
	int	i;

	i = 0;
	map = NULL;
	// A FAIRE ======= if (ft_strlen_bis(argv) < 2)
	// read(0, &buf, 1)
	fd = open(argv[1], O_RDONLY);
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
	return (map);
}	