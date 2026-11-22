/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   selection_sort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:28 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/10 00:00:00 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

static void	unload_b(t_stack **a, t_stack **b)
{
	t_rot_fn	fn;
	int			size_b;

	size_b = lstsize(*b);
	if (size_b > 0)
	{
		fn.fwd = rb;
		fn.bwd = rrb;
		move_to_top(b, max_index(*b), size_b, fn);
	}
	while (*b)
		pa(a, b);
}

t_stack	*selection_sort(t_stack **a, t_stack **b)
{
	int			size_a;
	int			size_b;
	t_move		best;
	t_rot_fn	fn;

	while (*a)
	{
		size_a = lstsize(*a);
		size_b = lstsize(*b);
		best = find_best_move(*a, *b, size_a, size_b);
		fn.fwd = ra;
		fn.bwd = rra;
		move_to_top(a, best.idx_a, size_a, fn);
		fn.fwd = rb;
		fn.bwd = rrb;
		move_to_top(b, best.target_b, size_b, fn);
		pb(a, b);
	}
	unload_b(a, b);
	return (*a);
}
