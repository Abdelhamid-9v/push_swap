/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   change_input.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:24:19 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 18:35:16 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static t_list	*ft_lstnew(int *content)
{
	t_list	*node;
	int		value;

	value = *content;
	node = (t_list *)malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->content = value;
	node->index = 0;
	node->next = NULL;
	return (node);
}

static t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

static void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*last;

	if (lst && new)
	{
		if (*lst)
		{
			last = ft_lstlast(*lst);
			last->next = new;
		}
		else
			*lst = new;
	}
}

t_list	*ft_change_input(int ac, char **av)
{
	int		i;
	int		value;
	t_list	*lst;
	t_list	*new_node;

	i = 0;
	lst = NULL;
	while (i < ac)
	{
		value = ft_l_atoi(av[i]);
		new_node = ft_lstnew(&value);
		if (!new_node)
		{
			free_stack(&lst);
			write(2, "Error\n", 6);
			exit(1);
		}
		ft_lstadd_back(&lst, new_node);
		i++;
	}
	return (lst);
}
