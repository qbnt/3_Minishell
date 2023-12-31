/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 13:52:45 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/08 13:43:51 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static t_bool	check_elems(t_elem_pars *oui);
static void		elem_count(t_elem_pars *oui, char **input);

/*============================================================================*/

t_pars	**parsing(char **input, t_mini *ms)
{
	t_in	*in;
	t_pars	*pars;
	t_pars	**res;

	ms->elem_pars = check_input(*input);
	if (!ms->elem_pars)
		return (printf("Lexer error\n"), free(*input), NULL);
	in = set_str_to_t_in(*input);
	if (!in)
		return (printf("Pars error\n"), NULL);
	pars = set_in_to_t_pars(in);
	res = make_clear_cmds(ms->elem_pars, pars->first, ms);
	return (res);
}

t_elem_pars	*check_input(char *input)
{
	t_elem_pars	*oui;
	int			i;

	i = 0;
	oui = ft_calloc(sizeof(t_elem_pars), 1);
	oui->nb_cmd = 1;
	while (ft_is_whitespace(input[i]))
		i ++;
	if (input[i] == '|' || input[i] == '&')
		return (NULL);
	while (*input)
	{
		elem_count(oui, &input);
		input ++;
	}
	oui->tmp_pipes = oui->nb_pipe;
	if (!check_elems(oui))
		return (free (oui), NULL);
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
	else if ((**input == '(')
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		oui->nb_op_parenth ++;
	else if ((**input == ')')
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		oui->nb_cl_parenth ++;
	else if ((**input == '>' || **input == '<')
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		pars_is_redir(input, &oui);
	if ((empty_parenth(*input))
		&& (oui->nb_scote % 2 == 0 && oui->nb_dcote % 2 == 0))
		oui->error = TRUE;
}

static t_bool	check_elems(t_elem_pars *oui)
{
	int	total_op;
	int	total_parenth;

	total_op = oui->nb_or_op + oui->nb_and_op + oui->nb_pipe;
	total_parenth = oui->nb_op_parenth + oui->nb_cl_parenth;
	if (oui->nb_dcote % 2 != 0)
		return (printf("Dcote open\n"), 0);
	else if (oui->nb_scote % 2 != 0)
		return (printf("Scote open\n"), 0);
	else if (total_parenth % 2 != 0
		|| (oui->nb_op_parenth != oui->nb_cl_parenth))
		return (printf("Parenth open\n"), 0);
	else if (oui->nb_and_char != 0)
		return (printf("And char\n"), 0);
	else if (total_op != oui->nb_cmd - 1)
		return (printf("Op sup\n"), 0);
	else if (oui->error == TRUE)
		return (printf("Error on true\n"), 0);
	return (1);
}
