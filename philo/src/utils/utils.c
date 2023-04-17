/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zstenger <zstenger@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:28:35 by zstenger          #+#    #+#             */
/*   Updated: 2023/04/17 11:28:41 by zstenger         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	ft_atoi(const char *str)
{
	int	z;
	int	res;
	int	sign;

	z = 0;
	res = 0;
	sign = 1;
	while (str[z] == ' ' || str[z] == '\f' || str[z] == '\n' || str[z] == '\r'
		|| str[z] == '\t' || str[z] == '\v')
			z++;
	if (str[z] == '-')
	{
		sign *= (-1);
		z++;
	}
	else if (str[z] == '+')
		z++;
	while (str[z] >= '0' && str[z] <= '9')
	{
		res = res * 10 + str[z] - '0';
		z++;
	}
	return (res * sign);
}
