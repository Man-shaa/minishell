/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:52:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/07 16:40:48 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// return le nombre de mots
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
		else if (str[i] == '"' && !count_words_quote(str, &i, &count))
			return (0);
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

// return le nombre de chars dans chaque mot
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
		else if (str[i] == '"')
			chars += count_chars_quote(str, &i, &count, n);
		else if (!is_in_charset(str[i]))
			chars += count_chars_cmd(str, &i, &count, n);
		else if (is_in_charset(str[i]) == 1)
			chars += count_chars_redir(str, &i, &count, n);
		else if (is_in_charset(str[i]) == 2)
			chars += count_chars_pipe(&i, &count, n);
	}
	return (chars);
}

// transcrit chaque mot dans le tab
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
	if (!count_words(str))
		return (ft_putstr("No instructions or missing double quote"), NULL);
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
