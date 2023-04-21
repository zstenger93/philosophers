CC				= cc
SRC_DIR			= src/
OBJ_DIR			= obj/
NAME			= philo
RM				= rm -rf
DN				= > /dev/null
CFLAGS			= -Werror -Wextra -Wall

SOURCE			= init/init \
				  time/time \
				  utils/free \
				  utils/utils \
				  routine/eat \
				  routine/sleep \
				  routine/think \
				  routine/state \
				  time/last_time \
				  threads/threads \
				  routine/routine \
				  init/input_check \
				  main/philosophers \
				  routine/drop_forks \
				  routine/grab_forks \
				  threads/full_check \
				  threads/death_check \

SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo "$(YELLOW)  Compiling: $(DEF_COLOR)$(PURPLE)$(NAME) Mandatory Part By:$(DEF_COLOR) $(RED)zstenger$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(CC) $(CFLAGS) $(OBJ) -g -pthread -o $(NAME) $(DN)

$(OBJ_DIR)%.o : $(SRC_DIR)%.c
	@mkdir -p $(@D)
	@$(CC) -c $< -o $@ $(DN)

clean:
	@echo "$(CYAN)CLEAN$(DEF_COLOR)"
	@echo "$(RED)Deleting objects.$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(RM) $(OBJ_DIR) $(DN)
	@echo "$(RED)Object files have been successfully removed!$(DEF_COLOR)"

fclean:
	@make clean $(DN)
	@echo "$(CYAN)FCLEAN$(DEF_COLOR)"
	@echo "$(RED)Deleting objects, executables.$(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(RM) $(NAME) philo.dSYM $(DN)
	@echo "$(RED)Executable and object files have been successfully removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

.PHONY: all clean fclean re

DEF_COLOR = \033[0;39m
CYAN3 = \033[1;4;96m
YELLOW = \033[1;33m
PURPLE = \033[1;35m
BWhite = \033[1;37m
RED = \033[1;4;91m
GREEN = \033[4;92m
CYAN2 = \x1B[1;36m
CYAN = \033[1;96m
