/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: myli-pen <myli-pen@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/02 16:28:30 by myli-pen          #+#    #+#             */
/*   Updated: 2025/08/04 01:50:17 by myli-pen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define HASH_SIZE 100003

# include "libft_io.h"
# include "libft_math.h"
# include "libft_mem.h"
# include "libft_str.h"
# include "libft_utils.h"
# include "libft_vector.h"

void	pa(t_vector *a, t_vector *b);
void	pb(t_vector *a, t_vector *b);
void	ra(t_vector *a);
void	parse_input(int argc, char *argv[], t_vector *a);
void	check_duplicates(t_vector *a, size_t i);
void	radix_sort(t_vector *a);
void	ft_error(t_vector *a, char *msg, t_vector *b);

#endif
