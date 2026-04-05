/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:45:03 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/12 15:41:50 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_puthex(unsigned long n, int uppercase, int *count)
{
	char	*base_upper;
	char	*base_lower;
	char	*base;

	base_upper = "0123456789ABCDEF";
	base_lower = "0123456789abcdef";
	if (uppercase)
		base = base_upper;
	else
		base = base_lower;
	if (n >= 16)
		ft_puthex(n / 16, uppercase, count);
	ft_putchar(base[n % 16], count);
}
