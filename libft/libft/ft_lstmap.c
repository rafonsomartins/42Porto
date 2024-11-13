/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ralves-e <ralves-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/19 18:58:59 by artuda-s          #+#    #+#             */
/*   Updated: 2024/04/23 18:25:31 by ralves-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*current;
	t_list	*head;

	node = NULL;
	head = NULL;
	while (lst != NULL)
	{
		current = ft_lstnew(f(lst->content));
		if (!current)
		{
			del(head);
			if (node)
				ft_lstclear(&node, del);
			return (NULL);
		}
		ft_lstadd_back(&node, current);
		if (!head)
			head = current;
		lst = lst->next;
	}
	return (head);
}

// #include "stdio.h"

// int main(void)
// {
// 	t_list *node = ft_lstnew("Hello, ");
// 	t_list *node2 = ft_lstnew("world!");
// 	ft_lstadd_back(&node, node2);
// 	t_list *res = ft_lstmap(node, (void *)printf, (void *)free);
// 	if (res)
// 		printf("%s\n", (char *)res->content);
// 	ft_lstclear(&res, (void *)free);
// 	ft_lstclear(&node, (void *)free);
// 	return (0);
// }
