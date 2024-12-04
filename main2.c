#include <stdio.h>
#include "libft.h"
int	**get_data(void)
{
	int		fd;
	int		i;
	int		x;
	char	*line;
	char	**split;
	char	**matrix;

	i = 0;
	line = NULL;
	split = NULL;
	matrix = malloc(sizeof(int *) * INPUT_LINES);
	if (!matrix)
	    return (NULL);
	while (matrix && i < INPUT_LINES)
	{
	    matrix[i] = malloc(sizeof(int) * 5);
	    if (!matrix[i])
	        return (NULL);
	   i++;
	}
	i = 0;
	fd = open("input.txt", O_RDWR);
	if (fd == -1)
		return (write(2, "err\n", 4), NULL);
	line = get_next_line(fd);
	while (line && i < INPUT_LINES)
	{
		split = ft_split(line, ' ');
		if (!split)
			return (1);
		x = 0;
		while (split && x < 5)
		{
		    matrix[i][x] = ft_atoi(split[x]);
		    x++;
		}
		line = get_next_line(fd);
		i++;
	}
	close(fd);
	return (matrix);
}

void    print_matrix(int **matrix, int len, int width)
{
    int i;
    int x;
    
    i = 0;
    while (matrix && i < len)
    {
        x = 0;
        while (x < width)
        {
            printf("matrix[%d][%d] = %d\n", i, x, matrix[i][x]);
            x++;
        }
        i++;
    }
}

int main()
{
    int **matrix;
    
    matrix = get_data();
    print_matrix(matrix, 1000, 5);
    return 0;
}
