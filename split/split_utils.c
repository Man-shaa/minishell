/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfroissa <mfroissa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 07:33:41 by mfroissa          #+#    #+#             */
/*   Updated: 2023/01/10 19:19:51 by mfroissa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minishell.h"

// return des valeurs en fonction du charset rencontre
int	is_in_charset(char c)
{
	if (c == '<' || c == '>')
		return (1);
	if (c == '|')
		return (2);
	if (c == ' ' || c == '\t')
		return (3);
	if (c == '"' || c == 39)
		return (4);
	return (0);
}

// return des valeurs en fonction du charset rencontre
int	is_end_of_string(char c)
{
	if (c == '<' || c == '>' || c == '|' || c == ' ' || c == '\t' || c == '\0')
		return (1);
	return (0);
}
