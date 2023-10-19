/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_define.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qbanet <qbanet@student.42perpignan.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 15:07:12 by qbanet            #+#    #+#             */
/*   Updated: 2023/10/19 14:02:48 by qbanet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_DEFINE_H
# define MINISHELL_DEFINE_H

/*Args types*/

# define CMD			0
//Les commandes sont les programmes ou les exécutables à exécuter.
//Exemples : ls, echo, cat, gcc, etc.

# define ARGS			1
//Les arguments sont des valeurs ou des options qui sont passées aux commandes.
//Exemples : file.txt, "-l", "Hello, World!", etc.

# define CONT_OP		2
//Les opérateurs de contrôle sont utilisés pour gérer la séquence d'exécution
//des commandes.
//Exemples : ;, |, &&, ||.

# define ENV_VAR		3
//Les variables d'environnement sont des variables spéciales du système.
//Exemple : $HOME, $USER, $PATH.

# define IN_OUT_REDIR	4
//Les opérateurs de redirection sont utilisés pour gérer la sortie et l'entrée
//standard des commandes.
//Exemples : >, >>, <.

# define QUOT_MARKED	5
//Les guillemets permettent de regrouper des mots en un seul token.
//Exemples : "texte entre guillemets", 'texte entre apostrophes'.

# define ESCAPE_CHAR	6
//Les caractères d'échappement permettent d'ignorer la signification spéciale de
//certains caractères.
//Exemple : \$, \n, \\.

# define SHELL_VAR		7
//Les variables internes au shell contiennent des informations sur le shell
//lui-même.
//Exemple : $$, $?.

# define DIR			8
//Les noms de fichiers et de répertoires sont utilisés dans les commandes pour
//spécifier les chemins.
//Exemples : /chemin/vers/fichier, dossier1/dossier2/fichier.txt.

# define SPC_CHAR		9
//Les caractères spéciaux peuvent être utilisés pour la recherche de fichiers
//(globbing).
//Exemples : *, ?, [, ].

#endif