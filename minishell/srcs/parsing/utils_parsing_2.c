/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/29 19:28:17 by qbanet           ###   ########.fr       */
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
	char	*res_str;
	char	*tmp;
	char	*tmp_str;

	i = 0;
	tmp_str = str;
	total_len = ft_strlen(str) + ft_dol_len_in_str(str, env);
	res_str = ft_calloc(sizeof(char), total_len + 1);
	while (*str)
	{
		if (token != LIT_STR && *str == '$')
		{
			tmp = ft_cpy_dol(++str);
			ft_strlcat(res_str, t_env_elems_find_value_of(env, tmp),
				total_len + 1);
			str += ft_strlen(tmp);
			i += ft_strlen(t_env_elems_find_value_of(env, tmp));
			free (tmp);
		}
		if (*str && *str != '$')
			res_str[i++] = *(str++);
	}
	return (free(tmp_str), res_str);
}
