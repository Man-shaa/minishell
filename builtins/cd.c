/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:07:52 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/18 20:07:24 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_a_dir(char *str)
{
	if (access(str, F_OK | X_OK) == 0)
		return (1);
	return (0);
}

int	check_cd(char **args)
{
	int	i;

	i = 0;
	if (!args[0])
		return (err_msg("minishell: no relative or absolute path", NULL, NULL, 0), 0);
	while (args[i])
		i++;
	if (i > 1)
		return (err_msg("minishell: more than 1 relative or absolute path",
			NULL, NULL, 0), 0);
	if (!is_a_dir(args[0]))
		return (err_msg("minishell: is not a directory", NULL, NULL, 0), 0);
	return (1);
}

// changer oldpwd et pwd avec replace...
int	ft_cd(t_data *data, char **args)
{
	if (!check_cd(args))
		return (1);
	chdir(args[0]);
	replace_pwd_my_env(data->envp);
	return (0);
}
