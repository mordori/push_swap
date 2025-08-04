/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:49:14 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 20:19:26 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int32_t	max_index_bits(t_vector *a);

void	radix_sort(t_vector *a)
{
	t_vector		*b;
	static int32_t	i;
	size_t			j;
	size_t			size;
	int32_t			index;

	b = malloc(sizeof (t_vector));
	if (!b || !vector_init(b, false, false))
		(free(b), ft_error(a, "B INIT", NULL));
	while (i++ < max_index_bits(a))
	{
		j = 0;
		size = vector_total(a);
		while (j++ < size)
		{
			index = ((t_pair *)vector_getlast(a))->index;
			if (((index >> (i - 1)) & 1) == 0)
				pb(a, b);
			else
				ra(a);
		}
		while (vector_total(b))
			pa(a, b);
	}
	(vector_free(b), free(b));
}

static inline int32_t	max_index_bits(t_vector *a)
{
	size_t	i;
	int32_t	bits;
	int32_t	max;

	i = 0;
	max = -1;
	bits = 0;
	while (i < vector_total(a))
	{
		max = ft_imax(max, ((t_pair *)vector_get(a, i))->index);
		++i;
	}
	while (max >> bits)
		++bits;
	return (bits);
}
