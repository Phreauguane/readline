/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:28:14 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/19 00:32:29 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_readline.h>

t_rldata	data;

void	init_readline(void)
{
	if (data.init == 1)
		return ;
	ft_bzero(&data, sizeof(t_rldata));
	data.init = 0;
}

char	*ft_readline(char *input)
{
	init_readline();
	raw_mode(&data);
	ft_printf("%s", input);
	read_input(&data);
	restore_mode(&data);
	return (NULL);
}

void	clean_readline(void)
{
	ft_printf("coucou\n");
}