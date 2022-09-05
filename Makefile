NAME	= container

SRCS	= main.cpp

INCLUDE	= container.h stack.hpp

OBJS	= $(SRCS:.cpp=.o)

DEP	= $(OBJS:.o=.d)

FLAGS	= -Wall -Werror -Wextra -MMD -MP -std=c++98

RM	= rm -rf

%.o: %.cpp
	c++ $(FLAGS) $(INC) -c $< -I .

all:	$(NAME)

$(NAME):	$(OBJS)
	c++ $(FLAGS) $(INC) $(OBJS) -o $(NAME)

-include $(DEP)

clean:
	$(RM) $(OBJS)

fclean:		clean
	$(RM) $(NAME)
	$(RM) $(DEP)

re:	fclean all

.PHONY:		all clean fclean re
