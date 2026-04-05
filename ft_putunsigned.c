/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putunsigned.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:42:25 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/12 15:42:10 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_putunsigned(unsigned int n, int *count)
{
	if (n >= 10)
	{
		ft_putunsigned(n / 10, count);
	}
	ft_putchar(n % 10 + '0', count);
}
