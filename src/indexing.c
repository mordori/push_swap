/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 09:20:54 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/27 01:50:33 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline bool	is_descending(t_pair *arr, size_t size);
static inline void	insertion_sort(t_pair *arr, size_t size);
static inline void	make_indexes(t_vector *a, t_pair *arr, size_t size);

/**
 * @brief Assigns indices to the values in the vector for sorting.
 *
 * Creates a temporary array of pairs (value, index), sorts them,
 * and assigns each value a unique index based on its rank in the sorted order.
 *
 * If the input is already sorted in descending order or has fewer
 * than 2 elements, the program frees resources and exits successfully.
 *
 * @param a Vector containing the input values.
 */
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

/**
 * @brief Checks if an array of pairs is sorted in descending order by value.
 *
 * @param arr Array of pairs to check.
 * @param size Number of elements in the array.
 * @return true if the array is in descending order, false otherwise.
 */
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

/**
 * @brief Sorts an array of pairs in ascending order by value using
 * insertion sort.
 *
 * @param arr Array of pairs to be sorted (modified in place).
 * @param size Number of elements in the array.
 */
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

/**
 * @brief Assigns sorted indices back to the original vector elements.
 *
 * After sorting the temporary array by value:
 *
 * - Each element is given an index corresponding to its rank in sorted order.
 *
 * - The original vector is updated so each element has its correct index.
 *
 * @param a Vector whose elements are updated.
 * @param arr Temporary sorted array of pairs.
 * @param size Number of elements in both the array and the vector.
 */
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
