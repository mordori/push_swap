/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:49:14 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 01:49:42 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_vector *a)
{
	t_vector	*b;
	size_t		bits;
	size_t		i;
	size_t		j;
	int			num;

	b = malloc(sizeof (t_vector));
	if (!b || !vector_init(b, false, false))
		ft_error(a, "B INIT", NULL);
	bits = 0;
	int max = 0;
	i = 0;
	while (i < vector_total(a))
	{
		int val = *(int *)vector_get(a, i);
		if (val > max)
			max = val;
		++i;
	}
	while (max >> bits)
		++bits;
	i = 0;
	while (i < bits)
	{
		j = 0;
		size_t k = vector_total(a);
		while (j++ < k)
		{
			num = *(int *)vector_getlast(a);
			if (((num >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		++i;
		while (vector_total(b))
			pa(a, b);
	}
	vector_free(b);
	free(b);
}
