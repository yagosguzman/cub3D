/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:55:30 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/29 22:42:01 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if ((c >= '\40' && c <= '\77') || (c >= '\100' && c <= '\176'))
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
	if (ft_isprintc))
		printf("%c is an alphabet", c);
	else
		printf("%c is not an alphabet", c);
	return (0);
}*/
