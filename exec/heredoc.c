/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:08:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/01 17:00:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	fill_heredoc(char *str, char *delim, int fd)
{
	while (1 && fd)
	{
		if (g_return_val == -42)
		{
			ft_free(str);
			close(fd);
			return (0);
		}
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
	return (1);
}

int	create_heredoc(int fd, char *delim)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	signal(SIGINT, handle_sighere);
	fd = open("/tmp/.heredoc_manuo", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (err_msg("Open heredoc failed !", NULL, NULL, 0));
	if (!fill_heredoc(str, delim, fd))
		return (0);
	close(fd);
	fd = open("/tmp/.heredoc_manuo", O_RDONLY);
	if (fd == -1)
		return (err_msg("Second open heredoc failed !", NULL, NULL, 0));
	if (dup2(fd, STDIN_FILENO) == -1)
		return (close(fd), err_msg("Dup2 heredoc failed", NULL, NULL, 0), 0);
	close(fd);
	return (1);
}
