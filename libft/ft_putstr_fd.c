/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:43:28 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 23:43:29 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** Ecrit la chaine s sur le descripteur de fichier fd.
*/

void	ft_putstr_fd(char const *s, int fd)
{
	if (s)
		write(fd, (char*)s, ft_strlen((char*)s));
}
