/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_manu.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/13 16:20:17 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/20 16:14:24 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_all_heredoc(t_data *data)
{
	int		count;
	t_cmd	*cmd;
	int		i;

	count = 0;
	cmd = data->cmd;
	while (cmd)
	{
		i = 0;
		while (cmd->type && cmd->token[i])
		{
			if (cmd->type[i] == HERE)
				count++;
			i++;
		}
		cmd = cmd->next;
	}
	data->proc->n_heredoc = count;
	if (data->proc->n_heredoc > 0)
	{
		data->proc->fd_heredoc = ft_calloc(count, sizeof(int));
		if (!data->proc->fd_heredoc)
			return (-1);
	}
	return (count);
}

// meme principe que parsing/parsing.c->handle_dollar()

// char	*expand_heredoc(char *str)
// {
// 	char	*new;
// 	char	*d_expand;
// 	t_envp	*env;
// 	int		i;
// 	int		d_pos;

// 	i = 0;
// 	while (str[i] && str[i] != '$')
// 		i++;
// 	new = ft_strndup(str, i);
// 	i++;
// 	d_pos = i;
// 	while (!is_sep(str[i]))
// 		i++;
// 	d_expand = ft_strndup(&str[j], i - j);
// 	env = search_node()
// 	return (new);
// }

int	fill_heredoc_manu(char *delim, int fd)
{
	int	f_stdin;
	char	*str;

	f_stdin = dup(STDIN_FILENO);
	while (1 && g_return_val != -42)
	{
		str = readline(">");
		if (g_return_val == -42)
		{
			ft_free(str);
			close(fd);
			dup2(f_stdin, STDIN_FILENO);
			close(f_stdin);
			return (0);
		}
		if (is_same(str, delim))
		{
			ft_free(str);
			break ;
		}
		// str = expand_heredoc(str);
		write(fd, str, ft_strlen(str));
		write(fd, "\n", 1);
		ft_free(str);
	}
	return (1);
}

int	create_heredoc_manu(t_cmd *cmd, int cmd_pos, int fd)
{
	int		i;
	char	*str;
	char	*filename;
	char	*cmd_number;

	str = NULL;
	i = 0;
	signal(SIGINT, handle_sighere);
	cmd_number = ft_itoa(cmd_pos);
	filename = ft_strjoin("/tmp/.heredoc_manuo", cmd_number);
	ft_free(cmd_number);
	fd = open(filename, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	ft_free(filename);
	if (fd == -1)
		return (err_msg("Open heredoc failed !", NULL, NULL, 0));
	if (!fill_heredoc_manu(cmd->token[cmd_pos], fd))
		return (0);
	close(fd);
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
	while (cmd)
	{
		i = 0;
		while (cmd->token && cmd->token[i])
		{
			if (cmd->type[i] == HERE)
			{
				if (!create_heredoc_manu(cmd, i,
						data->proc->fd_heredoc[i + cmd->index]))
					return (0);
			}
			i++;
		}
		cmd = cmd->next;
	}
	return (1);
}
