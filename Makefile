NAME = minishell

SRCS = ft_check_char.c ft_perror.c ft_built_in.c ft_strstr.c ft_bzero.c \
       ft_redirections.c ft_check_command.c ft_putendl.c ft_env_setenv.c \
       ft_strdup.c ft_check_path.c ft_putstr.c ft_strchr.c ft_strsplit.c \
       ft_execute.c ft_shell_launch.c ft_strcmp.c ft_strsub.c ft_get_char.c \
       ft_shell_read_line.c ft_strcpy.c ft_putchar.c ft_split_line.c ft_strjoin.c \
       ft_strlen.c ft_strcat.c ft_putnbr.c main.c ft_strtrim.c ft_strncmp.c

OBJ = $(SRCS:.c=.o)
all: $(NAME)

$(NAME):
	gcc -c $(SRCS)
	gcc -o $(NAME) $(OBJ)

clean:
	/bin/rm -f $(OBJ)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

norme:
	norminette $(SRCS) $(INCL)
