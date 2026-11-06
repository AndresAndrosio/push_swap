/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jcervera <jcervera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/22 20:43:20 by jcervera          #+#    #+#             */
/*   Updated: 2026/09/22 20:49:22 by jcervera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

unsigned int	ft_strlcat(char *dest, char *src, unsigned int size)
{
	unsigned int	dest_length;
	unsigned int	i;
	unsigned int	src_length;

	src_length = 0;
	dest_length = 0;
	while (dest[dest_length] != '\0' && dest_length < size)
		dest_length++;
	while (src[src_length] != '\0')
		src_length++;
	if (dest_length >= size)
		return (size + src_length);
	i = 0;
	while ((i + dest_length < size - 1) && src[i] != '\0')
	{
		dest[i + dest_length] = src[i];
		i++;
	}
	dest[i + dest_length] = '\0';
	return (dest_length + src_length);
}
