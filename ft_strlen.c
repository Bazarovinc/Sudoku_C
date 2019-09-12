/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ctelma <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 18:24:58 by ctelma            #+#    #+#             */
/*   Updated: 2019/08/11 18:20:54 by ctelma           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "functions.h"

int		ft_strlen(char *str)
{
	int count_of_str;

	count_of_str = 0;
	while (str[count_of_str] != '\0')
	{
		count_of_str = count_of_str + 1;
	}
	return (count_of_str);
}
