# Minishell

## Description

Le projet Minishell consiste à développer un interpréteur de commandes simplifié, similaire à Bash ou Zsh, permettant de mieux comprendre le fonctionnement interne d'un shell, notamment la gestion des processus et des descripteurs de fichiers.

## Fonctionnalités

- Affichage d'un prompt interactif
- Historique des commandes exécutées
- Exécution des commandes externes via le `PATH` ou un chemin absolu
- Gestion des quotes simples `'` et doubles `"`
- Redirections :
  - `<` entrée
  - `>` sortie
  - `<<` heredoc
  - `>>` sortie en ajout
- Pipes `|` pour connecter plusieurs commandes
- Gestion des variables d'environnement
- Gestion du statut `$?` de la dernière commande exécutée
- Signaux :
  - `Ctrl-C` interrompt la commande en cours
  - `Ctrl-D` ferme le shell si aucune commande n'est en cours
  - `Ctrl-\` ignoré
- Built-ins :
  - `echo` avec option `-n`
  - `cd` changement de répertoire
  - `pwd` affiche le répertoire courant
  - `export` gestion des variables d'environnement
  - `unset` supprime des variables
  - `env` affiche les variables d'environnement
  - `exit` quitte le shell

## Prérequis

- Linux ou macOS
- Compilateur C (norme C99)
- Bibliothèque readline installée

## Installation

1. Cloner le dépôt :

```
git clone https://github.com/qbnt/3_Minishell.git
cd 3_Minishell
```

2. Compiler :

```
make
```

## Utilisation

- Lancer Minishell :

```
./minishell
```

- Commandes basiques :

```
ls -la
echo "Hello, World!"
```

- Historique : touches fléchées haut/bas
- Redirections et pipes :

```
echo "Hello" > fichier.txt
cat < fichier.txt
ls | grep fichier
```

## Ressources utiles

- [Readline documentation](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Bash Beginners Guide](https://tldp.org/LDP/Bash-Beginners-Guide/html/)

## Licence

Projet sous licence MIT. Voir [LICENSE](LICENSE).
