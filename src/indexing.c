/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:20:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 20:10:40 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	insert_sort(t_pair *arr, size_t size);

void	index_values(t_vector *a)
{
	size_t	i;
	size_t	size;
	t_pair	*temp;

	size = vector_total(a);
	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		ft_error(a, "TEMP ALLOC", NULL);
	i = -1;
	while (++i < size)
	{
		temp[i].value = ((t_pair *)vector_get(a, i))->value;
		temp[i].index = i;
	}
	insert_sort(temp, size);
	i = -1;
	while (++i < size)
		temp[temp[i].index].value = i;
	i = -1;
	while (++i < size)
		((t_pair *)vector_get(a, i))->index = temp[i].value;
	free(temp);
}

static inline void	insert_sort(t_pair *arr, size_t size)
{
	size_t	i;
	size_t	j;
	t_pair	temp;

	i = 1;
	while (i < size)
	{
		temp = arr[i];
		j = i;
		while (j > 0 && arr[j - 1].value > temp.value)
		{
			arr[j] = arr[j - 1];
			--j;
		}
		arr[j] = temp;
		++i;
	}
}
