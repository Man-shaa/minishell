/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 15:08:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/03 14:10:08 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Return 1 si cmd a le dernier heredoc, sinon return 0
int	is_last_heredoc(t_data *data, t_cmd *cmd, int cmd_pos)
{
	int		count;

	count = 0;
	while (cmd->type && cmd_pos < count_tokens(data, cmd->index))
	{
		if (cmd->type[cmd_pos] == HERE)
			count++;
		cmd_pos++;
	}
	if (count > 1)
		return (0);
	return (1);
}

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
	// FILE	*fdread = fopen("/tmp/.heredoc_manuo", "r");
	// char	c;
	// printf("\nDEBUT LECTURE FGETC\n");
	// while ((c = fgetc(fdread)) != EOF)
	// 	printf("%c", c);
	// fclose(fdread);
	// printf("\nFIN LECTURE FGETC\n");
	return (1);
}

int	create_heredoc(t_data *data, t_cmd *cmd, int fd, int cmd_pos)
{
	int		i;
	char	*str;

	str = NULL;
	i = 0;
	signal(SIGINT, handle_sighere);
	fd = open("/tmp/.heredoc_manuo", O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (fd == -1)
		return (err_msg("Open heredoc failed !", NULL, NULL, 0));
	if (!fill_heredoc(str, cmd->token[cmd_pos], fd))
		return (0);
	close(fd);
	fd = open("/tmp/.heredoc_manuo", O_RDONLY);
	if (fd == -1)
		return (err_msg("Second open heredoc failed !", NULL, NULL, 0));
	if (is_last_heredoc(data, cmd, cmd_pos) == 1)
	{
		if (dup2(fd, STDIN_FILENO) == -1)
			return (close(fd), err_msg("Dup2 heredoc failed", NULL, NULL, 0), 0);
	}
	close(fd);
	return (1);
}
