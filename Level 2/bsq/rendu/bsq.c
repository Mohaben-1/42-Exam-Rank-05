#include <stdio.h>
#include <stdlib.h>

typedef struct s_bsq
{
	int		rows;
	int		cols;
	char	empty_ch;
	char	obst_ch;
	char	full_ch;
	char	**map;
}	t_bsq;

size_t	my_strlen(const char *s)
{
	size_t	n = 0;

	while (s && s[n])
		n++;
	return (n);
}

int	is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

void	free_map(t_bsq *b)
{
	if (!b || !b->map)
		return ;
	for (int i = 0; i < b->rows; i++)
		free(b->map[i]);
	free(b->map);
	b->map = NULL;
}

int	parse_first_line(char *line, t_bsq *b)
{
	if (!line || !b)
		return (0);

	size_t	len = my_strlen(line);

	if (len < 5)
		return (0);     
	if (line[len - 1] != '\n')
		return (0); 
	line[len - 1] = '\0';
	len--;

	if (len < 4)
		return (0);
	b->full_ch  = line[len - 1];
	b->obst_ch  = line[len - 2];
	b->empty_ch = line[len - 3];

	if (b->empty_ch == b->obst_ch || b->empty_ch == b->full_ch || b->obst_ch == b->full_ch)
		return (0);
	
	line[len - 3] = '\0';
	if (line[0] == '\0')
		return (0);

	int	rows = 0;

	for (char *p = line; *p; ++p)
	{
		if (!is_digit(*p))
			return (0);
		if (rows > 100000000)
			return (0);
		rows = rows * 10 + (*p - '0');
	}
	if (rows <= 0)
		return (0);
	b->rows = rows;
	return (1);
}

int	read_map(FILE *f, t_bsq *b)
{
	if (!f || !b)
		return (0);

	b->map = calloc((size_t)b->rows, sizeof(char *));

	if (!b->map)
		return (0);

	char	*line = NULL;
	size_t	cap = 0;
	int		cols = -1;

	for (int i = 0; i < b->rows; i++)
	{
		ssize_t	got = getline(&line, &cap, f);

		if (got < 0)
			return(free(line), 0);
		if (got == 0 || line[got - 1] != '\n')
			return(free(line), 0);
		line[got - 1] = '\0';
		got--;
		if (cols < 0)
			cols = (int)got;
		else if (cols != (int)got)
			return(free(line), 0);
		for (int j = 0; j < cols; j++)
		{
			char	c = line[j];

			if (!(c == b->empty_ch || c == b->obst_ch))
				return(free(line), 0);
		}
		b->map[i] = malloc((size_t)cols + 1);
		if (!b->map[i])
			return(free(line), 0);
		for (int j = 0; j < cols; j++)
			b->map[i][j] = line[j];
		b->map[i][cols] = '\0';
	}
	free(line);
	b->cols = cols;
	{
		char	*extra = NULL;
		size_t	extra_cap = 0;
		ssize_t	got = getline(&extra, &extra_cap, f);
		if (extra)
			free(extra);
		if (got != -1)
			return (0);
	}
	return (1);
}

int	min3(int a, int b, int c)
{
	int	m;

	if (a < b)
		m = a;
	else
		m = b;
	if (m < c)
		return (m);
	else
		return (c);
}


void	solve_bsq(t_bsq *b)
{
	int	R = b->rows;
	int	C = b->cols;
	int	*dp = calloc((size_t)R * (size_t)C, sizeof(int));

	if (!dp)
		return ;

	int	best_size = 0;
	int	best_i = 0;
	int	best_j = 0;

	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			int idx = i * C + j;
			if (b->map[i][j] == b->obst_ch)
				dp[idx] = 0;
			else
			{
				if (i == 0 || j == 0)
					dp[idx] = 1;
				else
				{
					int	up = dp[(i - 1) * C + j];
					int	left = dp[i * C + (j - 1)];
					int	diag = dp[(i - 1) * C + (j - 1)];

					dp[idx] = 1 + min3(up, left, diag);
				}
				if (dp[idx] > best_size)
				{
					best_size = dp[idx];
					best_i = i; best_j = j;
				}
				else if (dp[idx] == best_size && best_size > 0)
				{
					int	top_cur  = i - dp[idx] + 1;
					int	left_cur = j - dp[idx] + 1;
					int	top_best  = best_i - best_size + 1;
					int	left_best = best_j - best_size + 1;

					if (top_cur < top_best || (top_cur == top_best && left_cur < left_best))
						best_i = i; best_j = j;
				}
			}
		}
	}
	if (best_size > 0)
	{
		int	top  = best_i - best_size + 1;
		int	left = best_j - best_size + 1;

		for (int i = top; i <= best_i; i++)
			for (int j = left; j <= best_j; j++)
				b->map[i][j] = b->full_ch;
	}
	free(dp);
}

int	run_bsq(FILE *in)
{
	t_bsq	b = {0};
	char	*line = NULL;
	size_t	cap = 0;
	ssize_t	got = getline(&line, &cap, in);

	if (got < 0)
		return(free(line), 0);
	if (!parse_first_line(line, &b))
		return(free(line), 0);
	free(line);
	if (!read_map(in, &b))
		return(free(&b), 0);
	solve_bsq(&b);
	for (int i = 0; i < b.rows; i++)
	{
		fputs(b.map[i], stdout);
		fputs("\n", stdout);
	}
	free_map(&b);
	return (1);
}

int	main(int ac, char **av)
{
	if (ac == 1)
		run_bsq(stdin);
	else if (ac == 2)
	{
		FILE *f = fopen(av[1], "r");
		if (!f)
			return (1);
		run_bsq(f);
		fclose(f);
	}
	else
		return (1);
	return (0);
}
