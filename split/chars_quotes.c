/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_quotes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 17:50:32 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/17 17:50:55 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_chars_double(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] && str[(*i)] != '"')
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[(*i)] == '"')
		return (chars += count_chars_double_inner(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}

int	count_chars_double_inner(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] != 39 && str[*i] != '"' && !is_end_of_string(str[*i]))
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[*i] == '"')
		return (chars += count_chars_double_inner(str, i, count, n));
	else if (str[*i] == 39)
		return (chars += count_chars_single(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}

int	count_chars_single(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] && str[(*i)] != 39)
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[(*i)] == 39)
		return (chars += count_chars_single_inner(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}

int	count_chars_single_inner(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	if ((*count) == n)
		chars++;
	while (str[*i] != 39 && str[*i] != '"' && !is_end_of_string(str[*i]))
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	if (str[*i] == 39)
		return (chars += count_chars_single_inner(str, i, count, n));
	else if (str[*i] == '"')
		return (chars += count_chars_double(str, i, count, n));
	else
	{
		(*count)++;
		return (chars);
	}
}
