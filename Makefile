C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m

NAME	= container

SRCS	= main.cpp

INC_DIRS	= $(VEC) $(MAP) $(STK)

OBJS_DIR	= Objects

VEC	= Vector/ $(addprefix Vector/, Iterators/ MemberFonctions/ NonMemberFonctions/)

MAP	= Map/ $(addprefix Map/, Iterators/ MemberFonctions/ Node/)

STK	= Stack/

OBJS	= $(patsubst %.cpp, $(OBJS_DIR)/%.o, $(SRCS))

HELPERS	= $(addprefix $(HELPER_DIR)/, f1 f2 cmp cmp.d)

HELPER_DIR = Helpers

FLAGS	= -g -Wall -Werror -Wextra -std=c++98 $(foreach D, $(INC_DIRS), -I$(D)) $(DEPFLAGS)

DEPFLAGS	= -MP -MD

CC	= c++

RM	= rm -rf

$(OBJS_DIR)/%.o: %.cpp
	$(CC) $(FLAGS) -c -o $@ $<
	@echo "\t$(C_GREEN)COMPILING $<$(C_END)"

all:	$(NAME)

$(NAME):	$(OBJS)
ifeq ($(ARG), )
	@bash $(HELPER_DIR)/randScript.sh 200
else
	@bash $(HELPER_DIR)/randScript.sh $(ARG)
endif
	@echo "\t$(C_PURPLE)GENERATING RANDOM NUMBER FILE$(C_END)"
	$(CC) $(OBJS) -o $(NAME)
	@echo "\t$(C_PURPLE)BUILDING EXECUTABLE$(C_END)"

update:	main.cpp
	@bash buildCmp.sh
	@echo "\t$(C_CYAN)UPDATING CMP.CPP$(C_END)"
	@$(CC) $(FLAGS) $(HELPER_DIR)/cmp.cpp -o $(HELPER_DIR)/cmp
	@echo "\t$(C_GREEN)COMPILING CMP.CPP$(C_END)"

diff:	all update
ifneq ($(ARG), )
	@./$(NAME) $(ARG) > $(HELPER_DIR)/f1
	@echo "\t$(C_YELLOW)EXECUTING PROGRAM$(C_END)"
	@./$(HELPER_DIR)/cmp $(ARG) > $(HELPER_DIR)/f2
	@echo "\t$(C_YELLOW)EXECUTING CMP$(C_END)"
	@diff $(HELPER_DIR)/f1 $(HELPER_DIR)/f2
	@echo "\t$(C_BLUE)NO DIFFERENCE$(C_END)"
else
	@echo "\t$(C_RED)NO ARG PASSED$(C_END)"
endif


clean:
	@$(RM) $(OBJS)
	@echo "\t$(C_RED)DELEATING OBJECTS$(C_END)"

fclean:		clean
	@$(RM) $(NAME)
	@echo "\t$(C_RED)DELEATING EXECUTABLE$(C_END)"
	@$(RM) $(HELPERS)
	@echo "\t$(C_RED)DELEATING HELPERS$(C_END)"

re:	fclean all

.PHONY:		all clean fclean re
