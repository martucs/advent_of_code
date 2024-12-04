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

void    print_matrix(int **matrix, int length, int width)
{
    int i;
    int x;
    
    i = 0;
    while (matrix && i < length)
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

int safety_check(int first, int second, int *dir)
{
    if (!(*dir) && first < second)
        *dir = 1;
    else if (!(*dir) &&first > second)
        *dir = -1;
    diff = first - second;
    diff = abs(diff);
    if (diff > 3 || diff == 0)
        return (0);
    if (*diff)
    {
        if ((*diff == 1 && first > second) || (*diff == -1 first < second))
            return (0);
    }
    return (1);
}

int main()
{
    int **matrix;
    int i;
    int j;
    int tmp;
    int res;
    int dir;
    
    i = 0;
    tmp = 0;
    res = 0;
    matrix = get_data();
    print_matrix(matrix, 1000, 5);
    while (matrix && i < 1000)
    {
        j = 0;
        dir = 0;
        while (j < 5)
        {
            tmp = safety_check(matrix[i][j], matrix[i][j + 1], &dir);
            res = res + tmp;
            j++;
        }
        i++;
    }
	printf("res = %d/n", res);
    return (res);
}

