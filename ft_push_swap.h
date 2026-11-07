/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arozados <arozados@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:55 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/06 13:43:10 by arozados         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_stack;

/* Stack utilities */

/* Returns the number of nodes in a stack. */
int		lstsize(t_stack *stack);

/* Returns a pointer to the node with the smallest value. */
t_stack	*find_min(t_stack *stack);

/* Sorting algorithms */

/* Sorts stack A using stack B as auxiliary storage. */
t_stack	*selection_sort(t_stack **a, t_stack **b);

/* Stack operations */

/* Moves the first node of A to the top of B. */
void	pb(t_stack **a, t_stack **b);

/* Moves the first node of B to the top of A. */
int pa(t_stack **lst_a ,t_stack **lst_b );

/* Moves the first node of A to the bottom of A. */
int ra(t_stack **lst);

/* Moves the last node of A to the top of A. */
int rra(t_stack **lst);

#endif