
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

NAME = minishell

SRCS =  main_utils.c utils.c execute_utils.c export_utils.c exc_cmd.c libft_utils.c echo.c \
		main_utils_1.c cd_utils.c ft_unset.c ft_exit.c env.c export.c libft_utils1.c ft_cd.c pwd.c \
		execute_utils3.c env_null.c redrction.c ft_pipe.c main.c Heredoc_Expansion.c herdoc.c\
		execute_utils4.c heredoc_helper_0.c heredoc_helper_1.c heredoc_helper_2.c  herdoc_1.c \
		cd_utils1.c execute_utils2.c execute.c execute_utils1.c herdoc_2.c  heredoc_helper_3.c \
		parsing/Ambiguous.c             parsing/expand_utils_6.c        parsing/parser_helper.c   \
		parsing/Ambiguous_helper.c      parsing/expand_utils_7.c        parsing/parser_helper_2.c  \
		parsing/add_back_func.c         parsing/expand_utils_8.c        parsing/parser_helper_3.c   \
		parsing/add_one_shlvl.c         parsing/expand_utils_9.c        parsing/parser_helper_4.c    \
		parsing/add_shlvl_node.c        parsing/find_last_node.c        parsing/parsing_main.c        \
		parsing/free_func.c             parsing/parsing_utiles.c       \
		parsing/expand.c                parsing/free_func_1.c           parsing/parsing_utiles_3.c \
		parsing/expand_helper_0.c       parsing/ft_itoa.c               parsing/parsing_utiles_4.c \
		parsing/expand_helper_1.c       parsing/ft_split.c              parsing/parsing_utiles_5.c\
		parsing/expand_helper_10.c      parsing/lexer.c                 parsing/parsing_utiles_6.c\
		parsing/expand_utils.c          parsing/lexer_helper_0.c        parsing/struc_maker.c\
	    parsing/lexer_helper_1.c        parsing/syntx_check.c  			parsing/parser_0.c\
	    parsing/open_files.c            parsing/syntx_check_helper_0.c parsing/expand_utils_12.c  \
		parsing/open_files_helper.c     parsing/syntx_check_helper_1.c  \
		parsing/expand_utils_4.c        parsing/parser.c				parsing/expand_utils_5.c
		 

OBJS = $(SRCS:.c=.o)

INCLUDES = minishell.h parsing/parsing.h

all: $(NAME)

LDLIBS = -lreadline

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LDLIBS)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

run: all
	./$(NAME)

.PHONY: all clean fclean re run
