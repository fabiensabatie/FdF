/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 20:54:26 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/07 20:54:27 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

char		*ft_strdup(char *src)
{
	int		string_length;
	char	*cpy;

	string_length = ft_strlen(src);
	if (!(cpy = (char*)malloc(string_length + 1)))
		return (NULL);
	while (*src)
		*cpy++ = *src++;
	*cpy = '\0';
	return (cpy - string_length);
}
