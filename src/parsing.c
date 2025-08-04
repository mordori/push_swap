/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:46:37 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 23:47:49 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	parse_numbers(t_vector *a, char **elems);
static inline void	check_duplicates(t_vector *a, size_t i);

void	parse_input(int argc, char *argv[], t_vector *a)
{
	int		i;
	char	**elems;

	i = argc - 1;
	while (i > 0)
	{
		elems = ft_split(argv[i], ' ');
		if (!elems)
			ft_error(a, NULL);
		if (!*elems)
			(ft_free_split(elems), ft_error(a, NULL));
		parse_numbers(a, elems);
		ft_free_split(elems);
		--i;
	}
	check_duplicates(a, 0);
}

static inline void	parse_numbers(t_vector *a, char **elems)
{
	int		i;
	int64_t	val;
	t_pair	*pair;
	char	end;

	i = 0;
	while (elems[i])
		++i;
	while (--i >= 0)
	{
		end = 'e';
		pair = malloc(sizeof (*pair));
		if (!pair)
			(ft_free_split(elems), ft_error(a, NULL));
		pair->index = -1;
		val = ft_atol(elems[i], &end);
		if (end || val > INT_MAX || val < INT_MIN)
			(free(pair), ft_free_split(elems), ft_error(a, NULL));
		pair->value = (int32_t)val;
		if (!vector_add(a, pair))
			(free(pair), ft_free_split(elems), ft_error(a, NULL));
	}
}

static inline void	check_duplicates(t_vector *a, size_t i)
{
	int			*hash_table;
	bool		*used;
	int			val;
	uint32_t	idx;
	size_t		prime;

	prime = next_prime(vector_total(a) * 2);
	hash_table = ft_calloc(prime, sizeof (*hash_table));
	used = ft_calloc(prime, sizeof (*used));
	if (!hash_table || !used)
		(free(hash_table), free(used), ft_error(a, NULL));
	while (i < vector_total(a))
	{
		val = ((t_pair *)vector_get(a, i++))->value;
		idx = ((uint32_t)val) % prime;
		while (used[idx])
		{
			if (hash_table[idx] == val)
				(free(hash_table), free(used), ft_error(a, NULL));
			idx = (idx + 1) % prime;
		}
		hash_table[idx] = val;
		used[idx] = true;
	}
	(free(hash_table), free(used));
}
