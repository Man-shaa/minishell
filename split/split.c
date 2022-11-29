/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/17 17:52:09 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/29 04:46:32 by msharifi         ###   ########.fr       */
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
		else if (str[i] == '"')
			count_words_quote(str, &i, &count);
		else if (!is_in_charset(str[i]))
			count += count_words_cmd(str, &i);
		else if (is_in_charset(str[i]) == 1)
			count += count_words_redir(str, &i);
		else if (is_in_charset(str[i]) == 2)
			count += count_words_pipe(&i);
		if (count == -1)
			return (0);
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
		if (str[index] == '"')
			index++;
		mot[i] = str[index];
		i++;
		index++;
	}
	return (mot);
}

void	ft_split(char *str, t_data *data)
{
	char	**tab;
	int		i;

	if (!str)
		return ;
	i = 0;
	if (!count_words(str))
		return (ft_putstr("No instructions or missing double quote\n"));
	tab = ft_calloc(count_words(str) + 1, sizeof(char *));
	// printf("words : %d\n", count_words(str));
	while (i < count_words(str))
	{
		// printf("chars %d : %d\n", i, count_chars(str, i));
		tab[i] = ft_calloc(count_chars(str, i) + 1, sizeof(char));
		tab[i] = ft_putwords(str, i, tab[i]);
		add_last_list(data, tab[i]);
		i++;
	}
	tab[i] = 0;
	ft_free(tab);
}
