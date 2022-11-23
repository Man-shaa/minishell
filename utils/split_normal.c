/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_normal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:37 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/23 16:34:25 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h" 

int	count_words_normal(char *str, char c)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			i++;
		else
		{
			count++;
			while (str[i] && str[i] != c)
				i++;
		}
	}
	return (count);
}

char	*putword_normal(char *word, char *s, int i, int word_len)
{
	int	j;

	j = 0;
	while (word_len > 0)
	{
		word[j] = s[i - word_len];
		j++;
		word_len--;
	}
	word[j] = '\0';
	return (word);
}

char	**split_words_normal(char *s, char c, char **tab, int word_count)
{
	int	i;
	int	word;
	int	word_len;

	i = 0;
	word = 0;
	word_len = 0;
	while (word < word_count)
	{
		while (s[i] && s[i] == c)
			i++;
		while (s[i] && s[i] != c)
		{
			i++;
			word_len++;
		}
		tab[word] = ft_calloc(word_len + 1, 1);
		if (!tab)
			return (0);
		putword_normal(tab[word], s, i, word_len);
		word_len = 0;
		word++;
	}
	tab[word] = 0;
	return (tab);
}

char	**ft_split_normal(char *s, char c)
{
	char	**tab;
	int		word_count;

	if (!s)
		return (0);
	word_count = count_words_normal(s, c);
	tab = ft_calloc(word_count + 1, sizeof(char *));
	if (!tab)
		return (0);
	if (!split_words_normal(s, c, tab, word_count))
	free_tab(tab);
	return (tab);
}
