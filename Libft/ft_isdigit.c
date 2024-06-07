/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vasko <vasko@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 19:50:49 by gpinilla          #+#    #+#             */
/*   Updated: 2023/08/29 22:41:53 by vasko            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
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
	if (ft_isdigit(c))
		printf("%c is a digit", c);
	else
		printf("%c is not a digit", c);
	return (0);
}*/
