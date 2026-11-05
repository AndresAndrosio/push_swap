/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_push_swap.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/05 20:05:55 by jcervera          #+#    #+#             */
/*   Updated: 2026/11/05 20:34:52 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP
# define PUSH_SWAP

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include "libft.h"


typedef struct s_list
{
    int             value;
    struct s_stack  *next;
}   t_list;

t_list	selection_sort(t_list a, t_list b);
void	sa(t_list a);
void	pa(t_list a);
void	ra(t_list a);

#endif