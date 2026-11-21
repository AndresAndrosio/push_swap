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
#include <limits.h>
typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	struct s_stack	*before;
}	t_stack;

/* arg utilities*/

/**
 * Indicate whether the received arguments are valid.
 * Print 'Error' when its necessary
 * @return 1: if everything is right. 0: if something has gone wrong.
 */
int check_arg(int argc,char *argv[]);

t_stack **parser(int argc,char *argv[],t_stack **a);
/**
 * Convert a string to a long integer.
 * @param begin_at: pointer to the beginning of the string
 * @param end_at: pointer to the next character after the last character of the string
 * @return long: the converted long integer
 */
long strtolong(char *begin_at,char *end_at);

/**
 * this function check if argv contain only spaces or is empty
 * @param argc: amount of arguments
 * @param argv: arguments
 * @param i_arg: the index of the argument to start checking
 * @param i_char: the index of the character to start checking
 * @return 1: argv contain only spaces or is empty, 0: argv contain
 */
int find_num_in_argv(char *argv[],long num,int i_arg,int i_char);

/** 
 * Check if argv contain prohibited characters.
 * @param argc: amount of arguments
 * @param argv: arguments
 * @return 1: argv contain prohibited characters, 0: argv contain only allowed characters
 */
int contain_prohibit_char(int argc,const char *argv[]);

/**
 * Check if argv contain wrong numbers like: - -1231-2, - +21343, + +-21314, --1231, -+21343, ++-21314 + -
 * @param argc: amount of arguments
 * @param argv: arguments
 * @return char*: when argv contain wrong numbers like: - -1231-2 - +21343 + +-21314 --1231 -+21343 ++-21314 + -
 * NULL: when argv contain good numbers like: -1234 or +1234 [no space and only one sign and before sign atleast one space firtst element is not included]
 */
char * wrong_number_format(int argc,char *argv[]);

/**
 * check if argv contain only int numbers.
 * @return 1: argv contain only int numbers, 0: argv contain a number bigger than INT_MAX or smaller than INT_MIN
 */
int have_only_int_nums(int argc,char *argv[]);
/**
 * Check if argv contain duplicated numbers.
 * @param argc: amount of arguments
 * @param argv: arguments
 * @return 1: argv contain duplicated numbers, 0: argv contain unique numbers
 */
int number_duplicated(int argc,char *argv[]);
/**
 * Check if argv contain only empty arguments.
 * @param argc: amount of arguments
 * @param argv: arguments
 * @return 1: argv contain only empty arguments, 0: argv contain at least one non-empty argument
 */
int is_empty_arg(int argc,char *argv[]);

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