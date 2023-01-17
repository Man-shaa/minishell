/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/17 17:15:26 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/17 17:54:41 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	parsing(t_data *data)
{
	if (!check_dup(data))
		return (err_msg("minishell: unexpected token or redirection",
				NULL, NULL, 0));
	if (!handle_dollar_quote(data))
		return (err_msg("minishell: malloc failed", NULL, NULL, 0));
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
				return (0);
		}
		if (str[i] == 39)
		{
			i++;
			while (str[i] && str[i] != 39)
				i++;
			if (str[i] == '\0')
				return (0);
		}
		i++;
	}
	return (1);
}
