/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:32:56 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/16 17:21:35 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_dollars(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '$')
			result++;
		i++;
	}
	return (result);
}

int	handle_dollar_quote(t_data *data)
{
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (!fill_dollar_tab(tmp))
			return (0);
		if (count_dollars(tmp->str))
			handle_dollar(data, tmp);
		tmp->str = remove_quotes(tmp->str);
		tmp = tmp->next;
	}
	return (1);
}

int	fill_dollar_tab(t_list *tmp)
{
	int	i;
	int	index;

	i = 0;
	index = 0;
	tmp->dollar = ft_calloc(count_dollars(tmp->str), sizeof(int));
	if (!tmp->dollar)
		return (0);
	while (tmp->str[i])
	{
		if (tmp->str[i] == '$')
			tmp->dollar[index++] = 1;
		else if (tmp->str[i] == '"')
			fill_dollar_dq(tmp, &i, &index);
		else if (tmp->str[i] == 39)
			fill_dollar_sq(tmp, &i, &index);
		i++;
	}
	return (1);
}

void	fill_dollar_dq(t_list *tmp, int *i, int *index)
{
	(*i)++;
	while (tmp->str[*i] != '"')
	{
		if (tmp->str[*i] == '$')
		{
			tmp->dollar[*index] = 1;
			(*i)++;
			(*index)++;
		}
		else
			(*i)++;
	}
}

void	fill_dollar_sq(t_list *tmp, int *i, int *index)
{
	(*i)++;
	while (tmp->str[*i] != 39)
	{
		if (tmp->str[*i] == '$')
		{
			tmp->dollar[*index] = 0;
			(*i)++;
			(*index)++;
		}
		else
			(*i)++;
	}
}
