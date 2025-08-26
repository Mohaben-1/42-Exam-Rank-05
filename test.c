#include <unistd.h>
#include <stdlib.h>

void	print_board(char **board, int width, int height)
{
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			write(1, &board[i][j], 1);
		write(1, "\n", 1);
	}
}

int	count_neighbors(char **board, int width, int height, int x, int y)
{
	int	count = 0;

	for (int i = y - 1; i <= y + 1; i++)
	{
		for (int j = x - 1; j <= x + 1; j++)
		{
			if (i == y && j == x)
				continue ;
			if (i >= 0 && i < height && j >= 0 && j < width && board[i][j] == '0')
				count++;
		}
	}
	return (count);
}

void	game_of_life(char **board, int width, int height)
{
	char **new_board = malloc(height * sizeof(char *));
	if (!new_board)
		return ;
	for (int i = 0; i < height; i++)
	{
		new_board[i] = malloc(width + 1);
		if (!new_board[i])
		{
			// free already allocated rows to avoid leak
			for (int k = 0; k < i; k++)
				free(new_board[k]);
			free(new_board);
			return ;
		}
		for (int j = 0; j < width; j++)
		{
			int neighbors = count_neighbors(board, width, height, j, i);
			if (board[i][j] == '0')
			{
				if (neighbors == 2 || neighbors == 3)
					new_board[i][j] = '0';
				else
					new_board[i][j] = ' ';
			}
			else
			{
				if (neighbors == 3)
					new_board[i][j] = '0';
				else
					new_board[i][j] = ' ';
			}
		}
		new_board[i][width] = '\0';
	}
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
			board[i][j] = new_board[i][j];
		free(new_board[i]);
	}
	free(new_board);
}

void	free_board(char **board, int size)
{
	for (int i = 0; i < size; i++)
		free(board[i]);
	free(board);
}

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);

	int		width = atoi(av[1]);
	int		height = atoi(av[2]);
	int		iterations = atoi(av[3]);
	char	**board = malloc(height * sizeof(char *));
	if (!board)
		return (1);

	for (int i = 0; i < height; i++)
	{
		board[i] = malloc(width + 1);
		if (!board[i])
		{
			free_board(board, i);
			return (1);
		}
		for (int j = 0; j < width; j++)
			board[i][j] = ' ';
		board[i][width] = '\0';
	}

	int		pen_down = 0;
	int		x = 0;
	int		y = 0;
	char	cmd;

	while (read(0, &cmd, 1) > 0)
	{
		if (cmd == 'x')
		{
			pen_down = !pen_down;
			if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
				board[y][x] = '0';
		}
		else if (cmd == 'w' && y > 0)
			y--;
		else if (cmd == 's' && y < height - 1)
			y++;
		else if (cmd == 'a' && x > 0)
			x--;
		else if (cmd == 'd' && x < width - 1)
			x++;

		if (pen_down && x >= 0 && x < width && y >= 0 && y < height)
			board[y][x] = '0';
	}

	for (int i = 0; i < iterations; i++)
		game_of_life(board, width, height);

	print_board(board, width, height);
	free_board(board, height);
	return (0);
}
