/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arozados <arozados@student.42madrid.com    +#+  +:+       +#+        */
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

/**
 * Node of a stack, implemented as a singly linked list.
 * The head of the list is the top of the stack.
 *
 * @value: Integer stored in this node.
 * @next:  Next node (the one below in the stack), or NULL at the bottom.
 */
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_stack;

/**
 * Result of find_best_move: the cheapest element of A to push to B.
 *
 * @idx_a:    Position of the chosen element in A (0 = top).
 * @target_b: Position in B that must be brought to the top before pb,
 *            so the pushed element lands in its correct place.
 */
typedef struct s_move
{
	int	idx_a;
	int	target_b;
}	t_move;

/**
 * Pair of rotation functions for one stack, so the same code
 * can operate on A (ra/rra) or on B (rb/rrb).
 *
 * @fwd: Rotates the stack upwards (top goes to the bottom): ra or rb.
 * @bwd: Rotates the stack downwards (bottom goes to the top): rra or rrb.
 */
typedef struct s_rot_fn
{
	void	(*fwd)(t_stack **);
	void	(*bwd)(t_stack **);
}	t_rot_fn;

/* Stack utilities */

/**
* Create the first node or add a new node at the end of the linked list
* @param lst list that will recieve a new node
* @param value number, which will be owned by the new node
* @return -1: it wasn't complete successfully or the index where it was add.
*
*/
ssize_t add_node(t_stack **lst,int value);

/* Returns the number of nodes in a stack. */
int		lstsize(t_stack *stack);

/**
 * Computes how many rotations are needed to bring the element at
 * `index` to the top, choosing the shorter direction.
 *
 * @param index  Position of the element (0 = top).
 * @param size   Number of elements in the stack.
 * @return       min(index, size - index): the cheapest number of rotations.
 */
int		rotate_cost(int index, int size);

/**
 * Finds the position of the largest value in a stack.
 * Precondition: `b` must not be NULL (its first value is read).
 *
 * @param b  Top node of the stack to search.
 * @return   Index of the maximum value (0 = top). On ties, the first one.
 */
int		max_index(t_stack *b);

/**
 * Finds the closest smaller neighbour of `value`: the largest value in
 * the stack that is still strictly smaller than `value`.
 *
 * @param b      Top node of the stack to search (may be NULL).
 * @param value  Value to compare against.
 * @return       Index of that neighbour (0 = top), or -1 if every value
 *               in the stack is greater than or equal to `value`.
 */
int		smaller_index(t_stack *b, int value);

/**
 * Decides which position of B must be on top before pushing `value`,
 * so B stays in descending (circular) order.
 *
 * @param b      Top node of stack B (may be NULL).
 * @param value  Value from A that is about to be pushed.
 * @return       0 if B is empty; the index of the smaller neighbour if one
 *               exists; otherwise the index of the maximum of B.
 */
int		target_b_index(t_stack *b, int value);

/**
 * Rotates a stack until the element at `index` is on top, using the
 * shortest direction (forward if index <= size - index, else backward).
 *
 * @param stack  Address of the stack head; modified by the rotations.
 * @param index  Position of the target element (0 = top).
 * @param size   Number of elements currently in the stack.
 * @param fn     Rotation functions to use: fn.fwd (ra/rb), fn.bwd (rra/rrb).
 * @return       Nothing. Emits the rotation operations as a side effect.
 */
void	move_to_top(t_stack **stack, int index, int size, t_rot_fn fn);

/**
 * Finds the cheapest element of A to push onto B. For each element the
 * cost is: rotations to bring it to the top of A + rotations to bring
 * its target position in B to the top of B. The first minimum wins.
 *
 * @param a       Top node of stack A.
 * @param b       Top node of stack B (may be NULL).
 * @param size_a  Number of elements in A.
 * @param size_b  Number of elements in B.
 * @return        A t_move with the chosen element's index in A (idx_a)
 *                and the index in B to bring to the top (target_b).
 */
t_move	find_best_move(t_stack *a, t_stack *b, int size_a, int size_b);

/* Sorting algorithms */

/**
* Sorts stack A using stack B as auxiliary storage. 
* @param a pointer to stack A
* @param b pointer to stack B
* @param operation_amount pointer to the number of operations that has been done in the process of sorting.
* @return pointer to the sorted stack A
*/
t_stack	*selection_sort(t_stack **a, t_stack **b, int *operation_amount);

/* Stack operations */

/**
 * Swaps the first two elements of stack A
 * @param lst a list
 * @return 0: fail (NULL params, less than two elements, etc) 1: success
 */
int		sa(t_stack **lst, int *operation_amount);

/**
 * Swaps the first two elements of stack B
 * @param lst a list
 * @return 0: fail (NULL params, less than two elements, etc) 1: success
 */
int		sb(t_stack **lst, int *operation_amount);

/**
 * Moves the first element of A to the first position of B
 * @param lst_a stack A
 * @param lst_b stack B
 * @return 0: fail (NULL params, empty A, etc) 1: success
 */
int		pb(t_stack **lst_a, t_stack **lst_b, int *operation_amount);

/**
 * Moves the first element of B to the first position of A
 * @param lst_a stack A
 * @param lst_b stack B
 * @return 0: fail (NULL params, empty B, etc) 1: success
 */
int pa(t_stack **lst_a ,t_stack **lst_b, int *operation_amount);

/**
 * Moves the first element to the last position
 * @param lst a list
 * @return 0: fail (NULL params, less than two elements, etc) 1: success
 */
int ra(t_stack **lst, int *operation_amount);

/**
 * The last element go to first position
 * @param lst a list
 * @return 0:fail (NULL params, its not the first element, etc) 1:sucess
 */
int rra(t_stack **lst, int *operation_amount);

/**
 * Moves the first element to the last position
 * @param lst a list
 * @return 0: fail (NULL params, less than two elements, etc) 1: success
 */
int		rb(t_stack **lst, int *operation_amount);

/**
 * Moves the last element to the first position.
 * @param lst a list
 * @return 0: fail (NULL params, less than two elements, etc) 1: success
 */
int		rrb(t_stack **lst, int *operation_amount);

/* Moves the last node of A to the top of A. */
void	rra(t_stack **a);

/* Moves the first node of B to the bottom of B. */
void	rb(t_stack **b);

/* Moves the last node of B to the top of B. */
void	rrb(t_stack **b);

#endif
