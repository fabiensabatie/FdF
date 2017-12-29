/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 16:00:11 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 16:00:13 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

char	*ft_strstr(char *haystack, char *needle)
{
	size_t needle_size;
	size_t counter;
	size_t i;

	needle_size = (size_t)ft_strlen(needle);
	i = 0;
	if (*needle == '\0')
		return (haystack);
	while (haystack[i])
	{
		counter = 0;
		while (needle[counter] == haystack[i++])
			if (++counter == needle_size)
				return (&haystack[i - counter]);
		i -= counter;
	}
	return (NULL);
}
