/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:28:16 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/27 01:26:42 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Entry point for the program.
 *
 * The program initializes two vectors (stacks), parses input values into
 * stack A, assigns indices to the values, and sorts them using either
 * a small-sort algorithm if the total number of values ≤ 5, or
 * radix sort otherwise.
 *
 * @param argc Argument count.
 * @param argv Argument values.
 * @return EXIT_SUCCESS on normal completion.
 */
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
	print_stack(a);
	if (vector_total(a) <= 5)
		small_sort(a, b);
	else
		radix_sort(a, b);
	print_stack(a);
	vector_free(a, b, NULL);
	return (EXIT_SUCCESS);
}

/**
 * @brief Handles fatal errors by freeing vectors and terminating the program.
 *
 * If memory allocation or initialization fails, this function ensures cleanup
 * before printing an error message to stderr and exiting.
 *
 * @param a First vector.
 * @param b Second vector.
 */
void	ft_error(t_vector *a, t_vector *b)
{
	vector_free(a, b, NULL);
	ft_putendl_fd("Error", STDERR_FILENO);
	exit(EXIT_FAILURE);
}

/**
 * @brief Prints the contents of a vector representing a stack.
 *
 * @param a Vector (stack) to be printed.
 */
void	print_stack(t_vector *a)
{
	int	i;

	i = vector_total(a) - 1;
	while (i >= 0)
		ft_printf("%d ", ((t_pair *)vector_get(a, i--))->value);
	ft_printf("\n");
}
