/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readline.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jde-meo <jde-meo@student.42perpignan.fr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 23:27:53 by jde-meo           #+#    #+#             */
/*   Updated: 2024/03/19 00:38:19 by jde-meo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef	FT_READLINE
# define FT_READLINE

# include <termios.h>
# include <unistd.h>
# include <libft.h>
# define DEL				127
# define BS					8
# define DEL_ID				0
# define UP_KEY				"\033\133\101"
# define UP_KEY_ID			1
# define DOWN_KEY			"\033\133\102"
# define DOWN_KEY_ID		2
# define RIGHT_KEY			"\033\133\103"
# define RIGHT_KEY_ID		3
# define LEFT_KEY			"\033\133\104"
# define LEFT_KEY_ID		4
# define LF					10
# define LF_ID				5
# define ETX				3
# define ETX_ID				6
# define EOT				4
# define EOT_ID				7
# define FF					12
# define CLR_SCREEN_ID		8
# define WORD_RIGHT			"\033\133\61\73\65\103"
# define WORD_RIGHT_ID		9
# define WORD_LEFT			"\033\133\61\73\65\104"
# define WORD_LEFT_ID		10
# define LINE_START			1
# define HOME_KEY			"\033\133\110"
# define LINE_START_ID		11
# define LINE_END			5
# define END_KEY			"\033\133\106"
# define LINE_END_ID		12
# define CUT_WORD_RIGHT		"\033\144"
# define CUT_WORD_RIGHT_ID	13
# define CUT_WORD_LEFT		23
# define CUT_WORD_LEFT_ID	14
# define CUT_LINE_START		21
# define CUT_LINE_START_ID	15
# define CUT_LINE_END		11
# define CUT_LINE_END_ID	16
# define PASTE				25
# define PASTE_ID			17
# define SUPPR_KEY			"\033\133\63\176"
# define SUPPR_ID			18

# define CURSOR_RIGHT		"\033[1C"
# define CURSOR_LEFT		"\033[1D"

# define CLEAR_SCREEN		"\033[2J\033[H"

typedef struct s_rldata
{
	int				init;
	struct termios	old_mode;
	struct termios	mode;
	char			*buffer;
}	t_rldata;

/*	FT_READLINE.C		*/
char	*ft_readline(char *input);
void	clean_readline(void);

/*	GET_INPUT.C			*/
void	read_input(t_rldata *data);

/*	MODE.C				*/
void	raw_mode(t_rldata *data);
void	restore_mode(t_rldata *data);

#endif