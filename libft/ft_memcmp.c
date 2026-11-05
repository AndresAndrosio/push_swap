/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 17:41:39 by jcervera          #+#    #+#             */
/*   Updated: 2026/10/29 18:06:18 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*block1;
	const unsigned char	*block2;
	size_t				i;

	block1 = (const unsigned char *)s1;
	block2 = (const unsigned char *)s2;
	i = 0;
	while (i < n)
	{
		if (block1[i] != block2[i])
			return (block1[i] - block2[i]);
		i++;
	}
	return (0);
}
