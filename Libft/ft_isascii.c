/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:55:03 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/29 22:41:41 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isascii(int c)
{
	return (c >= 0 && c <= 127);
}

/*#include	<stdio.h>
#include	<ctype.h>

int	main(void)
{
	char	c;

	c = '0';
	if (ft_isascii(c))
		printf("%c is a digit", c);
	else
		printf("%c is not a digit", c);
	return (0);
}*/
