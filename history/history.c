/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   history.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:24:47 by msharifi          #+#    #+#             */
/*   Updated: 2022/12/21 18:30:21 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// Historique
void	add_to_history(char **av)
{
	char	*line;
	char	*save;
	int		i;

	i = 1;
	line = NULL;
	if (!av || !av[0])
		return ;
	while (av[i])
	{
		save = ft_strndup(line, 0);
		ft_free(line);
		line = ft_strjoin(save, av[i]);
		ft_free(save);
		i++;
	}
	printf("line : %s\n", line);
	add_history(line);
	ft_free(line);
}
