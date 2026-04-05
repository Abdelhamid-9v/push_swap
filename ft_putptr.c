/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:52:15 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/12 15:41:58 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putptr(unsigned long ptr, int *count)
{
	if (ptr == 0)
	{
		write(1, "0x0", 3);
		*count += 3;
		return ;
	}
	write(1, "0x", 2);
	*count += 2;
	ft_puthex(ptr, 0, count);
}
