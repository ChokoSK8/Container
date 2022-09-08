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

INCLUDE	= containers.h stack.hpp vector.hpp iterator.hpp const_iterator.hpp

OBJS	= $(SRCS:.cpp=.o)

DEP	= $(OBJS:.o=.d)

FLAGS	= -Wall -Werror -Wextra -MMD -MP -std=c++98

RM	= rm -rf

%.o: %.cpp
	@c++ $(FLAGS) $(INC) -c $< -I .
	@echo "\t$(C_GREEN)COMPILING $<$(C_END)"

all:	$(NAME)

$(NAME):	$(OBJS)
	@c++ $(FLAGS) $(INC) $(OBJS) -o $(NAME)
	@echo "\t$(C_PURPLE)BUILDING EXECUTABLE$(C_END)"

update:	main.cpp
	@awk 'FNR > 5' main.cpp > f1 ; awk 'FNR < 14' cmp.cpp > f2; cat f2 > cmp.cpp ; cat f1 >> cmp.cpp
	@echo "\t$(C_CYAN)UPDATING CMP.CPP$(C_END)"
	@c++ $(FLAGS) cmp.cpp -o cmp
	@echo "\t$(C_GREEN)COMPILING CMP.CPP$(C_END)"

diff:	all update
	@./$(NAME) > f1
	@echo "\t$(C_YELLOW)EXECUTING PROGRAM$(C_END)"
	@./cmp > f2
	@echo "\t$(C_YELLOW)EXECUTING CMP$(C_END)"
	@diff f1 f2
	@echo "\t$(C_BLUE)NO DIFFERENCE$(C_END)"

-include $(DEP)

clean:
	@$(RM) $(OBJS)
	@echo "\t$(C_RED)DELEATING OBJECTS$(C_END)"

fclean:		clean
	@$(RM) $(NAME)
	@echo "\t$(C_RED)DELEATING EXECUTABLE$(C_END)"
	@$(RM) $(DEP)
	@$(RM) f1 f2
	@echo "\t$(C_RED)DELEATING DEPENDENCIES$(C_END)"

re:	fclean all

.PHONY:		all clean fclean re
