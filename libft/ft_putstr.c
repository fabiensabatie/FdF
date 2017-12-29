/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/07 19:03:59 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/07 19:04:03 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

/*
** Affiche la chaine s sur la sortie standard.
*/

void	ft_putstr(char *str)
{
	if (str)
		write(1, str, ft_strlen(str));
}
