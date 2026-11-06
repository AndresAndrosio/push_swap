/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/07 13:49:13 by jcervera          #+#    #+#             */
/*   Updated: 2026/10/07 13:53:47 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	length;
	size_t	i;
	int		last;

	i = 0;
	last = -1;
	length = ft_strlen(s);
	if ((unsigned char)c == '\0')
		return ((char *)&s[length]);
	while (i < length)
	{
		if (s[i] == (unsigned char)c)
			last = (int)i;
		i++;
	}
	if (last == -1)
		return (NULL);
	return ((char *)&s[last]);
}
