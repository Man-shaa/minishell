/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:20:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/20 20:23:58 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

char	*expand_heredoc(t_envp *envp, char *str)
{
	char	*new;
	int		i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '$')
		{
			if (str[i + 1] == '?')
				new = replace_ret_val(str, i);
			else if (str[i + 1] == '$')
			{
				new = ft_strndup(str, 0);
				i++;
			}
			else if (!str[i + 1])
				new = ft_strndup(str, 0);
			else
				new = replace_dollar(envp, str, &i);
			ft_free(str);
			str = new;
		}
		i++;
	}
	return (str);
}

int	fill_heredoc(t_envp *envp, char *delim, int fd)
{
	int		f_stdin;
	char	*str;

	f_stdin = dup(STDIN_FILENO);
	while (1 && g_return_val != -42)
	{
		str = readline(">");
		if (g_return_val == -42)
		{
			ft_free(str);
			dup2(f_stdin, STDIN_FILENO);
			close(fd);
			return (close(f_stdin), 0);
		}
		if (is_same(str, delim))
			return (ft_free(str), close(f_stdin), close(fd), 1);
		if (str)
			str = expand_heredoc(envp, str);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		ft_free(str);
	}
	return (1);
}

int	create_heredoc(t_cmd *cmd, t_envp *envp, int cmd_pos, int fd)
{
	int		i;
	char	*str;
	char	*filename;
	char	*cmd_number;

	str = NULL;
	i = 0;
	cmd_number = ft_itoa(cmd_pos);
	filename = ft_strjoin("/tmp/.heredoc_manuo", cmd_number);
	ft_free(cmd_number);
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_free(filename);
	if (fd == -1)
		return (err_msg("Open heredoc failed !", NULL, NULL, 0));
	if (!fill_heredoc(envp, cmd->token[cmd_pos], fd))
		return (0);
	return (1);
}

int	print_all_heredoc(t_data *data, t_envp *envp)
{
	t_cmd	*cmd;
	int		i;

	i = 0;
	cmd = data->cmd;
	if (!count_all_heredoc(data))
		return (1);
	signal(SIGINT, handle_sighere);
	while (cmd)
	{
		i = 0;
		while (cmd->token && cmd->token[i])
		{
			if (cmd->type[i] == HERE)
			{
				if (!create_heredoc(cmd, envp, i,
						data->proc->fd_heredoc[i + cmd->index]))
					return (0);
			}
			i++;
		}
		cmd = cmd->next;
	}
	return (1);
}
