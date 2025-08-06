/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:28:16 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/06 20:27:17 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_vector	*a;
	t_vector	*b;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = malloc(sizeof(*a));
	if (!a || !vector_init(a, true, false))
		ft_error(a, NULL);
	parse_input(argc, argv, a);
	index_values(a);
	b = malloc(sizeof(*b));
	if (!b || !vector_init(b, true, false))
		ft_error(a, b);
	if (vector_total(a) <= 5)
		small_sort(a, b);
	else
		radix_sort(a, b);
	vector_free(a, b, NULL);
	return (EXIT_SUCCESS);
}

void	ft_error(t_vector *a, t_vector *b)
{
	vector_free(a, b, NULL);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

void	print_stack(t_vector *a)
{
	int	i;

	i = vector_total(a) - 1;
	while (i >= 0)
		ft_printf("%d ", ((t_pair *)vector_get(a, i--))->value);
	ft_printf("\n");
}
