/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/13 14:31:06 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/18 19:13:22 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

t_redir	*ft_lstnew_redir(void)
{
	t_redir	*redir;

	redir = ft_calloc(1, sizeof(t_cmd));
	if (!redir)
		return (NULL);
	redir->type = NULL;
	redir->porte = NULL;
	redir->next = NULL;
	return (redir);
}

t_cmd	*ft_lstnew_cmd(void)
{
	t_cmd	*cmd;

	cmd = ft_calloc(1, sizeof(t_cmd));
	if (!cmd)
		return (NULL);
	cmd->cmd_args = NULL;
	cmd->cmd_path = NULL;
	cmd->next = NULL;
	return (cmd);
}

t_cmd	*ft_lstlast_cmd(t_cmd *cmd)
{
	if (!cmd)
		return (NULL);
	while (cmd->next)
		cmd = cmd->next;
	return (cmd);
}

t_cmd	*add_last_cmd(t_cmd *cmd, char *av) //cree et ajoute la cmd recu (av) en dernier dans t_cmd
{
	t_cmd	*new;
	t_cmd	*last;

	new = ft_lstnew_cmd();
	new->cmd_args = ft_split_normal(av, ' ');
	if (!new)
		return (NULL);
	last = ft_lstlast_cmd(cmd);
	if (!last)
	{
		cmd = new;
		return (cmd);
	}
	last->next = new;
	return (cmd);
}
