C_GREY		=	\e[1;30m
C_RED		=	\e[1;31m
C_GREEN		=	\e[1;32m
C_YELLOW	=	\e[1;33m
C_BLUE		=	\e[1;34m
C_PURPLE	=	\e[1;35m
C_CYAN		=	\e[1;36m
C_WHITE		=	\e[1;37m
C_END		=	\e[0m

HELPER_DIR	= Helpers

all:	vec map stk

vec:
	@echo "\t$(C_YELLOW)ENTERING VECTOR DIRECTORY$(C_END)"
	@make --no-print-directory -C Vector/
	@echo "\t$(C_YELLOW)LEAVING VECTOR DIRECTORY$(C_END)"
	@bash $(HELPER_DIR)/copingExec.sh vecExec Vector
	@bash $(HELPER_DIR)/copingExec.sh stl_vecExec Vector

map:
	@echo "\t$(C_YELLOW)ENTERING MAP DIRECTORY$(C_END)"
	@make --no-print-directory -C Map/
	@echo "\t$(C_YELLOW)LEAVING MAP DIRECTORY$(C_END)"
	@bash $(HELPER_DIR)/copingExec.sh mapExec Map
	@bash $(HELPER_DIR)/copingExec.sh stl_mapExec Map

stk:
	@echo "\t$(C_YELLOW)ENTERING STACK DIRECTORY$(C_END)"
	@make --no-print-directory -C Stack/
	@echo "\t$(C_YELLOW)LEAVING STACK DIRECTORY$(C_END)"
	@bash $(HELPER_DIR)/copingExec.sh stkExec Stack
	@bash $(HELPER_DIR)/copingExec.sh stl_stkExec Stack

rand:
ifneq ($(NUM), )
	@echo "\t$(C_PURPLE)GENERATING $(NUM) RANDOM NUMBER FILE$(C_END)"
	@bash $(HELPER_DIR)/randScript.sh $(NUM) >> rand.txt
else
	@echo "\t$(C_RED)NO ARG PASSED$(C_END)"
endif

clean:
	@echo "\t$(C_YELLOW)ENTERING VECTOR DIRECTORY$(C_END)"
	@make clean --no-print-directory -C Vector/
	@echo "\t$(C_YELLOW)LEAVING VECTOR DIRECTORY$(C_END)"
	@echo "\t$(C_YELLOW)ENTERING MAP DIRECTORY$(C_END)"
	@make clean --no-print-directory -C  Map/
	@echo "\t$(C_YELLOW)LEAVING MAP DIRECTORY$(C_END)"
	@echo "\t$(C_YELLOW)ENTERING STACK DIRECTORY$(C_END)"
	@make clean --no-print-directory -C  Stack/
	@echo "\t$(C_YELLOW)LEAVING STACK DIRECTORY$(C_END)"

fclean:	
	@echo "\t$(C_YELLOW)ENTERING VECTOR DIRECTORY$(C_END)"
	@make fclean --no-print-directory -C Vector/
	@echo "\t$(C_YELLOW)LEAVING VECTOR DIRECTORY$(C_END)"
	@echo "\t$(C_YELLOW)ENTERING MAP DIRECTORY$(C_END)"
	@make fclean --no-print-directory -C  Map/
	@echo "\t$(C_YELLOW)LEAVING MAP DIRECTORY$(C_END)"
	@echo "\t$(C_YELLOW)ENTERING STACK DIRECTORY$(C_END)"
	@make fclean --no-print-directory -C  Stack/
	@echo "\t$(C_YELLOW)LEAVING STACK DIRECTORY$(C_END)"
	@echo "\t$(C_RED)DELEATING EXECUTABLES$(C_END)"
	@$(RM) Executables/*

re:	fclean all
