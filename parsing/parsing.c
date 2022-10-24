/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:52:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/10/24 23:47:06 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// return des valeurs en fonction du charset rencontre
int	is_in_charset(char c)
{
	if (c == '<')
		return (1);
	if (c == '>')
		return (2);
	if (c == '|')
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
		while (str[i] && !is_in_charset(str[i]))
		{
			while (str[i] && (str[i] == 32 || str[i] == '\t'))
				i++;
			if (str[i] == '\0')
				return (count);
			if (is_in_charset(str[i + 1]) || str[i + 1] == '\0' ||
				str[i + 1] == ' ' || str[i + 1] == '\t')
				count++;
			i++;
		}
		if (is_in_charset(str[i]))
		{
			if (str[i] != '|' && str[i + 1] == str[i])
				i++;
			count++;
			i++;
		}
	}
	return (count);
}

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
		while (str[i] && !is_in_charset(str[i]))
		{
			while (str[i] && (str[i] == 32 || str[i] == '\t'))
				i++;
			if (str[i] == '\0')
				return (chars);
			if (count == n)
				chars++;
			if (is_in_charset(str[i + 1]) || str[i + 1] == '\0' ||
				str[i + 1] == ' ' || str[i + 1] == '\t')
				count++;
			while (str[i] && (str[i] == 32 || str[i] == '\t'))
				i++;
			i++;
		}
		if (is_in_charset(str[i]))
		{
			if (count == n)
				chars++;
			if (str[i] != '|' && str[i + 1] == str[i])
			{
				chars++;
				i++;
			}
			count++;
			i++;
		}
	}
	return (chars);
}

char	*ft_putwords(char *str, int n, char *mot)
{
	int	i;
	int	count;
	int	chars;

	i = 0;
	count = 0;
	chars = 0;
	while (str[i])
	{
		while (str[i] && !is_in_charset(str[i]))
		{
			while (str[i] && (str[i] == 32 || str[i] == '\t'))
				i++;
			if (str[i] == '\0')
				break;
			if (count == n)
			{
				mot[chars] = str[i];
				chars++;
			}
			if (is_in_charset(str[i + 1]) || str[i + 1] == '\0' ||
				str[i + 1] == ' ' || str[i + 1] == '\t')
				count++;
			while (str[i] && (str[i] == 32 || str[i] == '\t'))
				i++;
			i++;
		}
		if (is_in_charset(str[i]))
		{
			if (count == n)
			{
				mot[chars] = str[i];
				chars++;
			}
			if (str[i] != '|' && str[i + 1] == str[i])
			{
				i++;
				if (count == n)
				{
					mot[chars] = str[i];
					chars++;
				}
			}
			count++;
			i++;
		}
	}
	mot[chars] = '\0';
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
		printf("chars %d : %d\n", i, count_chars(str, i) + 1);
		tab[i] = ft_calloc(sizeof(char), count_chars(str, i) + 1);
		tab[i] = ft_putwords(str, i, tab[i]);
		add_last_list(data, tab[i]);
		i++;
	}
	tab[i] = 0;
	return (tab);
}
