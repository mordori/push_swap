/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:49:14 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 09:21:09 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int	max_index_bits(t_vector *a);

void	radix_sort(t_vector *a)
{
	t_vector	*b;
	size_t		bits;
	size_t		i;
	size_t		j;
	int32_t		index;

	b = malloc(sizeof (t_vector));
	if (!b || !vector_init(b, false, false))
		ft_error(a, "B INIT", NULL);
	bits = max_index_bits(a);
	i = 0;
	while (i < bits)
	{
		j = 0;
		size_t k = vector_total(a);
		while (j++ < k)
		{
			index = ((t_pair *)vector_getlast(a))->index;
			if (((index >> i) & 1) == 0)
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

static inline int	max_index_bits(t_vector *a)
{
	size_t	i;
	size_t	bits;
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
