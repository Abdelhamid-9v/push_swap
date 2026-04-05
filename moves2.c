/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 09:47:17 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/13 09:51:46 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_list **stacka, t_list **stackb, char *op)
{
	reverse_rotate(stacka, "rra");
	reverse_rotate(stackb, "rrb");
	ft_printf("%s\n", op);
}
