/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:08:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/01/20 15:27:02 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	create_heredoc(int fd, char *delim)
{
	int		i;
	char	*str;

	i = 0;
	fd = open("/tmp/.heredoc_manuo", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (err_msg("Open heredoc failed !", NULL, NULL, 0));
	while (1)
	{
		str = readline(">");
		if (is_same(str, delim))
		{
			ft_free(str);
			break ;
		}
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		ft_free(str);
	}
	close(fd);
	fd = open("/tmp/.heredoc_manuo", O_RDONLY);
	if (fd == -1)
		return (err_msg("Second open heredoc failed !", NULL, NULL, 0));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (close(fd), err_msg("Dup2 heredoc failed", NULL, NULL, 0), 0);
	close(fd);
	return (1);
}
