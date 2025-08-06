/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:46:37 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/06 19:57:05 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	parse_numbers(t_vector *a, char **elems);
static inline void	check_duplicates(t_vector *a, size_t i, size_t prime);
static inline void	error_parse(char **elems, t_pair *pair, t_vector *a);
static inline void	error_hash(int32_t *hash_table, bool *used, t_vector *a);

void	parse_input(int argc, char *argv[], t_vector *a)
{
	int		i;
	char	**elems;

	i = argc - 1;
	while (i > 0)
	{
		elems = ft_split(argv[i], ' ');
		if (!elems)
			error_parse(NULL, NULL, a);
		if (!*elems)
			error_parse(elems, NULL, a);
		parse_numbers(a, elems);
		ft_free_split(elems);
		--i;
	}
	check_duplicates(a, 0, 0);
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
		pair = malloc(sizeof(*pair));
		if (!pair)
			error_parse(elems, NULL, a);
		pair->index = -1;
		val = ft_atol(elems[i], &end);
		if (end || val > INT_MAX || val < INT_MIN)
			error_parse(elems, pair, a);
		pair->value = (int32_t)val;
		if (!vector_add(a, pair))
			error_parse(elems, pair, a);
	}
}

static inline void	check_duplicates(t_vector *a, size_t i, size_t prime)
{
	int32_t		*hash_table;
	bool		*used;
	int32_t		val;
	uint32_t	idx;

	prime = next_prime(vector_total(a) * 2);
	hash_table = ft_calloc(prime, sizeof(*hash_table));
	used = ft_calloc(prime, sizeof(*used));
	if (!hash_table || !used)
		error_hash(hash_table, used, a);
	while (i < vector_total(a))
	{
		val = ((t_pair *)vector_get(a, i++))->value;
		idx = ((uint32_t)val) % prime;
		while (used[idx])
		{
			if (hash_table[idx] == val)
				error_hash(hash_table, used, a);
			idx = (idx + 1) % prime;
		}
		hash_table[idx] = val;
		used[idx] = true;
	}
	free(hash_table);
	free(used);
}

static inline void	error_parse(char **elems, t_pair *pair, t_vector *a)
{
	free(pair);
	ft_free_split(elems);
	ft_error(a, NULL);
}

static inline void	error_hash(int32_t *hash_table, bool *used, t_vector *a)
{
	free(hash_table);
	free(used);
	ft_error(a, NULL);
}
