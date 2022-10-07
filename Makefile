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

#INCDIR	= Includes/

VECDIR	= Vector/

#STADIR	= Stack/

INC	= -I $(VECDIR)

OBJS	= $(SRCS:.cpp=.o)

#VECDEP	= $(VECDIR)/*.hpp

FLAGS	= -g -Wall -Werror -Wextra -MMD -MP -std=c++98

RM	= rm -rf

%.o: %.cpp	#$(VECDEP)
	c++ $(FLAGS) -c $<
	@echo "\t$(C_GREEN)COMPILING $<$(C_END)"

all:	$(NAME)

$(NAME):	$(OBJS) #$(VECDEP)
ifeq ($(ARG), )
	@bash Utils/randScript.sh 200
else
	@bash Utils/randScript.sh $(ARG)
endif
	@echo "\t$(C_PURPLE)GENERATING RANDOM NUMBER FILE$(C_END)"
	@c++ $(FLAGS) $(OBJS) -o $(NAME)
	@echo "\t$(C_PURPLE)BUILDING EXECUTABLE$(C_END)"

update:	main.cpp
	@bash buildCmp.sh
	@echo "\t$(C_CYAN)UPDATING CMP.CPP$(C_END)"
	@c++ $(FLAGS) Utils/cmp.cpp -o cmp
	@echo "\t$(C_GREEN)COMPILING CMP.CPP$(C_END)"

diff:	all update
ifneq ($(ARG), )
	@./$(NAME) $(ARG) > f1
	@echo "\t$(C_YELLOW)EXECUTING PROGRAM$(C_END)"
	@./cmp $(ARG) > f2
	@echo "\t$(C_YELLOW)EXECUTING CMP$(C_END)"
	@diff f1 f2
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
	@$(RM) cmp.d cmp
	@$(RM) f1 f2
	@echo "\t$(C_RED)DELEATING HELPERS$(C_END)"

re:	fclean all

.PHONY:		all clean fclean re
