NAME		=	minishell

OBJS_DIR	=	objs

BUILTS_DIR	=	builtins/

CORE_DIR	=	core/

CREATE_DIR	=	create/

ERROR_DIR	=	error/

EXEC_DIR	=	exec/

FREE_DIR	=	free/

PARSING_DIR	=	parsing/

SIGNAL_DIR	=	signal/

SPLIT_DIR	=	split/

UTILS_DIR	=	utils/

SRCS		=	main.c \
				print/print_1.c \
				print/print_2.c \
				\
				${BUILTS_DIR}builtins.c \
				${BUILTS_DIR}cd.c \
				${BUILTS_DIR}echo.c \
				${BUILTS_DIR}env.c \
				${BUILTS_DIR}exit.c \
				${BUILTS_DIR}export.c \
				${BUILTS_DIR}pwd.c \
				${BUILTS_DIR}unset.c \
				\
				${CORE_DIR}core.c \
				\
				${CREATE_DIR}create_cmd.c \
				${CREATE_DIR}create_data.c \
				${CREATE_DIR}create_env.c \
				${CREATE_DIR}create_list.c \
				${CREATE_DIR}create_proc.c \
				${CREATE_DIR}fill_cmd.c \
				\
				${ERROR_DIR}error.c \
				\
				${EXEC_DIR}exec.c \
				${EXEC_DIR}heredoc.c \
				${EXEC_DIR}pipe.c \
				${EXEC_DIR}redirections.c \
				\
				${FREE_DIR}free_2.c \
				${FREE_DIR}free.c \
				\
				${SPLIT_DIR}split.c \
				${SPLIT_DIR}split_utils.c \
				${SPLIT_DIR}split_index.c \
				${SPLIT_DIR}words_utils.c \
				${SPLIT_DIR}chars_utils.c \
				${SPLIT_DIR}chars_quotes.c \
				\
				${PARSING_DIR}dollars.c \
				${PARSING_DIR}fill_dollar.c \
				${PARSING_DIR}parsing.c \
				${PARSING_DIR}quotes_utils.c \
				${PARSING_DIR}quotes.c \
				\
				${SIGNAL_DIR}signal_2.c \
				${SIGNAL_DIR}signal.c \
				\
				${UTILS_DIR}cmd_utils_two.c \
				${UTILS_DIR}cmd_utils.c \
				${UTILS_DIR}env_list_utils.c \
				${UTILS_DIR}exec_utils.c \
				${UTILS_DIR}heredoc_utils.c \
				${UTILS_DIR}export_utils.c \
				${UTILS_DIR}redirections_utils.c \
				${UTILS_DIR}split_echo.c \
				${UTILS_DIR}split_env.c \
				${UTILS_DIR}split_normal.c \
				${UTILS_DIR}str_utils_2.c \
				${UTILS_DIR}str_utils_3.c \
				${UTILS_DIR}str_utils.c \
				${UTILS_DIR}utils.c

OBJS		=	${SRCS:%.c=${OBJS_DIR}/%.o}

CC			=	clang

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -lreadline

$(OBJS_DIR)/%.o: %.c | $(OBJS_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJS_DIR) :
	@ mkdir -p $@
	@ mkdir -p objs/print/
	@ mkdir -p objs/builtins/
	@ mkdir -p objs/core/
	@ mkdir -p objs/create/
	@ mkdir -p objs/error/
	@ mkdir -p objs/exec/
	@ mkdir -p objs/free/
	@ mkdir -p objs/history/
	@ mkdir -p objs/parsing/
	@ mkdir -p objs/signal/
	@ mkdir -p objs/split/
	@ mkdir -p objs/utils/

all:		${NAME}

clean:		
		# ${RM} ${OBJS}
		${RM} ${OBJS_DIR}

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re