/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:32:56 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/14 18:39:34 by mfroissa         ###   ########.fr       */
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

int	fill_dollar_tab(t_data *data)
{
	int		i;
	int		index;
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
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
		tmp->str = remove_quotes(tmp->str);
		tmp = tmp->next;
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

int	ft_strlen_quotes(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == '"')
		{
			i++;
			while (str[i] != '"')
				i++;
			i++;
			count += 2;
		}
		else if (str[i] == 39)
		{
			i++;
			while (str[i] != 39)
				i++;
			i++;
			count += 2;
		}
		else if (str[i])
			i++;
	}
	return (count);
}

char	*remove_quotes(char *str)
{
 	int		i;
	int		j;
	char	*new;
	
	i = 0;
	j = 0;
	new = ft_calloc(ft_strlen(str) - ft_strlen_quotes(str) + 1, sizeof(char));
	if (!new)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '"')
			remove_dq(str, new, &i, &j);
		else if (str[i] == 39)
			remove_sq(str, new, &i, &j);
		else
			new[j++] = str[i++];
	}
	new[j] = '\0';
	free (str);
	return (new);
}

void	remove_dq(char *str, char *new, int *i, int *j)
{
	(*i)++;
	while (str[*i] != '"')
	{
		new[*j] = str[*i];
		(*i)++;
		(*j)++;
	}
	(*i)++;
}

void	remove_sq(char *str, char *new, int *i, int *j)
{
	(*i)++;
	while (str[*i] != 39)
	{
		new[*j] = str[*i];
		(*i)++;
		(*j)++;
	}
	(*i)++;
}
