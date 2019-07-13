NAME = libfts.a

SRC_DIR = src
SRC = $(addprefix $(SRC_DIR)/, \
	ft_bzero.s \
	ft_strcat.s \
	ft_isalpha.s \
	ft_isdigit.s \
	ft_isalnum.s \
	ft_isascii.s \
	ft_isprint.s \
	ft_toupper.s \
	ft_tolower.s \
	ft_puts.s \
	ft_strlen.s \
	ft_memset.s \
	ft_memcpy.s \
	ft_strdup.s \
	ft_memalloc.s \
	ft_strnew.s \
	ft_strcpy.s \
	ft_strjoin.s \
	ft_strcmp.s \
	)

OBJ_DIR = obj
OBJ = $(SRC:$(SRC_DIR)/%.s=$(OBJ_DIR)/%.o)

C_MAIN = tests/c_main.c
C_MAIN_O = tests/c_main.o
C_EXEC = c_tests

ASM_MAIN = tests/asm_main.s
ASM_MAIN_O = tests/asm_main.o
ASM_EXEC = asm_tests

# NASM = /Users/curquiza/.brew/bin/nasm
NASM = nasm
GCC = gcc -Wall -Wextra -Werror

all : $(NAME)

$(NAME) : $(OBJ)
	@ar rc $@ $(OBJ)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.s
	@mkdir -p $(OBJ_DIR)
	@$(NASM) -f macho64 $< -o $@
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(C_EXEC): $(NAME) $(C_MAIN)
	@$(GCC) -c $(C_MAIN) -o $(C_MAIN_O)
	@$(GCC) $(C_MAIN_O) $(NAME) -o $(C_EXEC)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

$(ASM_EXEC): $(NAME) $(ASM_MAIN)
	@$(NASM) -f macho64 $(ASM_MAIN) -o $(ASM_MAIN_O)
	@ld $(ASM_MAIN_O) $(NAME) -macosx_version_min 10.8 -lSystem -o $(ASM_EXEC)
	@printf "%-45s\033[1;32m%s\033[0m\n" "Make $@" "OK"

run_c_tests: $(C_EXEC)
	@printf "\nEXECUTION:\n"
	@./$(C_EXEC)

run_asm_tests: $(ASM_EXEC)
	@printf "\nEXECUTION:\n"
	@./$(ASM_EXEC)

run_tests: $(C_EXEC) $(ASM_EXEC)
	@printf "\nEXECUTION:\n"
	@printf "\nC:\n"
	@./$(C_EXEC)
	@printf "\nASM:\n"
	@./$(ASM_EXEC)

clean :
	@rm -rf $(OBJ_DIR) $(ASM_MAIN_O) $(C_MAIN)_O

fclean : clean
	@rm -f $(NAME) $(C_EXEC) $(ASM_EXEC)

re : fclean all
