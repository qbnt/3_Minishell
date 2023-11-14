/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:52:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/14 21:58:03 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	stop_input(char *input);
static t_bool	check_elems(t_elem_pars *oui);
static void		elem_count(t_elem_pars *oui, char *input);

/*----------------------------------------------------------------------------*/

t_pars	*parsing(char *input)
{
	t_in	*in;

	if (stop_input(input))
		exit(EXIT_SUCCESS);
	in = set_str_to_t_in(input);
	ft_print_t_in(&in, CHAR);
	return (set_in_to_t_pars(in));
}

static t_bool	stop_input(char *input)
{
	if (ft_strncmp(input, "exit", 5))
		return (FALSE);
	else
	{
		free(input);
		return (TRUE);
	}
}

t_elem_pars	*check_input(char *input)
{
	t_elem_pars	*oui;

	oui = ft_calloc(sizeof(t_elem_pars), 1);
	oui->nb_cmd = 1;
	while (*input)
	{
		elem_count(oui, input);
		input ++;
	}
	printf("dcote = %d, scote = %d, pipe = %d cmd = %d\n", oui->nb_dcote,
		oui->nb_scote, oui->nb_pipe, oui->nb_cmd);
	if (!check_elems(oui))
	{
		printf("oups\n");
		return (free (oui), NULL);
	}
	return (oui);
}

static void	elem_count(t_elem_pars *oui, char *input)
{
	if (*input == 34)
		oui->nb_dcote ++;
	else if (*input == 39 && oui->nb_dcote % 2 == 0)
		oui->nb_scote ++;
	else if (*input == '|')
	{
		oui->nb_cmd ++;
		oui->nb_pipe ++;
	}
	else if ((*input == '<' || *input == '<')
		&& ft_is_whitespace(*(input - 1)) && ft_is_whitespace(*(input + 1)))
		oui->nb_redir ++;
}

static t_bool	check_elems(t_elem_pars *oui)
{
	if (oui->nb_dcote % 2 != 0)
		return (0);
	else if (oui->nb_scote % 2 != 0)
		return (0);
	return (1);
}
