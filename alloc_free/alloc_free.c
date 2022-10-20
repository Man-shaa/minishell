/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   alloc_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msharifi <msharifi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 15:11:04 by msharifi          #+#    #+#             */
/*   Updated: 2022/10/20 18:45:06 by msharifi         ###   ########.fr       */
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

// Free seulement la structure t_list de t_data
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

void	free_envp(t_envp *envp)
{
	t_envp *save;

	save = envp;
	while (envp)
	{
		envp = envp->next;
		free_tab(save->tab);
		ft_free(save);
		save = envp;
	}
}

// Free tout t_dada
void	free_data(t_data *data)
{
	if (!data)
		return ;
	if (data->list)
		free_list(data->list);
	if (data->envp)
		free_envp(data->envp);
	ft_free(data);
}
