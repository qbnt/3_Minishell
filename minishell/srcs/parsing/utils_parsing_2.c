/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 12:18:19 by qbanet            #+#    #+#             */
/*   Updated: 2023/11/30 15:44:20 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	switch_dol(char **str, t_env_elems *env, size_t total_len,
				char *res_str);

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

char	*clean_dol(char *str, t_mini *ms, t_token token)
{
	int		i;
	size_t	total_len;
	char	*res_str;
	char	*tmp_str;

	i = 0;
	tmp_str = str;
	total_len = ft_strlen(str) + ft_dol_len_in_str(str, ms);
	res_str = ft_calloc(sizeof(char), total_len + 1);
	while (*str)
	{
		if (token != LIT_STR && *str == '$')
		{
			if (*(str + 1) == 0)
				return (str);
			if (*(str + 1) == '?')
				i += switch_res(&str, ms, total_len, res_str);
			else
				i += switch_dol(&str, ms->env->env_elems, total_len, res_str);
		}
		if (*str && *str != '$')
			res_str[i++] = *(str++);
	}
	return (free(tmp_str), res_str);
}

static int	switch_dol(char **str, t_env_elems *env, size_t total_len,
	char *res_str)
{
	char	*tmp;
	char	*tmp2;
	int		i;

	i = 0;
	tmp = ft_cpy_dol(++(*str));
	tmp2 = t_env_elems_find_value_of(env, tmp);
	ft_strlcat(res_str, tmp2, total_len + 1);
	(*str) += ft_strlen(tmp);
	i += ft_strlen(tmp2);
	free (tmp);
	free (tmp2);
	return (i);
}
