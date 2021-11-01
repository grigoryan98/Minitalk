CLIENT = client
SERVER = server
CC = gcc
RM = rm -rf
CFLAGS = -Wall -Wextra -Werror
SRCS_SERVER = server.c
SRCS_CLIENT = client.c 
OBJS_CLIENT = ${SRCS_CLIENT:.c=.o}
OBJS_SERVER = ${SRCS_SERVER:.c=.o}

all:  ${SERVER} ${CLIENT}

${SERVER}: ${OBJS_SERVER}
		${CC} ${CFLAGS} ${OBJS_SERVER} -o server
${CLIENT}: ${OBJS_CLIENT}
		${CC} ${CFLAGS} ${OBJS_CLIENT} -o client

clean:
		rm -rf client.o server.o

fclean: clean
	${RM} ${CLIENT} ${SERVER}

re : fclean all


.PHONY: all clean fclean re
