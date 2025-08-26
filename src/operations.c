/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/04 01:45:01 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/27 01:54:35 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Push top element of stack B onto stack A.
 *
 * @param a Destination stack (vector).
 * @param b Source stack (vector).
 */
void	pa(t_vector *a, t_vector *b)
{
	if (!vector_total(b))
		return ;
	if (!vector_add(a, vector_getlast(b)))
		ft_error(a, b);
	vector_del(b, vector_total(b) - 1);
	ft_putendl_fd("pa", STDOUT_FILENO);
}

/**
 * @brief Push top element of stack A onto stack B.
 *
 * @param a Source stack (vector).
 * @param b Destination stack (vector).
 */
void	pb(t_vector *a, t_vector *b)
{
	if (!vector_total(a))
		return ;
	if (!vector_add(b, vector_getlast(a)))
		ft_error(a, b);
	vector_del(a, vector_total(a) - 1);
	ft_putendl_fd("pb", STDOUT_FILENO);
}


/**
 * @brief Rotate stack A upwards.
 *
 * @param a Stack A to rotate.
 * @param b Stack B (used only for error handling).
 */
void	ra(t_vector *a, t_vector *b)
{
	if (vector_total(a) < 2)
		return ;
	if (!vector_insert(a, vector_getlast(a), 0))
		ft_error(a, b);
	vector_del(a, vector_total(a) - 1);
	ft_putendl_fd("ra", STDOUT_FILENO);
}

/**
 * @brief Swap the two top elements of stack A.
 *
 * @param a Stack A to operate on.
 */
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

/**
 * @brief Reverse rotate stack A downwards.
 *
 * @param a Stack A to reverse rotate.
 * @param b Stack B (used only for error handling).
 */
void	rra(t_vector *a, t_vector *b)
{
	if (vector_total(a) < 2)
		return ;
	if (!vector_add(a, vector_get(a, 0)))
		ft_error(a, b);
	vector_del(a, 0);
	ft_putendl_fd("rra", STDOUT_FILENO);
}
