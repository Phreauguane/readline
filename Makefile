.ONESHELL:

LIB			=	libftreadline.a

EXEC		=	readline

FILES		=	ft_readline		\
				get_input		\
				mode

CC			=	cc -Wall -Wextra -Werror

INCLUDE		=	-I includes

SRC_DIR		=	src/

OBJ_DIR		=	obj/

NO_OF_FILES := $(words $(FILES))

LIBFT_PATH	=	./libft/

LIBFT_FILE	=	libft.a

LIBFT_LIB	=	$(addprefix $(LIBFT_PATH), $(LIBFT_FILE))

DEF			=	"\033[0m"
BG_GREEN	=	"\033[48;2;0;200;0m"
BG_RED		=	"\033[48;2;210;0;0m"
FG_RED		=	"\033[38;2;210;0;0m"
FG_BLUE		=	"\033[38;2;0;70;200m"
FG_GREEN	=	"\033[38;2;0;200;0m"
BG_BLACK	=	"\033[48;2;0;0;0m"

PROG = 5
FILE = 6
TOP = 7
MID = 8
BOT = 9
SUCCESS = 10

all			:	progress

progress	:	lib
	@mkdir -p $(OBJ_DIR)
	@tput cup $(PROG) 0
	@echo -n $(DEF)$(FG_BLUE)Compiling $(FG_GREEN)$(EXEC)$(DEF) "                                                   "
	@tput cup $(TOP) 0
	@echo -n "▁▁▁▁▁▁▁▁▁▁"
	@for file in $(FILES); do \
		echo -n "▁";\
	done;
	@tput cup $(MID) 0
	@echo -n $(BG_BLACK)"Progress ▕"
	@for file in $(FILES); do \
		echo -n $(BG_BLACK)" "$(DEF);\
	done;
	@tput cup $(BOT) 0
	@echo -n "▔▔▔▔▔▔▔▔▔▔"
	@for file in $(FILES); do \
		echo -n "▔";\
	done;
	@tput cup $(MID) 10
	@for file in $(FILES); do
		$(CC) $(INCLUDE) -c $(SRC_DIR)$$file.c -o $(OBJ_DIR)$$file.o 2>> compil.log
		if [ "$$?" = "0" ]; then
			echo -n $(BG_GREEN)" "$(DEF)
		else
			echo -n $(BG_RED)" "$(DEF)
		fi
		tput sc
		tput cup $(FILE) 0
		echo -n $(FG_GREEN)$$file$(DEF) "              "
		tput rc
		sleep .01
	done;
	@tput cup $(FILE) 0
	@echo -n "              "
	$(CC) $(INCLUDE) -c main.c -o main.o 2>> compil.log
	@$(CC) $(OBJ_DIR)/*.o main.o -o $(EXEC) $(LIBFT_LIB) $(INCLUDE) 2>> compil.log
	@tput cup $(SUCCESS) 0
	@echo -n $(FG_RED)
	@cat compil.log
	@echo -n $(DEF)
	@echo $(HEADER)
	@rm -f compil.log

lib			:
	@make -C $(LIBFT_PATH)

clean_lib	:
	@make clean -sC $(LIBFT_PATH)

clean		:	clean_lib
	@rm -rf obj main.o

fclean		:	clean
	@rm -f $(EXEC)