int	ft_board(int size)
{
	char	*board;
	int		len;
	int		i;

	i = 0;
	len = (size + 1) * size + 1;
	board = malloc(sizeof(char) * (unsigned long)len);
	if (!board)
		return (0);
	while (i < (len - 2))
	{
		if (i == size)
			board[i] = '\n';
		else if (i > size && (i + 1) % (size + 1) == 0)
			board[i] = '\n';
		else
			board[i] = '.';
		i++;
	}
	board[i] = '\0';
	printf("%s\n", board);
	return (1);
}