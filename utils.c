/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/23 14:27:02 by ayoakouh          #+#    #+#             */
/*   Updated: 2025/07/02 12:54:53 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	restart_setting_term(void)
{
	struct termios	term;

	tcgetattr(STDIN_FILENO, &term);
	term.c_lflag |= ECHOCTL;
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	desable_echo_term(void)
{
	struct termios	term;

	tcgetattr(1, &term);
	term.c_lflag &= ~(ECHOCTL);
	tcsetattr(STDIN_FILENO, TCSANOW, &term);
}

void	loop_helper(char	*preprocessed_input,
			t_shell_var *state, int *status)
{
	t_token	*token_list;

	token_list = create_token_list(preprocessed_input);
	process_tokens(token_list, state, status);
	tcsetattr(1, TCSANOW, &state->infos);
}

char	*path(void)
{
	char	*name;

	name = random_dir();
	while (1)
	{
		if (access(name, F_OK) == -1)
		{
			free(name);
			name = random_dir();
		}
		else if (access(name, F_OK) == 0
			&& access(name, W_OK | X_OK | R_OK) == 0)
			break ;
		else
		{
			free(name);
			name = random_dir();
		}
	}
	return (name);
}

char	*file_name(void)
{
	char	*name;

	name = random_file_name();
	while (1)
	{
		if (access(name, F_OK) == 0)
		{
			free(name);
			name = random_file_name();
		}
		else if (access(name, F_OK) == -1)
			break ;
	}
	return (name);
}
