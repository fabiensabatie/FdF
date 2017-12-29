/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:38:22 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/07 21:38:24 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, void *src, int c, size_t n)
{
	int				i;
	unsigned char	*dest;
	unsigned char	*source;

	i = 0;
	dest = (unsigned char*)dst;
	source = (unsigned char*)src;
	while (n--)
	{
		dest[i] = source[i];
		if (source[i] == (unsigned char)c)
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
