/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:28:16 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 09:28:26 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static inline void	print_stack(t_vector *a);

int	main(int argc, char *argv[])
{
	t_vector	*a;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = malloc(sizeof (* a));
	if (!a || !vector_init(a, true, false))
		ft_error(NULL, "A INIT", NULL);
	parse_input(argc, argv, a);
	index_values(a);
	radix_sort(a);
	vector_free(a);
	free(a);
	return (EXIT_SUCCESS);
}

void	ft_error(t_vector *a, char *msg, t_vector *b)
{
	ft_putendl_fd("Error", STDERR_FILENO);
	ft_putendl_fd(msg, STDERR_FILENO);
	vector_free(b);
	vector_free(a);
	free(b);
	free(a);
	exit(EXIT_FAILURE);
}

static inline void	print_stack(t_vector *a)
{
	int	i;

	i = vector_total(a) - 1;
	while (i >= 0)
		ft_printf("%d ", ((t_pair *)vector_get(a, i--))->value);
	ft_printf("\n");
}
