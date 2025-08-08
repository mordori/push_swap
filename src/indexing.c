/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:20:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/08 15:00:02 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline bool	is_descending(t_pair *arr, size_t size);
static inline void	insertion_sort(t_pair *arr, size_t size);
static inline void	make_indexes(t_vector *a, t_pair *arr, size_t size);

void	index_values(t_vector *a)
{
	size_t	i;
	size_t	size;
	t_pair	*temp;

	size = vector_total(a);
	temp = malloc(sizeof(*temp) * size);
	if (!temp)
		ft_error(a, NULL);
	i = 0;
	while (i < size)
	{
		temp[i].value = ((t_pair *)vector_get(a, i))->value;
		temp[i].index = i;
		++i;
	}
	if (size < 2 || is_descending(temp, size))
	{
		free(temp);
		vector_free(a, NULL);
		exit(EXIT_SUCCESS);
	}
	insertion_sort(temp, size);
	make_indexes(a, temp, size);
	free(temp);
}

static inline bool	is_descending(t_pair *arr, size_t size)
{
	size_t	i;

	i = 1;
	while (i < size)
	{
		if (arr[i - 1].value < arr[i].value)
			return (false);
		++i;
	}
	return (true);
}

static inline void	insertion_sort(t_pair *arr, size_t size)
{
	size_t	i;
	size_t	j;
	t_pair	temp;

	i = 0;
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

static inline void	make_indexes(t_vector *a, t_pair *arr, size_t size)
{
	size_t	i;

	i = 0;
	while (i < size)
	{
		arr[arr[i].index].value = i;
		++i;
	}
	i = 0;
	while (i < size)
	{
		((t_pair *)vector_get(a, i))->index = arr[i].value;
		++i;
	}
}
