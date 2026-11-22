/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:55 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/10 00:00:00 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PUSH_SWAP_H
# define FT_PUSH_SWAP_H

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

/* A chosen move: index in a to bring to top, target slot in b. */
typedef struct s_move
{
	int	idx_a;
	int	target_b;
}	t_move;

/* The two rotation directions (forward/backward) for a given stack. */
typedef struct s_rot_fn
{
	void	(*fwd)(t_stack **);
	void	(*bwd)(t_stack **);
}	t_rot_fn;

/* Stack utilities */

/* Returns the number of nodes in a stack. */
int		lstsize(t_stack *stack);

/* Rotation cost (shortest direction) to bring `index` to the top. */
int		rotate_cost(int index, int size);

/* Index of the node holding the largest value in b. */
int		max_index(t_stack *b);

/* Index of the largest node smaller than `value`, or -1 if none. */
int		smaller_index(t_stack *b, int value);

/* Index in b where `value` should be brought to keep b's rotated
** descending run property once it is pushed. */
int		target_b_index(t_stack *b, int value);

/* Rotates `stack` (shortest direction) to bring `index` to the top. */
void	move_to_top(t_stack **stack, int index, int size, t_rot_fn fn);

/* Cheapest node of `a` to send to b: its index and b's target slot. */
t_move	find_best_move(t_stack *a, t_stack *b, int size_a, int size_b);

/* Sorting algorithms */

/* Sorts stack A using stack B as auxiliary storage. */
t_stack	*selection_sort(t_stack **a, t_stack **b);

/* Stack operations */

/* Moves the first node of A to the top of B. */
void	pb(t_stack **a, t_stack **b);

/* Moves the first node of B to the top of A. */
void	pa(t_stack **a, t_stack **b);

/* Moves the first node of A to the bottom of A. */
void	ra(t_stack **a);

/* Moves the last node of A to the top of A. */
void	rra(t_stack **a);

/* Moves the first node of B to the bottom of B. */
void	rb(t_stack **b);

/* Moves the last node of B to the top of B. */
void	rrb(t_stack **b);

#endif
