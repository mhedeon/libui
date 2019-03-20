NAME = lll

HDIR = ./headers

HEADERS = $(addprefix $(HDIR)/, window.h)

OBJ_DIR = ./obj

TEST_DIR = ./test

TEST_SRC = main.c

WINDOW_DIR = ./window

WINDOW_SRC = win.c draw.c

SRC_LIST = $(addprefix $(WINDOW_DIR)/, $(WINDOW_SRC))

SRC_LIST += $(addprefix $(TEST_DIR)/, $(TEST_SRC))

OBJ_LIST = $(addprefix $(OBJ_DIR)/, $(WINDOW_SRC:.c=.o))

OBJ_LIST += $(addprefix $(OBJ_DIR)/, $(TEST_SRC:.c=.o))

FLAGS = -Wall -Werror -Wextra

INCLUDES = -I./frameworks/SDL2.framework/Headers/ \
			-I./frameworks/SDL2_image.framework/Headers/ \
			-I./frameworks/SDL2_mixer.framework/Headers/ \
			-I./frameworks/SDL2_ttf.framework/Headers/ \
			-F./frameworks

FRAMEWORKS = -F./frameworks -rpath ./frameworks -framework SDL2 \
												-framework SDL2_image \
												-framework SDL2_mixer \
												-framework SDL2_ttf

all: $(NAME)

$(NAME): $(OBJ_DIR) $(OBJ_LIST) $(HEADERS)
	gcc -o $(NAME) $(OBJ_LIST) $(FRAMEWORKS)

$(OBJ_DIR):
	mkdir $(OBJ_DIR)

$(OBJ_LIST): $(OBJ_DIR)/%.o : $(filter %$*.c, $(SRC_LIST)) $(HEADERS)
	gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -rf $(OBJ_DIR)

fclean: clean
	rm -f $(NAME)

re: fclean all

pr: print-SRC_LIST print-OBJ_LIST print-HEADERS

print-%  : ; @echo $* = $($*)
