/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:20:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/03/20 13:31:13 by mfroissa         ###   ########.fr       */
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
	while (1 && g_return_val != -126)
	{
		str = readline(">");
		if (g_return_val == -126)
		{
			ft_free(str);
			dup2(f_stdin, STDIN_FILENO);
			close(fd);
			return (close(f_stdin), 0);
		}
		if (is_same(str, delim) || !str)
			return (ft_free(str), close(f_stdin), close(fd), 1);
		if (str)
			str = expand_heredoc(envp, str);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		ft_free(str);
	}
	return (1);
}

int	which_heredoc(t_data *data, t_cmd *cmd, int cmd_pos)
{
	t_cmd	*tmp;
	int		here_pos;
	int		j;

	here_pos = cmd_pos;
	if (data->proc->n_heredoc == 1)
		here_pos = 0;
	tmp = data->cmd;
	while (tmp && tmp != cmd)
	{
		j = 0;
		while (tmp->token && tmp->token[j])
		{
			if (tmp->type[j] == HERE)
				here_pos++;
			j++;
		}
		tmp = tmp->next;
	}
	return (here_pos);
}

int	create_heredoc(t_cmd *cmd, t_data *data, int cmd_pos)
{
	int		i;
	char	*str;
	char	*filename;
	char	*cmd_number;
	int		here_pos;

	str = NULL;
	i = 0;
	here_pos = which_heredoc(data, cmd, cmd_pos);
	cmd_number = ft_itoa(here_pos);
	filename = ft_strjoin("/tmp/.heredoc_manuo", cmd_number);
	ft_free(cmd_number);
	data->proc->fd_heredoc[here_pos] = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_free(filename);
	if (data->proc->fd_heredoc[here_pos] == -1)
		return (err_msg("Open heredoc failed !", NULL, NULL, 0));
	if (!fill_heredoc(data->envp, cmd->token[cmd_pos], data->proc->fd_heredoc[here_pos]))
		return (0);
	return (1);
}

int	print_all_heredoc(t_data *data)
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
				if (!create_heredoc(cmd, data, i))
					return (0);
			}
			i++;
		}
		cmd = cmd->next;
	}
	handle_signal();
	return (1);
}
