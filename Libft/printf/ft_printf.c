/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:13:30 by gpinilla          #+#    #+#             */
/*   Updated: 2024/04/09 23:01:59 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_conversions(char format, va_list args, int *leng)
{
	if (format == '%')
	{
		(*leng)++;
		return (write(1, "%", 1));
	}
	else if (format == 'd')
		print_integer(va_arg(args, int), leng);
	else if (format == 'i')
		print_integer_in_base(va_arg(args, int), leng);
	else if (format == 'u')
		print_unsigned_integer(va_arg(args, unsigned int), leng);
	else if (format == 'x')
		print_low_hexadecimal(va_arg(args, int), leng);
	else if (format == 'X')
		print_up_hexadecimal(va_arg(args, int), leng);
	else if (format == 'p')
		print_direc_memory(va_arg(args, void *), leng);
	else if (format == 'c')
		print_character(va_arg(args, int), leng);
	else if (format == 's')
		print_string(va_arg(args, char *), leng);
	else
		return (0);
	return (1);
}

int	ft_printf(char const *format, ...)
{
	va_list	args;
	int		leng;

	leng = 0;
	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			print_conversions(*format, args, &leng);
		}
		else
			leng += write(1, format, 1);
		format++;
	}
	va_end(args);
	return (leng);
}
