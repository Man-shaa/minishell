NAME		=	minishell

UTILS_DIR	=	utils/

ALLOC_DIR	=	alloc_free/

PARSING_DIR	=	parsing/

CREATE_DIR	=	create_init/

SRCS		=	main.c \
				print/print.c \
				${PARSING_DIR}parsing.c \
				${ALLOC_DIR}alloc_free.c \
				${CREATE_DIR}create.c \
				${UTILS_DIR}list_utils.c \
				${UTILS_DIR}str_utils.c

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