#ifndef COUNT_ISLAND_H
#define COUNT_ISLAND_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

char	*read_file(int fd, int *out_len);
int		count_lines(const char *data, int len);
int		parse_grid(char *data, int len, int width, int height, char ***out_grid);
void	fill_island(char **grid, int i, int j, int h, int w, char label);
void	count_islands(char **grid, int h, int w);
void	print_grid(char **grid, int h, int w);
void	free_grid(char **grid, int h);

#endif
