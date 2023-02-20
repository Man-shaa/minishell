/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 12:13:03 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/20 20:25:45 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Attends la fin d'execution de chaque process child et recupere la valeur
// de retour de chaque commande effectuee
void	wait_all_child(t_data *data, int n)
{
	int	i;
	int	status;

	status = 1;
	i = 0;
	if (!data->proc->pid)
		return ;
	while (i < n)
	{
		if (data->proc->pid[i] != -1)
		{
			waitpid(data->proc->pid[i], &status, 0);
			g_return_val = WEXITSTATUS(status);
		}
		i++;
	}
}

int	execve_binary(t_data *data, t_cmd *cmd, int ret)
{
	char	**env_tab;

	env_tab = get_env_tab(data->envp);
	if (!cmd->cmd_path)
	{
		ret = (error_cmd(cmd->opt));
		free_tab(env_tab);
		free_data(data);
		exit (ret);
	}
	execve(cmd->cmd_path, cmd->opt, env_tab);
	free_tab(env_tab);
	return (error_cmd(cmd->opt));
}

// Execute les commandes (non builtins)
// Ne return rien si l'execution a reussie ou la valeur d'erreur
int	exec_binary(t_data *data, t_cmd *c)
{
	int		ret;

	ret = 0;
	if (!is_builtin(c->cmd) && !c->cmd_path && c->type && c->type[0] != HERE)
		return (err_msg("env not found, need an absolute path", 0, 0, 1), 1);
	data->proc->pid[c->index] = fork();
	if (data->proc->pid[c->index] == 0)
	{
		if (redir(data, c, 1))
		{
			close_pipes(data->proc);
			free_data(data);
			exit(1);
		}
		if (is_builtin(c->cmd))
			g_return_val = exec_builtin(data, c, c->opt);
		else if (is_cmd(data, c, c->cmd, data->env_path))
			g_return_val = execve_binary(data, c, ret);
		free_data(data);
		exit(ret);
	}
	return (g_return_val);
}

// Envoies la commande a la fonction de builtins ou d'exec bin
// Return le retour de chaque commande effectuee
int	send_cmd(t_data *data, t_cmd *cmd)
{
	signal(SIGQUIT, handle_sigquit);
	if (!cmd->cmd || !cmd->cmd[0] || is_same(cmd->cmd, "..")
		|| is_same(cmd->cmd, "."))
	{
		if (cmd->token && cmd->token[0] && cmd->type[0] != HERE)
			return (redir(data, cmd, 0));
		else if (cmd->type && cmd->type[0] == HERE)
			return (exec_binary(data, cmd));
		return (error_cmd(cmd->opt));
	}
	else if (is_builtin(cmd->cmd))
		return (exec_builtin(data, cmd, cmd->opt));
	else if (is_builtin(cmd->cmd) || is_cmd(data, cmd, cmd->cmd,
			data->env_path))
		return (exec_binary(data, cmd));
	redir(data, cmd, 0);
	return (error_cmd(cmd->opt));
}

// Cree les pipes et s'occupe des redirections avant d'envoyer la commande
// a send_cmd
// Return 0 si il y a un probleme a la creation des pipes, sinon 0
int	execution(t_data *data)
{
	t_cmd	*cmd;

	cmd = data->cmd;
	if (!create_pipes_array(data))
		return (0);
	print_all_heredoc(data, data->envp);
	handle_sigint_exec();
	while (cmd) 
	{
		g_return_val = send_cmd(data, cmd);
		cmd = cmd->next;
	}
	close_pipes(data->proc);
	wait_all_child(data, data->proc->n_pipes + 1);
	handle_signal();
	return (1);
}
