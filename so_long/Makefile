SRCS = src/so_long.c src/images.c src/filevalidation.c src/move.c src/extra.c src/swap.c src/count.c utils/ft_bzero.c utils/ft_calloc.c utils/ft_itoa.c utils/ft_memset.c utils/ft_printf.c utils/ft_putbases.c utils/ft_putchar_fd.c utils/ft_putendl_fd.c utils/ft_putnbr.c utils/ft_putstr_fd.c utils/ft_strchr.c utils/ft_strdup.c utils/ft_strjoin.c utils/ft_strlen.c utils/ft_strncmp.c utils/ft_substr.c utils/get_next_line.c
OBJS = ${SRCS:.c=.o}
CC = cc
CFLAGS = -Wall -Wextra -Werror
NAME = so_long
INCLUDE = -I /usr/local/include
MLX = -L /usr/local/lib/ -lmlx -framework OpenGL -framework AppKit

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${INCLUDE} ${OBJS} ${MLX} -o ${NAME} ${LIBFT}
clean:
	rm -f ${OBJS}
fclean: clean
	rm -f ${NAME}
re: fclean all