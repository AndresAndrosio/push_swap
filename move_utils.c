/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/10 00:00:00 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/10 00:00:00 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_push_swap.h"

void	move_to_top(t_stack **stack, int index, int size, t_rot_fn fn)
{
	int	back;

	back = size - index;
	if (index <= back)
	{
		while (index-- > 0)
			fn.fwd(stack);
	}
	else
	{
		while (back-- > 0)
			fn.bwd(stack);
	}
}

t_move	find_best_move(t_stack *a, t_stack *b, int size_a, int size_b)
{
	t_stack	*cur;
	int		idx;
	int		cost;
	int		best_cost;
	t_move	best;

	cur = a;
	idx = 0;
	best_cost = -1;
	best.idx_a = 0;
	best.target_b = 0;
	while (cur)
	{
		cost = rotate_cost(idx, size_a);
		cost += rotate_cost(target_b_index(b, cur->value), size_b);
		if (best_cost == -1 || cost < best_cost)
		{
			best_cost = cost;
			best.idx_a = idx;
			best.target_b = target_b_index(b, cur->value);
		}
		cur = cur->next;
		idx++;
	}
	return (best);
}
