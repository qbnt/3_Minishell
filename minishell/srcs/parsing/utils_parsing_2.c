/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/21 19:15:32 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/*============================================================================*/

t_bool	empty_parenth(char *input)
{
	if (*input == '(' && *(input + 1) == ')')
		return (TRUE);
	else if (*input == '(')
	{
		input += 1;
		while (*input && ft_is_whitespace(*input))
			input += 1;
		if (*input == ')')
			return (TRUE);
	}
	else if (*input == ')')
	{
		input += 1;
		while (*input && ft_is_whitespace(*input))
			input += 1;
		if (*input == '(')
			return (TRUE);
	}
	return (FALSE);
}

void	select_opp(t_pars	*pars, t_pars **cmd)
{
	if (pars && pars->token == OPP && !ft_strncmp(pars->str, "|", 1)
		&& ft_strlen(pars->str) == 1)
		(*cmd)->first->pipe_op = TRUE;
	else if (pars && pars->token == OPP && !ft_strncmp(pars->str, "||", 2)
		&& ft_strlen(pars->str) == 2)
		(*cmd)->first->or_op = TRUE;
	else if (pars && pars->token == OPP && !ft_strncmp(pars->str, "&&", 2)
		&& ft_strlen(pars->str) == 2)
		(*cmd)->first->and_op = TRUE;
}

size_t	count_cote(char *str, t_token token)
{
	int		res;

	res = 0;
	while (*str)
	{
		if (token == CMD && (*str == 34 || *str == 39))
			res ++;
		else if (token == STR && *str == 34)
			res ++;
		else if (token == LIT_STR && *str == 39)
			res ++;
		str ++;
	}
	return (res);
}

char	*clean_dol(char *str, t_env_elems *env, t_token token)
{
	int		i;
	size_t	total_len;

	i = 0;
	total_len = 
	while (str[i] && str[i] != '$')
		i ++;
	if (str[i])
		printf("dol = %s\n", ft_cpy_dol(str + i));
	return (str);
}
