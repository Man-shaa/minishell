/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:11:04 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/19 10:22:40 by msharifi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

void	*ft_calloc(size_t n, size_t size)
{
	void	*tab;
	char	*str;

	tab = malloc(n * size);
	if (!tab)
		return (NULL);
	str = tab;
	while (n > 0)	
	{
		n--;
		str[n] = '\0';
	}
	return (tab);
}

void	ft_free(void *addr)
{
	free(addr);
	addr = NULL;
}

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		ft_free(tab[i]);
		i++;
	}
	if (tab)
		ft_free(tab);
}

// Free seulement la structure t_list dans t_data
void	free_list(t_list *list)
{
	t_list *save;

	save = list;
	while (list)
	{
		list = list->next;
		ft_free(save);
		save = list;
	}
}

// Free tout
void	free_data(t_data *data)
{
	if (data->list)
		free_list(data->list);
	if (data)
		ft_free(data);
}
