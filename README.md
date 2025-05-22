# Minishell

**As beautiful as a shell**

## 🐚 Overview

Minishell is a project that challenges you to recreate a minimal version of Bash. Through this project, you’ll dive into the core concepts behind command-line interfaces, process handling, file descriptors, and signal management. The goal is to build your own functioning shell that can execute user commands, handle redirections and pipes, manage environment variables, and implement essential built-in commands.

## 📚 What You’ll Learn

This project is a deep dive into some of the most foundational aspects of systems programming in C. It involves working with process creation (`fork`, `execve`), inter-process communication (`pipe`), terminal behavior, and signal handling. You’ll also manage memory carefully to avoid leaks and ensure robustness. 

## ⚙️ Key Features to Implement

The shell should be interactive, with a prompt awaiting user input, a working history, and support for quoting, variable expansion, and basic job control. Core built-in commands like `cd`, `echo`, `env`, `export`, `pwd`, `unset` and `exit` must be reimplemented. You’ll also handle syntax like input/output redirection and pipelines.

The project restricts you to using only one global variable (for return value handling)
