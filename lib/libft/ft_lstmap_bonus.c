/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_lstmap_bonus.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: chartema <chartema@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/08/08 14:32:01 by chartema      #+#    #+#                 */
/*   Updated: 2022/08/08 14:32:02 by chartema      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newlist;
	t_list	*temp;

	if (!lst)
		return (NULL);
	newlist = ft_lstnew(f(lst -> content));
	if (!newlist)
		return (NULL);
	temp = newlist;
	while (lst -> next != NULL)
	{
		lst = lst -> next;
		newlist -> next = ft_lstnew(f(lst -> content));
		if (newlist -> next == NULL)
		{
			ft_lstclear(&temp, del);
			return (NULL);
		}
		newlist = newlist -> next;
	}
	return (temp);
}
