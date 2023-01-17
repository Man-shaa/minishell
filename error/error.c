/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 13:19:29 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/17 17:04:05 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Affiche un message d'erreur sur STDERR
// Return la valeur de retour ret
int	err_msg(char *start, char *str, char *end, int ret)
{
	if (start)
		write(STDERR_FILENO, start, ft_strlen(start));
	if (str)
		write(STDERR_FILENO, str, ft_strlen(str));
	if (end)
		write(STDERR_FILENO, end, ft_strlen(end));
	write(STDERR_FILENO, "\n", 1);
	return (ret);
}

// Affiche le message d'erreur correspondant a l'erreur
// Return la valeur de retour selon l'erreur 
int	error_cmd(char **cmd)
{
	int	fd;
	DIR	*dir;
	int	ret;

	ret = 0;
	if (!cmd || !cmd[0])
		return (1);
	if (ft_strchr(cmd[0], '/'))
		return (err_msg("minishell: ", cmd[0], ": command not found", 127));
	fd = open(cmd[0], O_WRONLY);
	dir = opendir(cmd[0]);
	if (fd == -1 && dir == NULL)
		ret = err_msg("minishell: ", cmd[0], ": No such file or directory",
				127);
	else if (fd == -1 && dir != NULL)
		ret = err_msg("minishell: ", cmd[0], ": is a directory", 126);
	else if (fd != -1 && dir == NULL)
		ret = err_msg("minishell: ", cmd[0], ": Permission denied", 127);
	else
		ret = err_msg("minishell: ", cmd[0], ": command not found", 127);
	if (fd > 0)
		close(fd);
	if (dir)
		closedir(dir);
	return (ret);
}
