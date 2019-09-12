/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sudoku.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bshaquan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/10 19:16:33 by bshaquan          #+#    #+#             */
/*   Updated: 2019/08/11 18:32:24 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		looking_for_num(int **numbers, int row, int col, int value)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < 9)
	{
		if ((numbers[i][col] == value) || (numbers[row][i] == value))
			return (0);
		i += 1;
	}
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			if (numbers[row - (row % 3) + i][col - (col % 3) + j] == value)
				return (0);
			j += 1;
		}
		i += 1;
	}
	return (1);
}

int		solve(int **numbers, int value)
{
	int	i;
	int	x;
	int	y;

	i = 1;
	x = value / 9;
	y = value % 9;
	if (value == 81)
		return (1);
	if (numbers[x][y] != 0)
		return (solve(numbers, value + 1));
	while (i < 10)
	{
		if (looking_for_num(numbers, x, y, i))
		{
			numbers[x][y] = i;
			if (solve(numbers, value + 1))
				return (1);
			else
				numbers[x][y] = 0;
		}
		i += 1;
	}
	return (0);
}

int		rev_solve(int **numbers, int value)
{
	int	i;
	int	x;
	int	y;

	i = 9;
	x = value / 9;
	y = value % 9;
	if (value == 81)
		return (1);
	if (numbers[x][y] != 0)
		return (rev_solve(numbers, value + 1));
	while (i > 0)
	{
		if (looking_for_num(numbers, x, y, i))
		{
			numbers[x][y] = i;
			if (rev_solve(numbers, value + 1))
				return (1);
			else
				numbers[x][y] = 0;
		}
		i -= 1;
	}
	return (0);
}

int		result(int **nums, int **nums_1)
{
	int i;
	int j;

	i = 0;
	if (solve(nums, 0) == 1 && rev_solve(nums_1, 0) == 1)
		while (i < 9)
		{
			j = 0;
			while (j < 9)
			{
				if (nums[i][j] != nums_1[i][j])
					return (0);
				j++;
			}
			i++;
		}
	if (solve(nums, 0) == 0 && rev_solve(nums_1, 0) == 0)
		return (0);
	return (1);
}
