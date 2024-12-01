/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:00:29 by martalop          #+#    #+#             */
/*   Updated: 2024/12/01 20:44:33 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

int	fill_stacks(int *stack_a, int *stack_b)
{
	int		fd;
	int		i;
	int		s_i;
	char	*line;
	char	**line_arr;

	i = 1;
	s_i = 0;
	line = NULL;
	line_arr = NULL;
	fd = open("input", O_RDWR);
	if (fd == -1)
		return (write(2, "err\n", 4), 1);
	line = get_next_line(fd);
	while (line && s_i < 1000)
	{
		line_arr = ft_split(line, ' ');
		if (!line_arr)
			return (1);
		stack_a[s_i] = ft_atoi(line_arr[0]);
		stack_b[s_i] = ft_atoi(line_arr[1]);
		line = get_next_line(fd);
		i++;
		s_i++;
	}
	close(fd);
	return (0);
}

int	find_smallest(int *stack_a, int smallest)
{
	int	min;
	int	nb;
	int	tmp;
	int	i;

	i = 0;
	tmp = -1;
	min = 2147483647;
	if (smallest == -1)
		nb = -1;
	else
		nb = smallest;
	while (stack_a && stack_a[i])
	{
		if (stack_a[i] == 0 && smallest == -1)
		{
			return (stack_a[i]);
		}
		if (stack_a[i] < min && stack_a[i] > nb)
		{
			min = stack_a[i];
			tmp = stack_a[i];
		}
		i++;
	}
	return (tmp);
}

void	order_stacks(int *stack_a, int stack_b)
{
	int	i;
	int	j;
	int	smallest;

	i = 0;
	j = 0;
	smallest = -1;
	while (stack_a[i])
	{
		//find_smallest
		smallest = find_smallest(stack_a, smallest);
		//put it at the top after the last smallest number
		i++;
	}
}

int	main(void)
{
	int		*stack_a;
	int		*stack_b;

	stack_a = malloc(sizeof(int) * 1000);
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(int) * 1000);
	if (!stack_b)
		return (1);
	fill_stacks(stack_a, stack_b);
	//ordenar cada stack de menor a mayor
	order_stacks(stack_a, stack_b);
	// hacer restas de cada stack en la posicion en la que estan y guardarlas en algun sitio
	// pasar los resultados a valores sin negativos
	// sumar los resultados
	return (0);
}
