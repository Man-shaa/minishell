NAME		=	minishell

BUILTS_DIR	=	builtins/

CORE_DIR	=	core/

CREATE_DIR	=	create/

ERROR_DIR	=	error/

EXEC_DIR	=	exec/

FREE_DIR	=	free/

HISTORY_DIR	=	history/

PARSING_DIR	=	parsing/

SPLIT_DIR	=	split/

UTILS_DIR	=	utils/

SRCS		=	main_mateo.c \
				main_manu.c \
				print/print.c \
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
				${CREATE_DIR}create_list.c \
				${CREATE_DIR}create_env.c \
				\
				${ERROR_DIR}error.c \
				\
				${EXEC_DIR}exec.c \
				\
				${FREE_DIR}free.c \
				\
				${HISTORY_DIR}history.c \
				\
				${SPLIT_DIR}split.c \
				${SPLIT_DIR}split_utils.c \
				${SPLIT_DIR}words_utils.c \
				${SPLIT_DIR}chars_utils.c \
				\
				${PARSING_DIR}parsing.c \
				\
				${UTILS_DIR}cmd_utils.c \
				${UTILS_DIR}env_list_utils.c \
				${UTILS_DIR}exec_utils.c \
				${UTILS_DIR}export_utils.c \
				${UTILS_DIR}split_env.c \
				${UTILS_DIR}split_normal.c \
				${UTILS_DIR}str_utils.c \
				${UTILS_DIR}str_utils_2.c \
				${UTILS_DIR}utils.c

OBJS		=	${SRCS:.c=.o}

CC			=	clang

RM			=	rm -rf

GREEN		=	\033[1;32m

DEFAULT		=	\033[0m

CFLAGS		=	-Wall -Werror -Wextra -g3

.c.o:
		${CC} ${CFLAGS} -c $< -o ${<:.c=.o}

$(NAME):	${OBJS}
		${CC} ${CFLAGS} ${OBJS} -o ${NAME} -lreadline

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re