/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   words_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:33:48 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/10 18:09:11 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// reagit en fonction du caractere rencontre
int	count_words_cmd(char *str, int *i)
{
	int	count;

	count = 0;
	if (is_end_of_string(str[(*i) + 1]))
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

int	count_words_pipe(int *i)
{
	(*i)++;
	return (1);
}

// avant l'updqate
// void	count_words_quote(char *str, int *i, int *count)
// {
// 	(*i)++;
// 	while (str[*i] && str[(*i)] != '"')
// 		(*i)++;
// 	if (str[(*i)] == '"')
// 	{
// 		(*i)++;
// 		(*count)++;
// 	}
// 	else if (str[(*i)] == '\0')
// 		(*count) = -1;
// }

//update
int	count_words_quote(char *str, int *i, int *count)
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
			return (count_words_quote(str, i, count));
		else if (str[*i] == 39)
			return (count_words_single(str, i, count));
		else
			return (1);
	}
	else
	{
		(*i)++;
		return (1);
	}
}

//avant l'update
// void	count_words_single(char *str, int *i, int *count)
// {
// 	(*i)++;
// 	while (str[*i] && str[(*i)] != 39)
// 		(*i)++;
// 	if (str[(*i)] == 39)
// 	{
// 		(*i)++;
// 		(*count)++;
// 	}
// 	else if (str[(*i)] == '\0')
// 		(*count) = -1;
// }

//update
int	count_words_single(char *str, int *i, int *count)
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
			return (count_words_single(str, i, count));
		else if (str[*i] == '"')
			return (count_words_quote(str, i, count));
		else
			return (1);
	}
	else
	{
		(*i)++;
		return (1);
	}
}
