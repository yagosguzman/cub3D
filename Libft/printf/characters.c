/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   characters.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 20:14:10 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/31 16:26:39 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	print_character(int c, int *leng)
{
	char	character;

	character = (char)c;
	write(1, &character, 1);
	(*leng)++;
}

void	print_string(char *s, int *leng)
{
	if (!s)
		s = "(null)";
	while (*s)
	{
		write(1, s, 1);
		s++;
		(*leng)++;
	}
}

void	print_hexadecimal_memory(unsigned long int num, int *leng)
{
	char	base[17];
	char	buffer[17];
	int		i;
	int		remainder;

	i = 0;
	ft_strlcpy(base, "0123456789abcdef", 17);
	while (num > 0)
	{
		remainder = num % 16;
		buffer[i++] = base[remainder];
		num /= 16;
	}
	while (--i >= 0)
	{
		write(1, &buffer[i], 1);
		(*leng)++;
	}
}

void	print_direc_memory(void *ptr, int *leng)
{
	unsigned long int	memory_number;

	if (ptr == NULL)
	{
		write(1, "0x0", 3);
		(*leng) += 3;
		return ;
	}
	memory_number = (unsigned long int)ptr;
	(*leng) += write(1, "0x", 2);
	print_hexadecimal_memory(memory_number, leng);
}
