/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 05:07:52 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/18 18:21:29 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	is_a_dir(char *str)
{
	if (access(str, F_OK | X_OK) == 0)
		return (1);
	else
		return (0);
}

int	check_cd(char **args)
{
	int	i;

	i = 0;
	if (!args[0])
		return (err_msg("no relative or absolute path", NULL, NULL, 0), 0);
	while (args[i])
		i++;
	if (i > 1)
		return (err_msg("more than 1 relative or absolute path", NULL, NULL, 0), 0);
	if (!is_a_dir(args[0]))
		return (err_msg("no such file or directory", NULL, NULL, 0), 0);
	return (1);
}

// changer oldpwd et pwd avec replace...
int	ft_cd(t_data *data, char **args)
{
	(void)data;
	if (!check_cd(args))
		return (1);
	chdir(args[0]);
	return (0);
}
