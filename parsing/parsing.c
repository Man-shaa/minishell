/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:15:26 by mfroissa          #+#    #+#             */
/*   Updated: 2023/03/20 12:57:29 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	check_pipe(t_data *data)
{
	t_list	*tmp;

	tmp = data->list;
	if (tmp && tmp->type == 6)
		return (err_msg("minishell: syntax error near unexpected token `|'",
			NULL, NULL, 0));
	if (tmp && tmp->type == 2 && !tmp->next)
		return (err_msg("minishell: syntax error near unexpected token `<'",
			NULL, NULL, 0));
	if (tmp && tmp->type == 3 && !tmp->next)
		return (err_msg("minishell: syntax error near unexpected token `>'",
			NULL, NULL, 0));
	if (tmp && tmp->type == 4 && !tmp->next)
		return (err_msg("minishell: syntax error near unexpected token `<<'",
			NULL, NULL, 0));
	if (tmp && tmp->type == 5 && !tmp->next)
		return (err_msg("minishell: syntax error near unexpected token `>>'",
			NULL, NULL, 0));
	return (1);
}

int	check_dup(t_data *data)
{
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (tmp->next && tmp->type != WORD && tmp->type != PIPE
			&& tmp->next->type != WORD)
		{
			if (tmp->next->type != PIPE)
				return (0);
		}
		if (tmp->next && tmp->type == PIPE && tmp->next->type == PIPE)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	check_redir(char *str, int *i)
{
	if (str[(*i)] == '>' || str[(*i)] == '<')
	{
		if (str[(*i) + 1] == str[(*i)])
		{
			(*i)++;
			if (str[(*i) + 1] == str[(*i)])
				return (0);
		}
	}
	return (1);
}

int	check_quotes(char *str, int i)
{
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] && str[i] != '"')
				i++;
			if (str[i] == '\0')
				return (err_msg("quote is not closed", NULL, NULL, 99));
		}
		if (str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 39)
				i++;
			if (str[i] == '\0')
				return (err_msg("quote is not closed", NULL, NULL, 99));
		}
		if (!check_redir(str, &i))
			return (err_msg("syntax error", NULL, NULL, 0), 2);
		i++;
	}
	return (0);
}

int	parsing(t_data *data)
{
	if (!check_pipe(data))
	{
		g_return_val = 02;
		return (0);
	}
	if (!check_dup(data))
	{
		g_return_val = 02;
		return (err_msg("minishell: unexpected token or redirection",
				NULL, NULL, 0));
	}
	if (!handle_dollar_quote(data))
		return (err_msg("minishell: malloc failed", NULL, NULL, 0));
	return (1);
}
