#include "count_island.h"

#define CHUNK 4096

char *read_file(int fd, int *out_len)
{
	char	*data;
	char	*new_data;
	char	chunk[CHUNK];
	int		len;
	int		n;
	int		i;

	data = NULL;
	len = 0;
	while ((n = read(fd, chunk, CHUNK)) > 0)
	{
		new_data = (char *)malloc(len + n);
		if (!new_data)
		{
			free(data);
			return (NULL);
		}
		i = 0;
		while (i < len)
		{
			new_data[i] = data[i];
			i++;
		}
		i = 0;
		while (i < n)
		{
			new_data[len + i] = chunk[i];
			i++;
		}
		free(data);
		data = new_data;
		len += n;
	}
	if (n < 0)
	{
		free(data);
		return (NULL);
	}
	*out_len = len;
	return (data);
}

int count_lines(const char *data, int len)
{
	int count;
	int i;

	count = 0;
	i = 0;
	while (i < len)
	{
		if (data[i] == '\n')
			count++;
		i++;
	}
	return (count);
}

int parse_grid(char *data, int len, int width, int height, char ***out_grid)
{
	char	**grid;
	int		i;
	int		j;
	int		k;
	int		pos;

	grid = (char **)malloc(height * sizeof(char *));
	if (!grid)
		return (-1);
	pos = 0;
	i = 0;
	while (i < height)
	{
		grid[i] = (char *)malloc(width * sizeof(char));
		if (!grid[i])
		{
			k = 0;
			while (k < i)
				free(grid[k++]);
			free(grid);
			return (-1);
		}
		j = 0;
		while (j < width)
		{
			if (pos >= len || (data[pos] != '.' && data[pos] != 'X'))
			{
				k = 0;
				while (k <= i)
					free(grid[k++]);
				free(grid);
				return (-1);
			}
			grid[i][j] = data[pos];
			pos++;
			j++;
		}
		if (pos >= len || data[pos] != '\n')
		{
			k = 0;
			while (k <= i)
				free(grid[k++]);
			free(grid);
			return (-1);
		}
		pos++;
		i++;
	}
	if (pos != len)
	{
		k = 0;
		while (k < height)
			free(grid[k++]);
		free(grid);
		return (-1);
	}
	*out_grid = grid;
	return (0);
}

void fill_island(char **grid, int i, int j, int h, int w, char label)
{
	if (i < 0 || i >= h || j < 0 || j >= w)
		return ;
	if (grid[i][j] != 'X')
		return ;
	grid[i][j] = label;
	fill_island(grid, i - 1, j, h, w, label);
	fill_island(grid, i + 1, j, h, w, label);
	fill_island(grid, i, j - 1, h, w, label);
	fill_island(grid, i, j + 1, h, w, label);
}

void count_islands(char **grid, int h, int w)
{
	char	label;
	int		i;
	int		j;

	label = '0';
	i = 0;
	while (i < h)
	{
		j = 0;
		while (j < w)
		{
			if (grid[i][j] == 'X')
			{
				fill_island(grid, i, j, h, w, label);
				label++;
			}
			j++;
		}
		i++;
	}
}

void print_grid(char **grid, int h, int w)
{
	int i;

	i = 0;
	while (i < h)
	{
		write(STDOUT_FILENO, grid[i], w);
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}

void free_grid(char **grid, int h)
{
	int i;

	if (!grid)
		return ;
	i = 0;
	while (i < h)
		free(grid[i++]);
	free(grid);
}

int main(int argc, char **argv)
{
	int		fd;
	int		len;
	int		width;
	int		height;
	char	*data;
	char	**grid;

	if (argc != 2)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
	{
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	data = read_file(fd, &len);
	close(fd);
	if (!data || len == 0)
	{
		free(data);
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	width = 0;
	while (width < len && data[width] != '\n')
		width++;
	if (width == 0 || width >= len)
	{
		free(data);
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	height = count_lines(data, len);
	if (parse_grid(data, len, width, height, &grid) == -1)
	{
		free(data);
		write(STDOUT_FILENO, "\n", 1);
		return (0);
	}
	free(data);
	count_islands(grid, height, width);
	print_grid(grid, height, width);
	free_grid(grid, height);
	return (0);
}