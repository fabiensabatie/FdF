/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fsabatie <fsabatie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 11:44:55 by fsabatie          #+#    #+#             */
/*   Updated: 2017/11/11 01:47:54 by fsabatie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>
#include "libft.h"

/*
** Prend en paramètre l’adresse d’un pointeur sur un maillon et libère
** la mémoire de ce maillon et celle de tous ses successeurs l’un
** après l’autre avec del et free(3). Pour terminer, le pointeur sur
** le premier maillon maintenant libéré doit être mis à NULL (de manière
** similaire à la fonction ft_memdel de la partie obligatoire).
*/

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *next;

	lst = *alst;
	while (lst)
	{
		next = lst->next;
		del(lst->content, lst->content_size);
		free(lst);
		lst = next;
	}
	*alst = NULL;
}
