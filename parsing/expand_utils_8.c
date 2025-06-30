/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils_8.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ayoakouh <ayoakouh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/16 15:08:09 by anel-men          #+#    #+#             */
/*   Updated: 2025/06/29 16:40:01 by ayoakouh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

int	exp_hp(t_exp_helper *expand)
{
	if (expand && expand->original && expand->i > 0
		&& expand->original[expand->i] != '\0'
		&& expand->original[expand->i + 1] != '\0'
		&& expand->original[expand->i - 1] == '\"'
		&& expand->original[expand->i] == '$'
		&& expand->original[expand->i + 1] == '\"')
		return (0);
	return (1);
}

int	expand_handle_helper1(t_exp_helper *expand,
			t_env *env, int pipe_out, int last_node)
{
	char	*var;
	int		extracting;
	int		res_adding_var;

	var = NULL;
	if (exp_hp(expand) == 0)
		return (0);
	if (expand->original[expand->i] == '$' && expand->quote_state != 1)
	{
		expand->i++;
		extracting = extracting_the_key_value(expand,
				env, pipe_out, last_node);
		if (extracting == 0)
			return (0);
		if (expand->var_value)
		{
			res_adding_var = adding_var_value(expand);
			if (res_adding_var == 0)
				return (0);
		}
		else if (extracting == 1)
			return (1);
		return (1);
	}
	return (0);
}

int	process_string_loop(t_exp_helper *expand, t_env *env,
		t_add_int *two_number)
{
	while (expand->original[expand->i])
	{
		if (!expand_handle_helper0(expand) && !expand_handle_helper1(expand,
				env, two_number->number_2, two_number->number_3))
		{
			if (!ensure_buffer_space(expand, 1))
			{
				free(expand->expanded);
				expand->expanded = NULL;
				return (0);
			}
			expand->expanded[expand->j++] = expand->original[expand->i++];
		}
	}
	return (1);
}
