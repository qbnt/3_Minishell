/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_t_l_args.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 15:06:14 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/28 15:48:01 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*----------------------------------------------------------------------------*/

void	t_l_args_first(t_l_args *first)
{
	if (!first)
	{
		first = malloc(sizeof(t_l_args));
		first->prev = NULL;
		first->next = NULL;
		first->token = NO_TOKEN;
		first->content = NULL;
	}
}

void	t_l_args_add_next(t_pars *pars, t_l_args *full_cmd)
{
	size_t	len;

	len = ft_ltrlen(&pars);
	full_cmd->content = malloc((sizeof(char) * len) + 1);
	
}