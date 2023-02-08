/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:44 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/08 18:33:54 by msharifi         ###   ########.fr       */
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
		if (is_same(cmd->cmd, "cd") && args)
			g_return_val = ft_cd(data, args);
		else if (is_same(cmd->cmd, "export") && args)
			g_return_val = ft_export(data, args);
		else if (is_same(cmd->cmd, "echo") && args)
			ft_echo(args);
		else if (is_same(cmd->cmd, "env") && args)
			g_return_val = print_env(data->envp, args);
		else if (is_same(cmd->cmd, "pwd"))
			g_return_val = print_pwd();
		else if (is_same(cmd->cmd, "unset") && args && args[0])
			ft_unset(data, args);
		free_data(data);
		exit(g_return_val);
	}
	waitpid(pid, &status, 0);
	return (WEXITSTATUS(status));
}

// Compare str avec les builtins et si str en est un,
// envoies a la fonction correspondante pour l'executer
int	exec_builtin(t_data *data, t_cmd *cmd, char **args)
{
	int	ret_exit;

	if (is_same(cmd->cmd, "exit") && args && data->proc->n_pipes == 0)
	{
		ret_exit = ft_exit(data, args);
		if (ret_exit != -1)
			exit(ret_exit);
		g_return_val = 1;
	}
	if (send_builtin_fork(data, cmd, args))
		return (1);
	if (is_same(cmd->cmd, "export"))
		g_return_val = ft_export(data, args);
	else if (is_same(cmd->cmd, "cd"))
		g_return_val = ft_cd(data, args);
	else if (is_same(cmd->cmd, "unset"))
		ft_unset(data, args);
	return (g_return_val);
}
