/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:52:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/25 07:22:28 by mfroissa         ###   ########.fr       */
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

int	count_words(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (is_in_charset(str[i]) == 3)
			i++;
		else if (!is_in_charset(str[i]))
			count += count_words_cmd(str, &i);
		else if (is_in_charset(str[i]) == 1)
			count += count_words_redir(str, &i);
		else if (is_in_charset(str[i]) == 2)
		{
			count++;
			i++;
		}
	}
	return (count);
}

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

// int	count_words_exp(char *str, int *i)
// {
// 	int	count;

// 	count = 0;
// 	if (is_in_charset(str[(*i)]))
// 	{
// 		if (str[(*i)] != '|' && str[(*i) + 1] == str[(*i)])
// 			(*i)++;
// 		count++;
// 		(*i)++;
// 	}
// 	return (count);
// }

int	count_chars(char *str, int n)
{
	int	i;
	int	count;
	int	chars;

	i = 0;
	count = 0;
	chars = 0;
	while (str[i])
	{
		if (is_in_charset(str[i]) == 3)
			i++;
		else if (!is_in_charset(str[i]))
			chars += count_chars_cmd(str, &i, &count, n);
		else if (is_in_charset(str[i]) == 1)
			chars += count_chars_redir(str, &i, &count, n);
		else if (is_in_charset(str[i]) == 2)
			chars += count_chars_pipe(&i, &count, n);
	}
	return (chars);
}

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

// int	count_charsd(char *str, int n)
// {
// 	int	i;
// 	int	count;
// 	int	chars;

// 	i = 0;
// 	count = 0;
// 	chars = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && (str[i] == 32 || str[i] == '\t'))
// 			i++;
// 		while (str[i] && !is_in_charset(str[i]))
// 		{
// 			if (str[i] == '\0')
// 				return (chars);
// 			if (count == n)
// 				chars++;
// 			if (is_in_charset(str[i + 1]) || str[i + 1] == '\0'
// 				|| str[i + 1] == ' ' || str[i + 1] == '\t')
// 			{
// 				count++;
// 				if (str[i] != '|' && str[i + 1] == str[i])
// 					i++;
// 			}
// 			i++;
// 			while (str[i] && (str[i] == 32 || str[i] == '\t'))
// 				i++;
// 		}
// 		chars += count_chars_exp(str, &count, &n, &i);
// 	}
// 	return (chars);
// }

// int	count_chars_exp(char *str, int *count, int *n, int *i)
// {
// 	int	chars;

// 	chars = 0;
// 	while (is_in_charset(str[(*i)]))
// 	{
// 		if ((*count) == (*n))
// 			chars++;
// 		if (str[(*i)] != '|' && str[(*i) + 1] == str[(*i)])
// 		{
// 			if ((*count) == (*n))
// 				chars++;
// 			(*i)++;
// 		}
// 		(*count)++;
// 		(*i)++;
// 						while (str[*i] && (str[*i] == ' ' || str[*i] == '\t'))
// 			(*i)++;
// 	}
// 	return (chars);
// }

// char	*ft_putwords(char *str, int n, char *mot)
// {
// 	int	i;
// 	int	count;
// 	int	chars;

// 	i = 0;
// 	count = 0;
// 	chars = 0;
// 	while (str[i])
// 	{
// 		while (str[i] && !is_in_charset(str[i]))
// 		{
// 			while (str[i] && (str[i] == 32 || str[i] == '\t'))
// 				i++;
// 			if (str[i] == '\0')
// 				break ;
// 			if (count == n)
// 			{
// 				mot[chars] = str[i];
// 				chars++;
// 			}
// 			if (is_in_charset(str[i + 1]) || str[i + 1] == '\0'
// 				|| str[i + 1] == ' ' || str[i + 1] == '\t')
// 				count++;
// 			i++;
// 		}
// 		if (is_in_charset(str[i]))
// 		{
// 			if (count == n)
// 			{
// 				mot[chars] = str[i];
// 				chars++;
// 			}
// 			if (str[i] != '|' && str[i + 1] == str[i])
// 			{
// 				i++;
// 				if (count == n)
// 				{
// 					mot[chars] = str[i];
// 					chars++;
// 				}
// 			}
// 			count++;
// 			i++;
// 		}
// 	}
// 	mot[chars] = '\0';
// 	return (mot);
// }

int	get_index(char *str, int n)
{
	int	i;
	int	count;
	int	chars;

	i = 0;
	count = 0;
	chars = 0;
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

char	*ft_putwords(char *str, int n, char *mot)
{
	int	i;
	int	index;

	index = get_index(str, n);
	i = 0;
	while (i < count_chars(str, n))
	{
		mot[i] = str[index];
		i++;
		index++;
	}
	return (mot);
}

char	**ft_split(char *str, t_data *data)
{
	char	**tab;
	int		i;

	if (!str)
		return (0);
	i = 0;
	if (!str)
		return (NULL);
	tab = ft_calloc(sizeof(char *), count_words(str) + 1);
	printf("words : %d\n", count_words(str));
	while (i < count_words(str))
	{
		printf("chars %d : %d\n", i, count_chars(str, i));
		tab[i] = ft_calloc(sizeof(char), count_chars(str, i) + 1);
		tab[i] = ft_putwords(str, i, tab[i]);
		add_last_list(data, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
