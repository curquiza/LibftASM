NAME = libfts.a

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, \
	main.s \
	)

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ld $(OBJ) -macosx_version_min 10.8 -lSystem -o $(NAME)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@~/.brew/bin/nasm -f macho64 $< -o $@
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@rm -rf $(OBJ_DIR)

fclean : clean
	@rm -f $(NAME)

re : fclean all
