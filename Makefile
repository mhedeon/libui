NAME = libmgl

TEST_SRC = main.c

WINDOW_SRC = draw.c win.c

WINDOW_OBJ = $(WINDOW_SRC:.c=.o)

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I./frameworks/SDL2.framework/Headers/ \
			-I./frameworks/SDL2_image.framework/Headers/ \
			-I./frameworks/SDL2_mixer.framework/Headers/ \
			-I./frameworks/SDL2_ttf.framework/Headers/ \
			-F./frameworks -I./libft

FRAMEWORKS = -F./frameworks -rpath ./frameworks -framework SDL2 \
												-framework SDL2_image \
												-framework SDL2_mixer \
												-framework SDL2_ttf

all: $(NAME)

$(NAME): $(OBJ)
	@make -C libft
	@gcc -g -o $(NAME) $(OBJ) $(FRAMEWORKS) -L./libft -lft

%.o: %.c
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	@make -C libft clean
	@rm -f $(OBJ)

fclean: clean
	@make -C libft fclean
	@rm -f $(NAME)
	@rm -f $(OBJ)

re: fclean all
	@make -C libft re
