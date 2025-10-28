/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: alejmart <alejmart>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/12 04:22:35 by alejmart          #+#    #+#             */
/*   Updated: 2025/10/12 04:22:36 by alejmart         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list_head;
	t_list	*new_node;
	void	*mapped_content;

	if (!f || !del)
		return (NULL);
	new_list_head = NULL;
	while (lst)
	{
		mapped_content = f(lst->content);
		new_node = ft_lstnew(mapped_content);
		if (!new_node)
		{
			del(mapped_content);
			ft_lstclear(&new_list_head, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list_head, new_node);
		lst = lst->next;
	}
	return (new_list_head);
}
