NAME = libfts.a

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, \
	ft_puts.s \
	)

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $(OBJ)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@~/.brew/bin/nasm -f macho64 $< -o $@
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

c_tests: $(NAME)
	@gcc tests/main.c $(NAME) -o c_tests
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

asm_tests: $(NAME)
	@~/.brew/bin/nasm -f macho64 tests/main.s -o tests/main.o
	@ld tests/main.o $(NAME) -macosx_version_min 10.8 -lSystem -o asm_tests
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

clean :
	@rm -rf $(OBJ_DIR) tests/main.o

fclean : clean
	@rm -f $(NAME) tests/main.o c_tests asm_tests

re : fclean all
