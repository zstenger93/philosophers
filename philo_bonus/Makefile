CC				= cc
SRC_DIR			= philo_bonus/
OBJ_DIR			= obj/
RM				= rm -rf
NAME			= philo_bonus
DN				= > /dev/null

SOURCE			= src/philosophers


SRC				= $(addprefix $(SRC_DIR), $(addsuffix .c, $(SOURCE)))
OBJ				= $(addprefix $(OBJ_DIR), $(addsuffix .o, $(SOURCE)))

all: $(NAME)

$(NAME): $(OBJ)
	@echo ""
	@echo "$(YELLOW)  Compiling: $(DEF_COLOR)$(PURPLE)$(NAME) Mandatory Part By:$(DEF_COLOR) $(RED)zstenger(DEF_COLOR)"
	@echo "$(CYAN2)" $(DN)
	@$(CC) $(CFLAGS) $(OBJ) -g -pthread -o philosophers $(DN)

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
	@$(RM) $(NAME) $(DN)
	@echo "$(RED)Executable and object files have been successfully removed.$(DEF_COLOR)"

re: fclean all
	@echo "$(RED)Files have been cleaned and project has been rebuilt!$(DEF_COLOR)"

.PHONY: all clean fclean re
