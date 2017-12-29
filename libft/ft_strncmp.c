/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 21:23:10 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 21:23:12 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

int	ft_strncmp(char *s1, char *s2, size_t n)
{
	unsigned char *first;
	unsigned char *second;

	first = (unsigned char*)s1;
	second = (unsigned char*)s2;
	if (!n)
		return (0);
	while ((*first == *second) && *first && *second && n-- > 1)
	{
		first++;
		second++;
	}
	return (*first - *second);
}
