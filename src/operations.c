/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:45:01 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 23:48:24 by myli-pen         ###   ########.fr       */
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
