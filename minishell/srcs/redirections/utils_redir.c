/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 18:45:21 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/23 18:47:56 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

t_bool	redir_in_cmd(t_pars *cmd)
{
	while (cmd)
	{
		if (cmd->token == REDIR || cmd->token == RE_IN || cmd->token == RE_OUT)
			return (TRUE);
		cmd = cmd->next;
	}
	return (FALSE);
}
