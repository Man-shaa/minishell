/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 18:48:44 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 11:46:00 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Ajouter les valeurs de retour de chaque builtin

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
int	exec_builtin(t_data *data, char **args)
{
	int	return_val;

	return_val = 1;
	if (is_same(args[0], "cd"))
		ft_cd(data, args[1]);
	else if (is_same(args[0], "echo"))
		ft_echo(data, args[1]);
	else if (is_same(args[0], "env"))
		print_env(data->envp);
	else if (is_same(args[0], "exit"))
		return (200); // a rajouter
	else if (is_same(args[0], "export"))
		ft_export(data, args[1]);
	else if (is_same(args[0], "pwd"))
		print_pwd();
	else if (is_same(args[0], "unset"))
		ft_unset(data, args[1]);
	return (return_val); // a remplacer par valeur de retour de builtin
}
