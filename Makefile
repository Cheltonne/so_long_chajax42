NAME = so_long

CC = gcc
CFLAGS = -Wall -Wextra -Werror
FLAGS = -Lminilibx-linux -lmlx -lXext -lX11
RM = rm -f

GAME_FILES = end_of_game \
	     libft_functions \
	     parser \
	     parser2 \
	     parser3 \
	     rendering \
	     so_long \
	     so_long_utils \
	     so_long_utils2 \
	     start_of_game \

GNL_FILES = get_next_line \
	    get_next_line_utils \
	    get_next_line_utils2 \

GAME_DIR = game/
GNL_DIR = get_next_line/
GAME_SRCS = $(addprefix $(GAME_DIR), $(addsuffix .c, $(GAME_FILES))) \
	$(addprefix $(GNL_DIR), $(addsuffix .c, $(GNL_FILES))) \

OBJS =	$(addprefix $(GAME_DIR), $(addsuffix .o, $(GAME_FILES))) \
	$(addprefix $(GNL_DIR), $(addsuffix .o, $(GNL_FILES))) \

.c.o: $(SRCS)
	$(CC) $(CFLAGS) -c -o $@ $<

$(NAME): $(OBJS)
	make -C minilibx-linux
	$(CC) $(CFLAGS) -o $@ $^ $(FLAGS)

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: clean all

.PHONY: bonus all clean fclean re
