/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 15:14:01 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 15:14:02 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(char *str, int c)
{
	char *last;

	last = NULL;
	while (*str)
		if (*str++ == c)
			last = str - 1;
	if (!c)
		return (str);
	return (last);
}
