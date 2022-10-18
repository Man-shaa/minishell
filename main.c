/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 14:44:22 by msharifi          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2022/10/18 23:18:29 by mfroissa         ###   ########.fr       */
=======
/*   Updated: 2022/10/18 23:09:15 by msharifi         ###   ########.fr       */
>>>>>>> 4ead86d8b416b3d308ff31fca6d4d17c86afa185
/*                                                                            */
/* ************************************************************************** */

#include "includes/minishell.h"

int	main(void)
{
<<<<<<< HEAD
	char *str = "echo     > m mateo";
	char	**tab;
	int		i;

	i = 0;
	tab = ft_split(str);
	while (tab[i])
	{
		printf("%s\n", tab[i]);
		free(tab[i]);
		i++;
	}
	free(tab);
=======
	t_data	*data;
	int		i;

	i = 1;
	data = create_data();
	if (!data)
		return (1);
	while (i < ac)
	{
		data->list = add_to_list(data, av[i]);
		if (!data->list)
			return (free_data(data), 2);
		i++;
	}
	print_list(data->list);
	free_data(data);
>>>>>>> 4ead86d8b416b3d308ff31fca6d4d17c86afa185
	return (0);
}
