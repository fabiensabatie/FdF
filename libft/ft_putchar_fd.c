/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/08 23:41:00 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/08 23:41:02 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

/*
** Ecrit le caractère c sur le descripteur de fichier fd.
*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
