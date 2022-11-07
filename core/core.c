/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 11:27:33 by mfroissa          #+#    #+#             */
/*   Updated: 2022/11/07 11:59:40 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	get_prompt(t_data *data)
{
	char	*str;
	char	**tab;
	int		i;

	data = malloc(sizeof(t_data));
	str = readline("Manuo 🤔 ✖✖ ");
	i = 0;
	tab = ft_split(str, data);
		print_list(data->list);
	free_data(data);
}