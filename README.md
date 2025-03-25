# Minishell

`Minishell` is a group project at 42 focused on building a simplified UNIX shell. It helps students strengthen their understanding of system programming while learning to work effectively in a team.

## 🛠️ Project Overview

The goal is to implement a minimal shell that can parse and execute basic shell commands, including pipes, redirections, and built-in functions — closely mimicking Bash behavior.

## 🚀 Features

- Interactive prompt display
- Command history support
- Execution of external commands via `PATH` or absolute path
- Handling of single `'` and double `"` quotes
- Redirections:
  - `<` input
  - `>` output
  - `<<` heredoc
  - `>>` append output
- Pipes `|` to chain multiple commands
- Environment variables handling
- Support for `$?` to get the last command’s exit status
- Signal management:
  - `Ctrl-C` interrupts the current command
  - `Ctrl-D` exits the shell if no command is running
  - `Ctrl-\` is ignored
- Built-in commands:
  - `echo` with `-n` option
  - `cd` change directory
  - `pwd` display current directory
  - `export` manage environment variables
  - `unset` remove environment variables
  - `env` print environment
  - `exit` exit the shell

## 📦 Requirements

- Linux or macOS
- C compiler (C99 standard)
- Readline library installed

## ⚙️ Installation

1. Clone the repository:

```
git clone https://github.com/qbnt/3_Minishell.git
cd 3_Minishell
```

2. Compile the project:

```
make
```

## 💡 Usage

- Run Minishell:

```
./minishell
```

- Basic commands:

```
ls -la
echo "Hello, World!"
```

- Navigate command history with ↑ ↓ arrows
- Redirections and pipes:

```
echo "Hello" > file.txt
cat < file.txt
ls | grep file
```

## 📚 Useful Resources

- [Readline documentation](https://tiswww.case.edu/php/chet/readline/rltop.html)
- [Bash Beginners Guide](https://tldp.org/LDP/Bash-Beginners-Guide/html/)

## 📄 License

Project licensed under the MIT License. See [LICENSE](LICENSE).
