/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:00:29 by martalop          #+#    #+#             */
/*   Updated: 2024/12/02 21:48:13 by martalop         ###   ########.fr       */
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
	fd = open("input2", O_RDWR);
	if (fd == -1)
		return (write(2, "err\n", 4), 1);
	line = get_next_line(fd);
	while (line && s_i < 6)
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

void	print_stack(int );

int	find_smallest(int *stack, /*int lenght,*/ int smallest)
{
	int	min;
	int	nb;
	int	tmp;
	int	i;
	int	j;

//	i = 0;
//	tmp = -1;
	min = 2147483647;
//	if (smallest == -1)
//		nb = -1;
//	else
//		nb = smallest;
	i = 0;
	j = 0;
	while (i < 6)
	{
		//printf("Stack[%d]: %d\n", i, stack[i]);
		if (stack[i] < min && stack[i] > -1)
		{
			min = stack[i];
			j = i;
		}
		++i;
	}
	stack[j] = -1;
	return (min);

	while (stack && stack[i] && i < 6)
	{
		printf("stack = %d\n", stack[i]);
		if (stack[i] == 0 && smallest == -1)
		{
			return (stack[i]);
		}
		if (stack[i] < min && stack[i] > -1)
		{
			min = stack[i];
		}
	/*	if (stack[i] == smallest && min == 2147483647)
		{
			printf("stack = %d\n", stack[i]);
			printf("min = %d\n", min);
			return (smallest);
		}*/
		i++;
	}
	return (min);
}

int	*get_ordered_stack(int *stack)
{
	int	i;
	int	j;
	int	*new_stack;
	int	smallest;

	i = 0;
	j = 0;
	smallest = -1;
	new_stack = malloc(sizeof(int) * 6);
	if (!new_stack)
		return (NULL);
	while (i < 6)
	{
		//find_smallest
		smallest = find_smallest(stack, smallest);
	//	printf("stack in %d: %d\n", i, stack[i]);
		new_stack[i] = smallest;
		printf("smallest = %d\n", smallest);
	//	printf("new_stack in %d: %d\n", i, new_stack[i]);
		//put it at the top after the last smallest number
		i++;
	}
	return (new_stack);
}

/*int	main(void)
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
}*/

int	*get_diff(int *stack_a, int *stack_b)
{
	int	*diff1;
	int	i;

	i = 0:	
	diff1 = malloc(sizeof(int) * 6);
	if (!diff1)
		return (NULL);
	while (i < 6)
	{
		diff[i] = stack_a[i] - stack_b[i];
		if (diff[i] < 0)
			diff[i] x= -1;
		i++;
	}
}

int	do_diff_sum(int *array)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < 6)
	{
		res = res + array[i];
		i++;
	}
	return (res);
}

int	main(void)
{

	int		*stack_a;
	int		*stack_b;
	int		*ord_stack_a;
	int		*ord_stack_b;
	int		*diff1;

	stack_a = malloc(sizeof(int) * 6);
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(int) * 6);
	if (!stack_b)
		return (1);
	fill_stacks(stack_a, stack_b);
	ord_stack_a = get_ordered_stack(stack_a);
	ord_stack_b = get_ordered_stack(stack_b);
	diff1 = get_diff(stack_a, stack_b);
	sum_res = do_diff_sum(diff1);
	printf("res = %d\n", sum_res);
	return (0);
}
