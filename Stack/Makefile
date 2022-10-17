C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m

NAME	= stkExec

SRCS	= main.cpp

OBJS_DIR	= Objects

OBJS	= $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

HELPER_DIR	= Helpers

FLAGS	= -g -Wall -Werror -Wextra -std=c++98

CC	= c++

RM	= rm -rf

HELPERS	= $(addprefix $(HELPER_DIR)/, f1 f2)

$(OBJS_DIR)/%.o: %.cpp
	@c++ $(FLAGS) -o $@ -D NAMESPACE=ft -c $?
	@echo "\t$(C_GREEN)COMPILING $<$(C_END)"

all:	$(NAME)

$(NAME):	$(OBJS)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\t$(C_PURPLE)BUILDING EXECUTABLE WITH NAMESPACE=FT$(C_END)"

diff:	all
ifneq ($(ARG), )
	@./$(NAME) $(ARG) > $(HELPER_DIR)/f1
	@echo "\t$(C_YELLOW)EXECUTING PROGRAM WITH NAMESPACE=FT$(C_END)"
	@$(CC) $(FLAGS) main.cpp -D NAMESPACE=std -o $(NAME)
	@echo "\t$(C_PURPLE)BUILDING EXECUTABLE WITH NAMESPACE=STD$(C_END)"
	@./$(NAME) $(ARG) > $(HELPER_DIR)/f2
	@echo "\t$(C_YELLOW)EXECUTING PROGRAM WITH NAMESPACE=STD$(C_END)"
	@diff $(HELPER_DIR)/f1 $(HELPER_DIR)/f2
	@echo "\t$(C_BLUE)NO DIFFERENCE$(C_END)"
else
	@echo "\t$(C_RED)NO ARG PASSED$(C_END)"
endif

rand:
ifneq ($(NUM), )
	@bash $(HELPER_DIR)/randScript.sh $(NUM) >> rand.txt
	@echo "\t$(C_PURPLE)GENERATING $(NUM) RANDOM NUMBER FILE$(C_END)"
else
	@echo "\t$(C_RED)HOW TO USE: make rand NUM=<number>$(C_END)"
endif

std:
ifneq ($(ARG), )
	@echo "\t$(C_PURPLE)BUILDING EXECUTABLE WITH NAMESPACE=STD$(C_END)"
	@$(CC) $(FLAGS) main.cpp -D NAMESPACE=std -o $(NAME)
	@echo "\t$(C_YELLOW)EXECUTING PROGRAM WITH NAMESPACE=STD$(C_END)"
	@./$(NAME) $(ARG)
else
	@echo "\t$(C_RED)NO ARG PASSED$(C_END)"
endif

clean:
	@$(RM) $(HELPERS)
	@echo "\t$(C_RED)DELEATING HELPERS$(C_END)"
	@$(RM) $(OBJS)
	@echo "\t$(C_RED)DELEATING OBJECTS$(C_END)"

fclean:		clean
	@$(RM) $(NAME)
	@echo "\t$(C_RED)DELEATING EXECUTABLE$(C_END)"

re:	fclean all

.PHONY:		all clean fclean re
