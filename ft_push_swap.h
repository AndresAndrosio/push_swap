/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arozados <arozados@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:55 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/05 21:33:21 by jcervera         ###   ########.fr       */
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

/* Returns a pointer to the node with the smallest value. */
t_stack	*find_min(t_stack *stack);

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

#endif