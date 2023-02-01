/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 16:32:56 by mfroissa          #+#    #+#             */
/*   Updated: 2023/02/01 16:46:25 by mfroissa         ###   ########.fr       */
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

int	handle_dollar_quote(t_data *data)
{
	t_list	*tmp;

	tmp = data->list;
	while (tmp)
	{
		if (!fill_dollar_tab(tmp))
			return (0);
		if (count_dollars(tmp->str))
			handle_dollar(data, tmp);
		tmp->str = remove_quotes(tmp->str);
		tmp = tmp->next;
	}
	return (1);
}
