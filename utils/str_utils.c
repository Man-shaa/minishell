/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:32:11 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/20 19:07:03 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

char	*ft_strcmp(char *str, char *to_find)
{
	int	i;

	i = 0;
	while (str[i] && to_find[i] && str[i] == to_find[i])
		i++;
	if (!to_find[i])
		return (&str[i]);
	return (NULL);
}

char	*ft_strdup(char *str)
{
	int		i;
	char	*dup;

	i = 0;
	if (!str)
		return (NULL);
	dup = ft_calloc(ft_strlen(str) + 1, 1);
	while (str[i])
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// Cherche le type de redir
int	ft_strchr(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '<' && str[1] == '<')
		return (DELIM);
	if (str[0] == '>' && str[1] == '>')
		return (APPEND);
	if (str[0] == '<')
		return (IN);
	if (str[0] == '>')
		return (OUT);	
	else
		return (WORD);
	return (0);
}
