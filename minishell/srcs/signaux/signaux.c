/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:37:23 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/07 10:31:49 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_handler(int signal, siginfo_t *sf, void *oui);
static void	sigint_handler(void);
static void	sigquit_handler(int signal, siginfo_t *sf);

/*============================================================================*/

void	signaux(t_mini *ms)
{
	struct sigaction	sa;

	ms += 0;
	sigemptyset(&sa.sa_mask);
	sa.sa_sigaction = signal_handler;
	sa.sa_flags = SA_SIGINFO | SA_RESTART;
	sigaction(SIGINT, &sa, 0);
	sigaction(SIGQUIT, &sa, 0);
}

static void	signal_handler(int signal, siginfo_t *sf, void *oui)
{
	oui += 0;
	sf += 0;
	if (signal == SIGINT)
		sigint_handler();
	else if (sf->si_pid == 0 && signal == SIGQUIT)
		sigquit_handler(signal, sf);
}

static void	sigint_handler(void)
{
	ft_printf("\n");
	rl_replace_line("", 0);
	rl_on_new_line();
	rl_redisplay();
}

static void	sigquit_handler(int signal, siginfo_t *sf)
{
	kill(sf->si_pid, signal);
}
