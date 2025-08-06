/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:49:14 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/06 20:03:51 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline int32_t	max_index_bits(t_vector *a);

void	small_sort(t_vector *a, t_vector *b)
{

}

void	radix_sort(t_vector *a, t_vector *b)
{
	int32_t	i;
	size_t	size;
	t_pair	*pair;

	i = 0;
	while (i < max_index_bits(a))
	{
		size = vector_total(a);
		while (size--)
		{
			pair = (t_pair *)vector_getlast(a);
			if (((pair->index >> i) & 1) == 0)
				pb(a, b);
			else
				ra(a, b);
		}
		while (vector_total(b))
			pa(a, b);
		++i;
	}
}

static inline int32_t	max_index_bits(t_vector *a)
{
	size_t	i;
	int32_t	bits;
	int32_t	max;
	t_pair	*pair;

	i = 0;
	max = -1;
	bits = 0;
	while (i < vector_total(a))
	{
		pair = (t_pair *)vector_get(a, i);
		max = ft_imax(max, pair->index);
		++i;
	}
	while (max >> bits)
		++bits;
	return (bits);
}
