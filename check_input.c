/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 11:24:28 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/18 14:19:09 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_input(char *str)
{
	if (!str || !*str)
		return (0);
	if (*str == '-' || *str == '+')
		str++;
	while (*str)
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}

static int	has_duplicates(char **av, int ac)
{
	int	i;
	int	j;

	i = 0;
	while (i < ac - 1)
	{
		j = i + 1;
		while (j < ac)
		{
			if (ft_l_atoi(av[i]) == ft_l_atoi(av[j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	check_input(int ac, char **av)
{
	int	i;

	if (has_duplicates(av, ac))
		error_exit();
	i = 0;
	while (i < ac)
	{
		if (!is_valid_input(av[i]))
			error_exit();
		if (ft_l_atoi (av[i]) > 2147483647 || ft_l_atoi(av[i]) < -2147483648)
			error_exit();
		i++;
	}
}
