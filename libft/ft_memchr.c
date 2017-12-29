/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 12:04:14 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 12:04:16 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memchr(void *s, int c, size_t n)
{
	unsigned char	*str;
	unsigned char	tofind;

	str = (unsigned char*)s;
	tofind = (unsigned char)c;
	while (n--)
		if (*str++ == tofind)
			return (str - 1);
	return (NULL);
}
