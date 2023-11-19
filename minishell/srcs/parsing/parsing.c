/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:52:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/19 12:31:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	check_elems(t_elem_pars *oui);
static void		elem_count(t_elem_pars *oui, char **input);

/*============================================================================*/

t_pars	**parsing(char *input, t_mini *ms)
{
	t_in	*in;
	t_pars	*pars;

	ms->elem_pars = check_input(input);
	in = set_str_to_t_in(input);
	if (!in)
		return (perror("Pars error\n"), NULL);
	pars = set_in_to_t_pars(in);
	free(input);
	return (make_clear_cmds(ms->elem_pars, pars->first));
}

t_elem_pars	*check_input(char *input)
{
	t_elem_pars	*oui;

	oui = ft_calloc(sizeof(t_elem_pars), 1);
	oui->nb_cmd = 1;
	while (*input)
	{
		elem_count(oui, &input);
		input ++;
	}
	printf("dcote = %d	| scote = %d	| pipe = %d	| cmd = %d\nand_op = %d	| and char = %d	| or op = %d	| parenth = %d\n\n", oui->nb_dcote, oui->nb_scote, oui->nb_pipe, oui->nb_cmd, oui->nb_and_op, oui->nb_and_char, oui->nb_or_op, oui->nb_parenth);
	if (!check_elems(oui))
	{
		printf("oups\n");
		return (free (oui), NULL);
	}
	return (oui);
}

static void	elem_count(t_elem_pars *oui, char **input)
{
	if (**input == 34 && oui->nb_scote % 2 == 0)
		oui->nb_dcote ++;
	else if (**input == 39 && oui->nb_dcote % 2 == 0)
		oui->nb_scote ++;
	else if (**input == '|'
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		pars_is_pipe(input, &oui);
	else if (**input == '&'
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		pars_is_and_op(input, &oui);
	else if ((**input == '(' || **input == ')')
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		oui->nb_parenth ++;
}

static t_bool	check_elems(t_elem_pars *oui)
{
	int	total_op;

	total_op = oui->nb_or_op + oui->nb_and_op + oui->nb_pipe;
	if (oui->nb_dcote % 2 != 0)
		return (printf("dcote open\n"), 0);
	else if (oui->nb_scote % 2 != 0)
		return (printf("scote open\n"), 0);
	else if (oui->nb_parenth % 2 != 0)
		return (printf("parenth open\n"), 0);
	else if (oui->nb_and_char != 0)
		return (printf("and char\n"), 0);
	else if (total_op != oui->nb_cmd - 1)
		return (printf("op sup\n"), 0);
	else if (oui->error == TRUE)
		return (printf("error elem\n"), 0);
	return (1);
}
