/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chars_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:33:16 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/04 16:56:17 by mfroissa         ###   ########.fr       */
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
	if (is_in_charset(str[(*i) + 1]) || str[(*i) + 1] == '\0')
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

int	count_chars_quote(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	while (str[(*i)] != '"')
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	(*i)++;
	(*count)++;
	return (chars);
}

int	count_chars_single(char *str, int *i, int *count, int n)
{
	int	chars;

	chars = 0;
	(*i)++;
	// if ((*count) == n)
	// 	chars++;
	while (str[(*i)] != 39)
	{
		(*i)++;
		if ((*count) == n)
			chars++;
	}
	(*i)++;
	// if ((*count) == n)
	// 	chars++;
	(*count)++;
	// printf("chaine[%d] = %d\n", (*count), chars);
	return (chars);
}
