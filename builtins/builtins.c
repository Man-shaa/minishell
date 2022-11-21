/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 16:00:09 by msharifi         ###   ########.fr       */
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
// envoies a la fonction correspondante
int	exec_builtin(t_data *data, char *cmd, char **args)
{
	int	return_val;

	return_val = 1;
	if (is_same(cmd, "cd"))
		ft_cd(data, args[0]);
	else if (is_same(cmd, "echo"))
		ft_echo(data, args);
	else if (is_same(cmd, "env"))
		print_env(data->envp);
	else if (is_same(cmd, "exit"))
		return (200); // a rajouter
	else if (is_same(cmd, "export"))
		ft_export(data, args);
	else if (is_same(cmd, "pwd"))
		print_pwd();
	else if (is_same(cmd, "unset"))
		ft_unset(data, args[1]);
	return (return_val); // a remplacer par valeur de retour de builtin
}
