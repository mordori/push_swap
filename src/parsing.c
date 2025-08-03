/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:46:37 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 01:47:47 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	parse_numbers(t_vector *a, char **elems, char *end, int *index);

void	parse_input(int argc, char *argv[], t_vector *a)
{
	int		i;
	int		index;
	char	*end;
	char	**elems;

	i = 1;
	index = 0;
	end = malloc(sizeof (*end));
	while (i < argc)
	{
		elems = ft_split(argv[i], ' ');
		if (!elems || !*elems)
			free(end), ft_error(a, "ELEMS ALLOC", NULL);
		parse_numbers(a, elems, end, &index);
		ft_free_split(elems);
		++i;
	}
	free(end);
}

void	check_duplicates(t_vector *a, size_t i)
{
	int			*hash_table;
	bool		*used;
	int			value;
	uint32_t	index;
	size_t		prime;

	prime = next_prime(vector_total(a) * 2);
	hash_table = ft_calloc(prime, sizeof (*hash_table));
	used = ft_calloc(prime, sizeof (*used));
	if (!hash_table || !used)
		free(hash_table), free(used), ft_error(a, "HASH", NULL);
	while (i < vector_total(a))
	{
		value = *(int *)vector_get(a, i++);
		index = ((uint32_t)value) % prime;
		while (used[index])
		{
			if (hash_table[index] == value)
				free(hash_table), free(used), ft_error(a, "DUPLICATE", NULL);
			index = (index + 1) % prime;
		}
		hash_table[index] = value;
		used[index] = true;
	}
	free(hash_table), free(used);
}

static inline void	parse_numbers(t_vector *a, char **elems, char *end, int *index)
{
	int64_t	*num;
	int		j;

	j = 0;
	while (elems[j])
	{
		*end = 'e';
		num = malloc(sizeof (*num));
		if (!num)
			free(end), ft_free_split(elems), ft_error(a, "NUM ALLOC", NULL);
		*num = ft_atol(elems[j], end);
		if ((*end) || *num > INT_MAX || *num < INT_MIN)
			free(end), ft_free_split(elems), ft_error(a, "INPUT ABOMINATION", NULL);
		if (!vector_add(a, num))
			free(end), ft_error(a, "A ADD", NULL);
		++index;
		++j;
	}
}
