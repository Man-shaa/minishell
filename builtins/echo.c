/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/22 17:39:45 by msharifi          #+#    #+#             */
/*   Updated: 2022/11/21 01:32:10 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// gerer option -n (newline)

#include "../includes/minishell.h"

void	ft_echo(t_data *data, char *str)
{
	t_envp	*node;
	char	*res;

	node = data->envp;
	if (ft_strchr(str, '$'))
		ft_putstr(str);
	else
	{
		res = ignore_charset(str, "$(){}");
		node = search_node(data->envp, res);
		ft_free(res);
		ft_putstr(node->tab[1]);
	}
	write(1, "\n", 1);
}
