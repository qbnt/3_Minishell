/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:37:23 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/05 15:57:28 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_handler(int signal);
static void	sigint_handler(void);
static void	sigquit_handler(void);

/*============================================================================*/

void	signaux(t_signial *sig)
{
	sigemptyset(&(sig->set));
	sigaddset(&(sig->set), SIGINT);
	sigaddset(&(sig->set), SIGQUIT);
	sig->sa.sa_handler = signal_handler;
	sig->sa.sa_mask = sig->set;
	sig->sa.sa_flags = SA_SIGINFO;
	sigaction(SIGINT, &(sig->sa), NULL);
	sigaction(SIGQUIT, &(sig->sa), NULL);
}

static void	signal_handler(int signal)
{
	if (signal == SIGINT)
		sigint_handler();
	else if (signal == SIGQUIT)
		sigquit_handler();
}

static void	sigint_handler(void)
{
	rl_on_new_line();
	rl_replace_line("^C\n", 0);
	rl_redisplay();
}

static void	sigquit_handler(void)
{
	printf("SIGQUIT recu mais ignore\n");
}
