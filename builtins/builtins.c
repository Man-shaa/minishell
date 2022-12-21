/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 18:51:48 by msharifi         ###   ########.fr       */
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

// Compare str avec les builtins et si str en est un,
// envoies a la fonction correspondante pour l'executer
int	exec_builtin(t_data *data, char *cmd, char **args)
{
	int	ret_exit;

	if (is_same(cmd, "cd") && args && args[0])
		data->return_val = ft_cd(data, args[0]);
	else if (is_same(cmd, "export") && args)
		data->return_val = ft_export(data, args);
	if (is_same(cmd, "echo") && args)
		ft_echo(data, args);
	else if (is_same(cmd, "env") && args)
		print_env(data->envp, args);
	else if (is_same(cmd, "exit") && args)
	{
		ret_exit = ft_exit(data, args);
		if (ret_exit != -1)
			exit(ret_exit);
		data->return_val = 1;
	}
	else if (is_same(cmd, "pwd"))
		print_pwd();
	else if (is_same(cmd, "unset") && args && args[0])
		ft_unset(data, args[0]);
	return (data->return_val);
}
