/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 17:10:30 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 17:10:33 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t needle_size;
	size_t counter;
	size_t i;

	needle_size = (size_t)ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return (haystack);
	while (haystack[i] && len--)
	{
		counter = 0;
		while (needle[counter] == haystack[i++] && counter <= len)
			if (++counter == needle_size)
				return (&haystack[i - counter]);
		i -= counter;
	}
	return (NULL);
}
