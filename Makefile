NAME		=	minishell

UTILS_DIR	=	utils/

FREE_DIR	=	free/

PARSING_DIR	=	parsing/

BUILTS_DIR	=	builtins/

CREATE_DIR	=	create/

SRCS		=	main_mateo.c \
				main_manu.c \
				print/print.c \
				${BUILTS_DIR}env.c \
				${BUILTS_DIR}export.c \
				${PARSING_DIR}parsing.c \
				${CREATE_DIR}create_data.c \
				${CREATE_DIR}create_list.c \
				${CREATE_DIR}create_env.c \
				${FREE_DIR}free.c \
				${UTILS_DIR}split_env.c \
				${UTILS_DIR}str_utils.c \
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
		${CC} ${CFLAGS} ${OBJS} -o ${NAME}

all:		${NAME}

clean:		
		${RM} ${OBJS}

fclean:		clean
		${RM} ${NAME}
		@echo "\n${GREEN}Everything cleaned${DEFAULT}"

re:			fclean
		$(MAKE) all -j

.PHONY:		all clean fclean re