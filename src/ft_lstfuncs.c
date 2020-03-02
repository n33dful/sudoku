/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cdarci <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/06 16:10:12 by cdarci            #+#    #+#             */
/*   Updated: 2020/02/06 16:10:17 by cdarci           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sudoku.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*list = (t_list *)malloc(sizeof(t_list));

	if (!list)
		return (NULL);
	else if (content)
	{
		if (!(list->content = malloc(content_size)))
		{
			free(list);
			return (NULL);
		}
		memcpy(list->content, content, content_size);
	}
	else
		list->content = NULL;
	list->content_size = list->content ? content_size : 0;
	list->next = NULL;
	return (list);
}

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list	*point = (*alst);

	if (!point)
	{
		(*alst) = new;
		return ;
	}
	while (point->next)
		point = point->next;
	point->next = new;
}

void	ft_celldel(void *content, size_t content_size)
{
	if (content_size > 0 && content)
	{
		free(content);
		content = NULL;
	}
}

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	if (alst && (*alst) && del)
	{
		while ((*alst))
		{
			current = (*alst);
			del(current->content, current->content_size);
			(*alst) = (*alst)->next;
			free(current);
			current = NULL;
		}
		(*alst) = NULL;
	}
}