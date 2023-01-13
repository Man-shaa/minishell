/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:32:56 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/13 22:26:05 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

int	count_dollars(char *str)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '$')
			result++;
		i++;
	}
	return (result);
}

int	fill_dollar_tab(t_data *data)
{
	int		i;
	int		index;
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
		i = 0;
		index = 0;
		tmp->dollar = ft_calloc(count_dollars(tmp->str), sizeof(int));
		if (!tmp->dollar)
			return (0);
		while (tmp->str[i])
		{
			if (tmp->str[i] == '$')
				tmp->dollar[index++] = 1;
			else if (tmp->str[i] == '"')
				fill_dollar_dq(tmp, &i, &index);
			else if (tmp->str[i] == 39)
				fill_dollar_sq(tmp, &i, &index);
			i++;
		}
		tmp = tmp->next;
	}
	//fonction manu echo_env_var()
	//fonction mateo enlever les quotes
	return (1);
}

void	fill_dollar_dq(t_list *tmp, int *i, int *index)
{
	printf("PASSAGE DANS FILL DOLLAR DQ\n");
	(*i)++;
	while (tmp->str[*i] != '"')
	{
		if (tmp->str[*i] == '$')
		{
			tmp->dollar[*index] = 1;
			printf("dollar[%d] = 1\n", *index);
			(*i)++;
			(*index)++;
		}
		else
			(*i)++;
	}
}

void	fill_dollar_sq(t_list *tmp, int *i, int *index)
{
	printf("PASSAGE DANS FILL DOLLAR SQ\n");
	(*i)++;
	while (tmp->str[*i] != 39)
	{
		if (tmp->str[*i] == '$')
		{
			tmp->dollar[*index] = 0;
			printf("dollar[%d] = 0\n", *index);
			(*i)++;
			(*index)++;
		}
		else
			(*i)++;
	}
}