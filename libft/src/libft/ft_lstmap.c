/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 20:30:14 by ggalon            #+#    #+#             */
/*   Updated: 2023/11/14 17:59:36 by ggalon           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*temp;
	void	*content;

	if (!lst || !f || !del)
		return (NULL);
	content = f(lst->content);
	new_list = ft_lstnew(content);
	if (!new_list)
		return ((*del)(content), NULL);
	lst = lst->next;
	while (lst)
	{
		content = f(lst->content);
		temp = ft_lstnew(content);
		if (!temp)
			return ((*del)(content), ft_lstclear(&new_list, del), NULL);
		ft_lstadd_back(&new_list, temp);
		lst = lst->next;
	}
	return (new_list);
}
