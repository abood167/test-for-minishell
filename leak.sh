valgrind -s --track-fds=yes --tool=memcheck  --trace-children=yes --leak-check=full --show-leak-kinds=all --suppressions=.ignore_readline.txt ./minishell