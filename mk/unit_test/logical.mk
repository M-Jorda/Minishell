NAME_LG	= logical_ut

DIR_LG	= $(DIR_UT)
LGOP	= $(MAN)/parser/lexing/logic_operator

SRC_LGR = $(LGOP)logical
UT_LGC = $(LGOP)main_test.c $(SRC_LGR) $(MAN)/deployment/setup/setup.c

OBJ_LGC	= $(patsubst %.c, $(DIR_LG)%.o, $(UT_LGC))

LGOPing:	$(LIB) $(NAME_LG)

$(NAME_LG): $(OBJ_LGC)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_LGC) $(LIBFT) $(LIBMS) $(LIBFT) -lreadline
	@$(PRINT) $(BAN_LG)

dir_LGOPer: 
	@mkdir -p $(DIR_LG)$(LGOP)

$(DIR_LG)$(LGOP)%.o: $(LGOP)%.c | dir_LGOPer
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_LG	= \
" **********************************************" "\n" \
"*$(Y)   _       _______ _    _ _______ ______    $(O)*" "\n" \
"*$(Y)  | |     (_______) \  / (_______|_____ \   $(O)*" "\n" \
"*$(Y)  | |      _____   \ \/ / _____   _____) )  $(O)*" "\n" \
"*$(Y)  | |     |  ___)   )  ( |  ___) |  ___ (   $(O)*" "\n" \
"*$(Y)  | |_____| |_____ / /\ \| |_____| |   | |  $(O)*" "\n" \
"*$(Y)  |_______)_______)_/  \_\_______)_|   |_|  $(O)*" "\n" \
"*$(V) Made by : alearroy / jjorda                $(O)*" "\n" \
"*$(V) Started : 04/04/2025                       $(O)*" "\n" \
"*$(V) Finished :                                 $(O)*" "\n" \
"**********************************************"
