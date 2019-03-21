NAME = libmgl

#------------------------------- HEADERS ---------------------------------------
H_DIR = ./headers

H_LIST = libmgl.h \
			window.h \
			ttf.h

HEADERS = $(addprefix $(H_DIR)/, $(H_LIST))
#-------------------------------------------------------------------------------

#------------------------------- TEST ------------------------------------------
TEST_DIR = ./test

TEST_SRC = main.c

TEST_SRC_LIST = $(addprefix $(TEST_DIR)/, TEST_SRC)
#-------------------------------------------------------------------------------

#------------------------------- WINDOW ----------------------------------------
WINDOW_DIR = ./window

WINDOW_SRC = window_create.c \
				window_update.c \
				error.c \
				pixel.c \
				draw.c

WINDOW_SRC_LIST = $(addprefix $(WINDOW_DIR)/, $(WINDOW_SRC))
#-------------------------------------------------------------------------------

#------------------------------- TTF -------------------------------------------
TTF_DIR = ./ttf

TTF_SRC = ttf.c

TTF_SRC_LIST = $(addprefix $(TTF_DIR)/, $(TTF_SRC))
#-------------------------------------------------------------------------------

#------------------------------- OBJECTS ---------------------------------------
OBJ_DIR = ./obj

OBJ_LIST = $(addprefix $(OBJ_DIR)/, $(TEST_SRC:.c=.o))
OBJ_LIST += $(addprefix $(OBJ_DIR)/, $(WINDOW_SRC:.c=.o))
OBJ_LIST += $(addprefix $(OBJ_DIR)/, $(TTF_SRC:.c=.o))
#-------------------------------------------------------------------------------

#------------------------------- INCLUDES --------------------------------------
FLAGS = -Wall -Werror -Wextra

INCLUDES = -I $(H_DIR) \
 			-I./frameworks/SDL2.framework/Headers/ \
			-I./frameworks/SDL2_image.framework/Headers/ \
			-I./frameworks/SDL2_mixer.framework/Headers/ \
			-I./frameworks/SDL2_ttf.framework/Headers/ \
			-F./frameworks

FRAMEWORKS = -F./frameworks -rpath ./frameworks -framework SDL2 \
												-framework SDL2_image \
												-framework SDL2_mixer \
												-framework SDL2_ttf
#-------------------------------------------------------------------------------

#------------------------------- MAKE ------------------------------------------
all: $(NAME)

$(OBJ_DIR):
	@mkdir $(OBJ_DIR)
#-------------------------------------------------------------------------------

#------------------------------- LINK ------------------------------------------
$(NAME): $(OBJ_DIR) $(OBJ_LIST) $(HEADERS)
	@gcc -o $(NAME) $(OBJ_LIST) $(FRAMEWORKS)
#-------------------------------------------------------------------------------

#------------------------------- COMPILE ---------------------------------------

#------------------------------- TEST
$(OBJ_DIR)/%.o : $(TEST_DIR)/%.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

#------------------------------- WINDOW
$(OBJ_DIR)/%.o : $(WINDOW_DIR)/%.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

#------------------------------- TTF
$(OBJ_DIR)/%.o : $(TTF_DIR)/%.c $(HEADERS)
	@gcc $(FLAGS) -c $< -o $@ $(INCLUDES)

#-------------------------------------------------------------------------------

#------------------------------- CLEAN -----------------------------------------
clean:
	@rm -rf $(OBJ_DIR)

fclean: clean
	@rm -f $(NAME)

re: fclean all
#-------------------------------------------------------------------------------

#------------------------------- DEBUG -----------------------------------------
pr: print-OBJ_LIST print-HEADERS print-QWE

print-%  : ; @echo $* = $($*)
#-------------------------------------------------------------------------------
