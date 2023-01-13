/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:11:04 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/13 22:11:20 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	ft_free(tab);
}

// Free la structure t_list de t_data
void	free_list(t_list *list)
{
	t_list	*save;

	save = list;
	while (list)
	{
		list = list->next;
		if (save->str)
			ft_free(save->str);
		if (save->dollar)
			ft_free(save->dollar);
		ft_free(save);
		save = list;
	}
}

// Free la structure t_envp de t_data
void	free_envp(t_envp *envp)
{
	t_envp	*save;

	save = envp;
	while (envp)
	{
		envp = envp->next;
		if (save->tab)
			free_tab(save->tab);
		ft_free(save);
		save = envp;
	}
}

// Free la structure t_cmd de t_data
void	free_cmd(t_cmd *cmd)
{
	t_cmd	*save;

	save = cmd;
	while (cmd)
	{
		cmd = cmd->next;
		if (save->cmd_path)
			ft_free(save->cmd_path);
		if (save->opt)
			ft_free(save->opt);
		if (save->type)
			ft_free(save->type);
		if (save->token)
			ft_free(save->token);
		ft_free(save);
		save = cmd;
	}
}

// Free tout t_data
void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->list)
		free_list(data->list);
	if (data->cmd)
		free_cmd(data->cmd);
	if (data->envp)
		free_envp(data->envp);
	if (data->proc)
		free_proc(data->proc);
	ft_free(data);
	rl_clear_history();
}
