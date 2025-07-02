/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_shlvl_node.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anel-men <anel-men@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 15:06:02 by anel-men          #+#    #+#             */
/*   Updated: 2025/07/02 12:51:11 by anel-men         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

void	add_shlvl_node(t_env *env)
{
	t_env	*new_node;
	t_env	*last_node;

	new_node = create_shlvl_node();
	if (!new_node)
		return ;
	last_node = find_last_node(env);
	last_node->next = new_node;
}

void	change_space_helper(char *str, int	*quote_state, int *i)
{
	if (str[*i] >= 9 && str[*i] <= 13 && *quote_state == 0)
		str[*i] = ' ';
}

int	check_if_there_only_qoutes(char *str)
{
	int	i;
	int	count;
	int	lent;

	i = 0;
	count = 0;
	lent = ft_strlen(str);
	while (str && str[i])
	{
		if (str[i] == '\'' || str[i] == '\"')
			count++;
		i++;
	}
	if (lent == count)
		return (1);
	return (0);
}
