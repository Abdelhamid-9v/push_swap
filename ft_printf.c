/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abel-had <abel-had@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:56:09 by abel-had          #+#    #+#             */
/*   Updated: 2025/01/12 15:41:20 by abel-had         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_valid_specifier(char specifier)
{
	return (specifier == 'c' || specifier == 's' || specifier == 'd'
		||specifier == 'i' || specifier == 'u' || specifier == 'x'
		||specifier == 'X' || specifier == 'p' || specifier == '%');
}

static int	process(char specifier, va_list args)
{
	int	count;

	count = 0;
	if (specifier == 'c')
		ft_putchar(va_arg(args, int), &count);
	else if (specifier == 's')
		ft_putstr(va_arg(args, char *), &count);
	else if (specifier == 'd' || specifier == 'i')
		ft_putnbr(va_arg(args, int), &count);
	else if (specifier == 'u')
		ft_putunsigned(va_arg(args, unsigned int), &count);
	else if (specifier == 'x')
		ft_puthex(va_arg(args, unsigned int), 0, &count);
	else if (specifier == 'X')
		ft_puthex(va_arg(args, unsigned int), 1, &count);
	else if (specifier == 'p')
		ft_putptr(va_arg(args, unsigned long), &count);
	else if (specifier == '%')
		ft_putchar('%', &count);
	else
		return (0);
	return (count);
}

static int	handle_format(const char **format, va_list args, int *count)
{
	int	temp;

	if (write(1, "", 0) == -1)
		return (-1);
	while (**format != '\0' )
	{
		if (**format == '%')
		{
			(*format)++;
			if (**format == '\0')
				break ;
			temp = process(**format, args);
			if (temp == 0 && !is_valid_specifier(**format))
				ft_putchar(**format, count);
			else
				*count += temp;
		}
		else if (**format != '%')
			ft_putchar(**format, count);
		(*format)++;
	}
	return (1);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		a;

	count = 0;
	va_start(args, format);
	a = handle_format(&format, args, &count);
	va_end(args);
	if (a == -1)
		return (-1);
	return (count);
}
