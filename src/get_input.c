/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_input.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:32:14 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/19 13:31:14 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_readline.h>

void	read_esc(char **buff)
{
	char	c;
	int		ret;

	c = '\0';
	ret = read(STDIN_FILENO, &c, 1);
	while (ret == 0)
		ret = read(STDIN_FILENO, &c, 1);
	if (c != '\133')
		return ;
	ret = read(STDIN_FILENO, &c, 1);
	while (ret == 0)
		ret = read(STDIN_FILENO, &c, 1);
	if (c != '\133')
		return ;
	(void)ret;
	(void)buff;
}

void	read_key(char **buff)
{
	char	c;
	int		ret;

	ret = read(STDIN_FILENO, &c, 1);
	while (c != '\n' && ret > 0)
	{
		if (c == '\033')
			read_esc(buff);
		else
		{
			*buff = str_addc(*buff, c);
			ft_printf("%c", c);
		}
		ret = read(STDIN_FILENO, &c, 1);
	}
}

void	read_input(t_rldata *data)
{
	char	*buff;

	buff = NULL;
	(void)data;
	read_key(&buff);
	ft_printf("\'%s\'", buff);
}
