/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:08:17 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/23 15:28:34 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_heredoc(char *delim)
{
	int	i;
	int	fd;
	char *str;

	i = 0;
	fd = open(".heredoc", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (err_msg("Open failed !", NULL, NULL , 0));
	while (1)
	{
		str = readline(">");
		if (ft_strcmp(str, delim))
			break ;
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
	}
	close(fd);
	fd = open(".heredoc", O_RDONLY);
	close(fd);
	return (fd);
}
