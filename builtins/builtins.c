/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/20 21:36:11 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return 1 si str est un builtin, sinon 0
int	is_builtin(char *str)
{
	if (is_same(str, "cd"))
		return (1);
	else if (is_same(str, "echo"))
		return (1);
	else if (is_same(str, "env"))
		return (1);
	else if (is_same(str, "exit"))
		return (1);
	else if (is_same(str, "export"))
		return (1);
	else if (is_same(str, "pwd"))
		return (1);
	else if (is_same(str, "unset"))
		return (1);
	return (0);
}

void	send_to_individual_builtin(t_data *data, t_cmd *cmd, char **args)
{
	if (is_same(cmd->cmd, "cd") && args)
		g_return_val = ft_cd(data, args);
	else if (is_same(cmd->cmd, "export") && args)
		g_return_val = ft_export(data, args, 0);
	else if (is_same(cmd->cmd, "echo") && args)
		g_return_val = ft_echo(args);
	else if (is_same(cmd->cmd, "env") && args)
		g_return_val = print_env(data->envp, args);
	else if (is_same(cmd->cmd, "pwd"))
		g_return_val = print_pwd();
	else if (is_same(cmd->cmd, "unset") && args && args[0])
		g_return_val = ft_unset(data, args);
}

int	send_builtin_fork(t_data *data, t_cmd *cmd, char **args)
{
	int	pid;
	int	status;

	pid = fork();
	if (pid == -1)
		return (1);
	if (pid == 0)
	{
		redir(data, cmd, 1);
		send_to_individual_builtin(data, cmd, args);
		free_data(data);
		exit(g_return_val);
	}
	waitpid(pid, &status, 0);
	g_return_val = WEXITSTATUS(status);
	return (WEXITSTATUS(status));
}

// Compare str avec les builtins et si str en est un,
// envoies a la fonction correspondante pour l'executer
int	exec_builtin(t_data *data, t_cmd *cmd, char **args)
{
	if (is_same(cmd->cmd, "exit") && args && data->proc->n_pipes == 0)
	{
		g_return_val = ft_exit(data, args);
		if (g_return_val != -1)
			exit(g_return_val);
		g_return_val = 1;
	}
	if (data->proc->n_pipes == 0)
	{
		if (is_same(cmd->cmd, "export") && args && args[0])
			g_return_val = ft_export(data, args, 1);
		else if (is_same(cmd->cmd, "cd"))
			g_return_val = ft_cd(data, args);
		else if (is_same(cmd->cmd, "unset"))
			g_return_val = ft_unset(data, args);
	}
	send_builtin_fork(data, cmd, args);
	return (g_return_val);
}
