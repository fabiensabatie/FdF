/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 21:15:58 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/07 21:15:59 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *str, int c, size_t len)
{
	int				i;
	unsigned char	*string;

	i = 0;
	string = (unsigned char*)str;
	while (len--)
		string[i++] = c;
	return (string);
}
