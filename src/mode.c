/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mode.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:42:53 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/19 00:01:30 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_readline.h>

void	raw_mode(t_rldata *data)
{
	struct termios	termios;

	tcgetattr(STDIN_FILENO, &termios);
	data->old_mode = termios;
	termios.c_lflag &= ~(ECHO | ICANON | ISIG);
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &termios);
	data->mode = termios;
}

void	restore_mode(t_rldata *data)
{
	tcsetattr(STDIN_FILENO, TCSAFLUSH, &(data->old_mode));
	data->mode = data->old_mode;
}
