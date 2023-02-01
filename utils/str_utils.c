/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:32:11 by msharifi          #+#    #+#             */
/*   Updated: 2023/02/01 16:49:39 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
		i++;
	return (i);
}

// Cherche to_find dans str
// Return l'addresse de la fin de chaine de caractere to_find 
// ou NULL si to_find n'a pas ete trouve dans str
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

// Duplique n caratcere de str
// Si n = 0 duplique l'entierte de str
// Return la chaine de caractere dupliquee
char	*ft_strndup(char *str, int n)
{
	int		i;
	char	*dup;

	i = -1;
	if (!str)
		return (NULL);
	dup = ft_calloc(ft_strlen(str) + 1, 1);
	if (!dup)
		return (NULL);
	if (n == 0)
	{
		while (str[++i])
			dup[i] = str[i];
	}
	else
	{
		while (++i < n && str[i])
			dup[i] = str[i];
	}
	return (dup);
}

void	ft_putstr(char *str)
{
	if (!str)
		return ;
	write(STDOUT_FILENO, str, ft_strlen(str));
}

// Cherche le type de redir
// Return le type ou 0 si str ne correspond a aucun connu
int	redir_type(char *str)
{
	if (!str)
		return (0);
	if (str[0] == '|')
		return (PIPE);
	if (str[0] == '<' && str[1] && str[1] == '<')
		return (HERE);
	if (str[0] == '>' && str[1] && str[1] == '>')
		return (APPEND);
	if (str[0] == '<')
		return (IN);
	if (str[0] == '>')
		return (OUT);
	else
		return (WORD);
}
