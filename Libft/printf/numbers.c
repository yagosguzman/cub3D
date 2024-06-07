/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   numbers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ysanchez <ysanchez@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:13:53 by gpinilla          #+#    #+#             */
/*   Updated: 2024/04/09 23:02:09 by ysanchez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_integer(int number, int *leng)
{
	unsigned int	nbr;

	nbr = number;
	if (number < 0)
	{
		write(1, "-", 1);
		(*leng)++;
		nbr = -number;
	}
	if (nbr >= 10)
		print_integer(nbr / 10, leng);
	ft_putchar_fd(nbr % 10 + '0', 1);
	(*leng)++;
}

void	print_integer_in_base(int number, int *leng)
{
	print_integer(number, leng);
}

void	print_unsigned_integer(unsigned int number, int *leng)
{
	if (number >= 10)
		print_unsigned_integer(number / 10, leng);
	ft_putchar_fd(number % 10 + '0', 1);
	(*leng)++;
}

void	print_low_hexadecimal(int number, int *leng)
{
	char			base[17];
	char			buffer[8];
	unsigned int	num_unsigned;
	int				remainder;
	int				i;

	i = 0;
	if (number == 0)
	{
		write(1, "0", 1);
		(*leng)++;
	}
	num_unsigned = (unsigned int)number;
	ft_strlcpy(base, "0123456789abcdef", 17);
	while (num_unsigned > 0)
	{
		remainder = num_unsigned % 16;
		buffer[i++] = base[remainder];
		num_unsigned /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		(*leng)++;
	}
}

void	print_up_hexadecimal(int number, int *leng)
{
	char				base[17];
	char				buffer[8];
	unsigned int		num_unsigned;
	int					remainder;
	int					i;

	i = 0;
	if (number == 0)
	{
		write(1, "0", 1);
		(*leng)++;
	}
	num_unsigned = (unsigned int)number;
	ft_strlcpy(base, "0123456789ABCDEF", 17);
	while (num_unsigned > 0)
	{
		remainder = num_unsigned % 16;
		buffer[i++] = base[remainder];
		num_unsigned /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		(*leng)++;
	}
}
