/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:33:41 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/25 07:47:06 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// return des valeurs en fonction du charset rencontre
int	is_in_charset(char c)
{
	if (c == '<' || c == '>')
		return (1);
	if (c == '|')
		return (2);
	if (c == ' ' || c == '\t')
		return (3);
	return (0);
}

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
			if (is_in_charset(str[i + 1]) || str[i + 1] == '\0'
				|| str[i + 1] == ' ' || str[i + 1] == '\t')
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
		if (str[(*i)] != '|' && str[(*i) + 1] == str[(*i)])
			(*i)++;
		(*count)++;
		(*i)++;
	}
	return (0);
}
