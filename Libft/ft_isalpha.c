/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:49:45 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/29 22:39:26 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c >= '\101' && c <= '\132') || (c >= '\141' && c <= '\172'))
		return (c);
	return (0);
}
/*
#include	<stdio.h>
#include	<ctype.h>

int	main(void)
{
	char	c;

	c = ' ';
	if (ft_isalpha(c))
		printf("%c is an alphabet", c);
	else
		printf("%c is not an alphabet", c);
	return (0);
}*/
