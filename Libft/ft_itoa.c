/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:31:30 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:26:43 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*Utilizando malloc(3), genera una string que
represente el valor entero recibido como argumento.
Los números negativos tienen que gestionarse.*/

static size_t	ft_count_digits(int n)
{
	size_t	count;

	count = 0;
	while (n)
	{
		n /= 10;
		count++;
	}
	return (count);
}

static void	ft_write_nbr(char *dest, unsigned int nbr)
{
	if (nbr < 10)
		*dest = nbr + '0';
	else
	{
		*dest = nbr % 10 + '0';
		ft_write_nbr(dest - 1, nbr / 10);
	}
}

char	*ft_itoa(int n)
{
	char			*s;
	unsigned int	nbr;
	int				digits;

	nbr = n;
	if (n == 0)
		return (ft_strdup("0"));
	if (n < 0)
		digits = ft_count_digits(n) + 1;
	else
		digits = ft_count_digits(n);
	s = (char *)malloc((digits + 1) * sizeof(char));
	if (!s)
		return (0);
	if (n < 0)
	{
		ft_write_nbr((s + digits - 1), -nbr);
		*s = '-';
	}
	else
		ft_write_nbr((s + digits - 1), nbr);
	s[digits] = '\0';
	return (s);
}

/*
int	main(void)
{
	int 	n;
	char	*s;

	n = -234777765;
	s = ft_itoa(n);
	printf("%s",s);
	return(0);
}*/
