/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:33:16 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/10 19:22:21 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

//reagit en fonction du caractere rencontre
int	count_chars_cmd(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	if ((*count) == n)
		chars++;
	if (is_end_of_string(str[(*i) + 1]))
		(*count)++;
	(*i)++;
	return (chars);
}

int	count_chars_redir(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	if ((*count) == n)
		chars++;
	if (str[(*i) + 1] == str[(*i)])
	{
		if ((*count) == n)
			chars++;
		(*i)++;
	}
	(*count)++;
	(*i)++;
	return (chars);
}

int	count_chars_pipe(int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	if ((*count) == n)
		chars++;
	(*count)++;
	(*i)++;
	return (chars);
}

//update
int	count_chars_quote(char *str, int *i, int *count, int n)
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
	if (str[(*i)] == '"' && !is_end_of_string(str[(*i) + 1]))
	{
		(*i)++;
		if ((*count) == n)
			chars++;
		while (str[*i] != '"' && str[*i] != 39 && !is_end_of_string(str[*i]))
		{
			(*i)++;
			if ((*count) == n)
				chars++;
		}
		if (str[*i] == '"')
			return (chars += count_chars_quote(str, i, count, n));
		else if (str[*i] == 39)
			return (chars += count_chars_single(str, i, count, n));
		else
		{
			(*count)++;
			return (chars);
		}
	}
	else
	{
		(*i)++;
		if ((*count) == n)
			chars++;
		(*count)++;
		return (chars);
	}
}

//update
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
	if (str[(*i)] == 39 && !is_end_of_string(str[(*i) + 1]))
	{
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
			return (chars += count_chars_single(str, i, count, n));
		else if (str[*i] == '"')
			return (chars += count_chars_quote(str, i, count, n));
		else
		{
			(*count)++;
			return (chars);
		}
	}
	else
	{
		(*i)++;
		if ((*count) == n)
			chars++;
		(*count)++;
		return (chars);
	}
}
