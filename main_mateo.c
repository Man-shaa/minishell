/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_mateo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/19 10:16:41 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "includes/minishell.h"

int	main(int ac, char **av)
{
	t_data	*data;
	char *str;
	char	**tab;
	int		i;

	data = create_data();
	if (!data)
		return (1);
	i = 0;
	if (ac != 2)
		return (printf("nul"), 0);
	str = av[1];
	tab = ft_split(str, data);
	print_tab(tab);
	print_list(data->list);
	free(tab);
	return (0);
}
