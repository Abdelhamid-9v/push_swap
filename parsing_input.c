/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 17:33:48 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/17 13:19:46 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	calculate_total_length(int ac, char **av)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	while (++i < ac)
		len += ft_strlen(av[i]) + 1;
	return (len);
}

static char	*initialize_str(int len)
{
	char	*str;

	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[0] = '\0';
	return (str);
}

static char	*append_arg(char *str, char *arg)
{
	char	*temp;

	temp = ft_strjoin(str, arg);
	free(str);
	str = temp;
	temp = ft_strjoin(str, " ");
	free(str);
	str = temp;
	return (str);
}

static char	*concat_args(int ac, char **av)
{
	int		i;
	char	*str;
	int		len;

	len = calculate_total_length(ac, av);
	str = initialize_str(len);
	if (!str)
		return (NULL);
	i = 0;
	while (++i < ac)
	{
		if (av[i][0] != '\0')
			str = append_arg(str, av[i]);
		else
		{
			free(str);
			error_exit();
		}
	}
	return (str);
}

char	**handling_arg(int ac, char **av)
{
	char	*str;
	char	**arg;

	if (ac < 2)
		return (NULL);
	str = concat_args(ac, av);
	if (!str)
		return (NULL);
	arg = ft_split(str, ' ');
	free(str);
	if (!arg)
		return (NULL);
	return (arg);
}
