/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gpinilla <gpinilla@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/31 17:32:46 by gpinilla          #+#    #+#             */
/*   Updated: 2023/06/09 17:05:15 by gpinilla         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*Envía el carácter ’c’ al file descriptor
especificado.*/

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
