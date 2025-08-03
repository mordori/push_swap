/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:28:16 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 01:51:05 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_vector	*a;

	if (argc < 2)
		return (EXIT_SUCCESS);
	a = malloc(sizeof (* a));
	if (!a || !vector_init(a, true, false))
		ft_error(NULL, "A INIT", NULL);
	parse_input(argc, argv, a);
	check_duplicates(a, 0);
	radix_sort(a);

	for (int s = vector_total(a)-1; s >= 0; --s)
		ft_printf("%d ", *(int *)vector_get(a, s));
	ft_printf("\n");

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
