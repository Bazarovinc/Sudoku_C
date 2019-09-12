/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 16:21:04 by bshaquan          #+#    #+#             */
/*   Updated: 2019/08/11 17:53:45 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

void	screen_numbers(int **numbers)
{
	int	x;
	int	y;

	x = 0;
	while (x < 9)
	{
		y = 0;
		while (y < 9)
		{
			ft_putchar(numbers[x][y] + '0');
			if (y != 8)
				ft_putchar(' ');
			y += 1;
		}
		ft_putchar('\n');
		x += 1;
	}
}

int		**read_numbers(char **argv)
{
	int	x;
	int	y;
	int	**numbers;

	x = 0;
	numbers = (int **)malloc(sizeof(int *) * 9);
	while (x < 9)
	{
		if (ft_strlen(argv[x]) != 9)
			return (0);
		numbers[x] = (int *)malloc(sizeof(int) * 9);
		y = 0;
		while (y < 9)
		{
			if (argv[x][y] == '.')
				numbers[x][y] = 0;
			else if (argv[x][y] >= '1' && argv[x][y] <= '9')
				numbers[x][y] = argv[x][y] - '0';
			else
				return (0);
			y += 1;
		}
		x += 1;
	}
	return (numbers);
}

void	clean(int **nums)
{
	int i;

	i = 0;
	if (nums != NULL)
	{
		while (nums[i])
		{
			free(nums[i]);
			i++;
		}
		free(nums);
	}
}

int		main(int argc, char **argv)
{
	int	**nums;
	int **nums_1;

	if (argc == 10)
	{
		nums = read_numbers(argv + 1);
		nums_1 = read_numbers(argv + 1);
		if (!nums)
			ft_putstr("Error\n");
		else if (result(nums, nums_1))
		{
			screen_numbers(nums);
			clean(nums);
			clean(nums_1);
		}
		else
			ft_putstr("Error\n");
	}
	else
		ft_putstr("Error\n");
	return (0);
}
