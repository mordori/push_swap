/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:49:14 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/08 01:45:40 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	sort_three(t_vector *a, t_vector *b);
static inline void	pb_min(t_vector *a, t_vector *b);
static inline int32_t	max_index_bits(t_vector *a);

void	small_sort(t_vector *a, t_vector *b)
{
	size_t	size;

	size = vector_total(a);
	if (size == 2)
	{
		if (((t_pair *)vector_get(a, 0))->index <
			((t_pair *)vector_get(a, 1))->index)
			sa(a);
		return ;
	}
	while (vector_total(a) > 3)
		pb_min(a, b);
	sort_three(a, b);
	while (vector_total(b))
		pa(a, b);
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

static inline void	pb_min(t_vector *a, t_vector *b)
{
	size_t	i;
	size_t	idx;
	int32_t	min;
	int32_t	current;

	i = 0;
	idx = 0;
	while (i < vector_total(a))
	{
		min = ((t_pair *)vector_get(a, idx))->index;
		current = ((t_pair *)vector_get(a, i))->index;
		if (current < min)
			idx = i;
		++i;
	}
	if (idx == 2 && vector_total(a) == 5)
		ra(a, b);
	if ((idx == 3 && vector_total(a) == 5) || idx == 2)
		sa(a);
	if (idx == 1)
		rra(a, b);
	if (idx == 1 || idx == 0)
		rra(a, b);
	pb(a, b);
}

static inline void	sort_three(t_vector *a, t_vector *b)
{
	int32_t	idx0;
	int32_t	idx1;
	int32_t	idx2;

	idx2 = ((t_pair *)vector_get(a, 2))->index;
	idx1 = ((t_pair *)vector_get(a, 1))->index;
	idx0 = ((t_pair *)vector_get(a, 0))->index;
	if(idx2 < idx1 && idx2 < idx0 && idx0 < idx1)
	{
		rra(a,b);
		sa(a);
	}
	else if(idx1 < idx2 && idx1 < idx0 && idx2 < idx0)
		sa(a);
	else if(idx1 < idx2 && idx1 < idx0 && idx0 < idx2)
		ra(a, b);
	else if(idx0 < idx2 && idx0 < idx1 && idx2 < idx1)
		rra(a,b);
	else if(idx0 < idx2 && idx0 < idx1 && idx1 < idx2)
	{
		ra(a,b);
		sa(a);
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
