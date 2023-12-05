/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signaux.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 12:37:23 by qbanet            #+#    #+#             */
/*   Updated: 2023/12/05 14:53:21 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	signal_handler(int signal);

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
	TEST1 ;
	if (signal == SIGINT)
		printf("SIGINT recu mais ignore\n");
	else if (signal == SIGQUIT)
		printf("SIGQUIT recu mais ignore\n");
}
