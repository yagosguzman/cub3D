/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:54:37 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/29 22:39:15 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalnum(int c)
{
	if ((c >= '\60' && c <= '\71') || (c >= '\101' && c <= '\132')
		|| (c >= '\141' && c <= '\172'))
		return (c);
	return (0);
}
/*
#include	<stdio.h>
#include	<ctype.h>

int	main(void)
{
	char	c;

	c = '0';
	if (isalnum(c))
		printf("%c is an alnum", c);
	else
		printf("%c is not an alnum", c);
	return (0);
}*/
