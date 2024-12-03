/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martalop <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/01 18:00:29 by martalop          #+#    #+#             */
/*   Updated: 2024/12/03 16:21:04 by martalop         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "libft/libft.h"

#ifndef INPUT_LINES
#define INPUT_LINES 1000
#endif

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
	while (line && s_i < INPUT_LINES)
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

void	print_stack(int *stack, int len)
{
	int	i;

	i = 0;
	while (stack && i < len)
	{
		printf("Stack[%d]: %d\n", i, stack[i]);
		i++;
	}
}

int	find_smallest(int *stack)
{
	int	min;
	int	i;
	int	j;

	min = 2147483647;
	i = 0;
	j = 0;
	while (i < INPUT_LINES)
	{
		if (stack[i] < min && stack[i] > -1)
		{
			min = stack[i];
			j = i;
		}
		++i;
	}
	stack[j] = -1;
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
	new_stack = malloc(sizeof(int) * INPUT_LINES);
	if (!new_stack)
		return (NULL);
	while (i < INPUT_LINES)
	{
		smallest = find_smallest(stack); 
		new_stack[i] = smallest;
		i++;
	}
	return (new_stack);
}
// *
// smallest = find_smallest(stack);
// new_stack[i] = smallest;
//
// we find the smallest number in 'stack' and we CHANGE its value to -1
// we store the number found in 'new_stack'
// 'stack' ends the while loop full of -1's
// *

int	*get_diff(int *stack_a, int *stack_b)
{
	int	*diff;
	int	i;

	i = 0;	
	diff = malloc(sizeof(int) * 6);
	if (!diff)
		return (NULL);
	while (i < INPUT_LINES)
	{
		diff[i] = stack_a[i] - stack_b[i];
		if (diff[i] < 0)
			diff[i] *= -1;
		i++;
	}
	return (diff);
}

int	do_diff_sum(int *array)
{
	int	i;
	int	res;

	i = 0;
	res = 0;
	while (i < INPUT_LINES)
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
	int		*diff;
	int		sum_res;

	stack_a = malloc(sizeof(int) * INPUT_LINES);
	if (!stack_a)
		return (1);
	stack_b = malloc(sizeof(int) * INPUT_LINES);
	if (!stack_b)
		return (1);
	fill_stacks(stack_a, stack_b);
//	printf("before order\n");
//	print_stack(stack_a, INPUT_LINES);
//	printf("\n");
//	print_stack(stack_b, INPUT_LINES);
	ord_stack_a = get_ordered_stack(stack_a);
	ord_stack_b = get_ordered_stack(stack_b);
//	printf("\nafter order\n");
//	print_stack(ord_stack_a, INPUT_LINES);
//	printf("\n");
//	print_stack(ord_stack_b, INPUT_LINES);
	diff = get_diff(ord_stack_a, ord_stack_b);
//	printf("\ndiff\n");
//	print_stack(diff, INPUT_LINES);
	sum_res = do_diff_sum(diff);
	printf("res = %d\n", sum_res);
	return (0);
}
