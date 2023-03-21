/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/10 19:18:27 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/21 14:26:53 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Compare type et chaque cmd->type en parcourant cmd->token
// Return 1 si cmd->type == type, sinon 0
int	is_token(t_cmd *cmd, int type)
{
	int	i;

	i = 0;
	if (!cmd->token)
		return (0);
	while (cmd->token[i])
	{
		if (cmd->type[i] == type)
			return (1);
		i++;
	}
	return (0);
}

// Return 1 si la commande avant cmd->index == index est une redirection out
// Sinon return 0
int	is_last_cmd_token_out(t_data *data, int index)
{
	t_cmd	*prev;

	prev = data->cmd;
	if (index == 0)
		return (0);
	while (prev && prev->index != index - 1)
		prev = prev->next;
	if (!prev)
		return (0);
	if (is_token(prev, OUT))
		return (1);
	return (0);
}

// cree les fichiers si commande existante mais invalide, sans dup2
int	create_files(t_data *data, t_cmd *cmd)
{
	int	i;

	i = 0;
	if (count_tokens(data, cmd->index) > 0)
	{
		while (cmd->token && cmd->token[i])
		{
			if (!handle_token_redir(data, cmd, i, 0))
				return (1);
			i++;
		}
	}
	return (0);
}
