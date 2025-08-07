/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:45:01 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/07 20:50:42 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_vector *a, t_vector *b)
{
	if (!vector_total(b))
		return ;
	if (!vector_add(a, vector_getlast(b)))
		ft_error(a, b);
	vector_del(b, vector_total(b) - 1);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

void	pb(t_vector *a, t_vector *b)
{
	if (!vector_total(a))
		return ;
	if (!vector_add(b, vector_getlast(a)))
		ft_error(a, b);
	vector_del(a, vector_total(a) - 1);
	ft_putendl_fd("pb", STDOUT_FILENO);
}

void	ra(t_vector *a, t_vector *b)
{
	if (vector_total(a) < 2)
		return ;
	if (!vector_insert(a, vector_getlast(a), 0))
		ft_error(a, b);
	vector_del(a, vector_total(a) - 1);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

void	sa(t_vector *a)
{
	t_pair	*temp;
	size_t	size;

	size = vector_total(a);
	if (size < 2)
		return ;
	temp = (t_pair *)vector_getlast(a);
	vector_set(a, size - 1, vector_get(a, size - 2));
	vector_set(a, size - 2, temp);
	ft_putendl_fd("sa", STDOUT_FILENO);
}

void	rra(t_vector *a, t_vector *b)
{
	if (vector_total(a) < 2)
		return ;
	if (!vector_add(a, vector_get(a, 0)))
		ft_error(a, b);
	vector_del(a, 0);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
