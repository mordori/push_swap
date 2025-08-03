/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/03 01:14:46 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 01:43:34 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

float	ft_lerp(float a, float b, float t)
{
	return ((1.0f - t) * a + t * b);
}

int	ft_imax(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_imin(int a, int b)
{
	if (a > b)
		return (b);
	return (a);
}

bool	is_prime(size_t num)
{
	size_t	i;

	if (num == 2)
		return (true);
	if (num < 2 || num % 2 == 0)
		return (false);
	i = 3;
	while (i * i <= num)
	{
		if (num % i == 0)
			return (false);
		i += 2;
	}
	return (true);
}

size_t	next_prime(size_t start)
{
	while (!is_prime(start))
		++start;
	return (start);
}
