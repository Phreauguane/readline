/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:32:14 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/19 00:39:51 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_readline.h>

void	read_key(int fd, char *buff, int size)
{
	
}

void	read_input(t_rldata *data)
{
	char	*buff;
	char	c;

	buff = NULL;
	(void)data;
	c = '\0';
	while (c != '\n' && read(STDIN_FILENO, &c, 1))
	{
		buff = str_addc(buff, c);
		ft_printf("%c", c);
	}
	ft_printf(buff);
}
