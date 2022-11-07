/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:33:48 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/07 15:37:40 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// reagit en fonction du caractere rencontre
int	count_words_cmd(char *str, int *i)
{
	int	count;

	count = 0;
	if (is_in_charset(str[(*i) + 1]) || str[(*i) + 1] == '\0')
		count++;
	(*i)++;
	return (count);
}

int	count_words_redir(char *str, int *i)
{
	int	count;

	count = 0;
	if (str[(*i) + 1] == str[(*i)])
		(*i)++;
	count++;
	(*i)++;
	return (count);
}

int	count_words_quote(char *str, int *i, int *count)
{
	while (str[*i] && str[(*i)] != '"')
		(*i)++;
	if (str[(*i)] == '"')
	{
		(*i)++;
		(*count)++;
		return (1);
	}
	return (0);
}
