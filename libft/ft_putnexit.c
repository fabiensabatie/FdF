/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnexit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/08 23:36:11 by fsabatie          #+#    #+#             */
/*   Updated: 2017/12/17 14:08:33 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

/*
** Affiche la chaine s sur la sortie standard suivi d’un ’\n’.
*/

void	ft_putnexit(char const *s)
{
	ft_putstr((char *)s);
	ft_putchar('\n');
	exit(1);
}
