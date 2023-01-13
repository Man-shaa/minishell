/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_index.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 19:19:37 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/13 22:03:31 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// return l'index ou commence chaque mots
int	get_index(char *str, int n)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t'))
			i++;
		while (str[i] && !is_in_charset(str[i]))
		{
			while (str[i] && (str[i] == ' ' || str[i] == '\t'))
				i++;
			if (count == n)
				return (i);
			if (is_end_of_string(str[i + 1]))
				count++;
			i++;
		}
		if (get_index_exp(str, &count, &i, n))
			return (i);
	}
	return (0);
}

int	get_index_exp(char *str, int *count, int *i, int n)
{
	while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
		(*i)++;
	if (is_in_charset(str[(*i)]))
	{
		if ((*count) == n)
			return (1);
		else if (str[(*i)] == '"')
			get_index_dq(str, count, i);
		else if (str[(*i)] == 39)
			get_index_sq(str, count, i);
		else if (str[(*i)] != '|' && str[(*i) + 1] == str[(*i)])
			(*i)++;
		else
		{
			(*count)++;
			(*i)++;
		}
	}
	return (0);
}

void	get_index_dq(char *str, int *count, int *i)
{
	(*i)++;
	while (str[*i] && str[(*i)] != '"')
		(*i)++;
	if (str[(*i)] == '"' && !is_end_of_string(str[(*i) + 1]))
	{
		(*i)++;
		while (str[*i] != '"' && str[*i] != 39 && !is_end_of_string(str[*i]))
			(*i)++;
		if (str[*i] == '"')
			get_index_dq(str, count, i);
		else if (str[*i] == 39)
			get_index_sq(str, count, i);
		if (is_end_of_string(str[(*i)]))
			(*count)++;
	}
	else
	{
		(*i)++;
		(*count)++;
	}
}

void	get_index_sq(char *str, int *count, int *i)
{
	(*i)++;
	while (str[*i] && str[(*i)] != 39)
		(*i)++;
	if (str[(*i)] == 39 && !is_end_of_string(str[(*i) + 1]))
	{
		(*i)++;
		while (str[*i] != 39 && str[*i] != '"' && !is_end_of_string(str[*i]))
			(*i)++;
		if (str[*i] == 39)
			get_index_sq(str, count, i);
		else if (str[*i] == '"')
			get_index_dq(str, count, i);
		if (is_end_of_string(str[(*i)]))
			(*count)++;
	}
	else
	{
		(*i)++;
		(*count)++;
	}
}
