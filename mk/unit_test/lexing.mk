NAME_LX	= lexer_ut

DIR_LX	= $(DIR_UT)
LEX		= $(MAN)/parser/lexing/
EXP		= $(LEX)expansion/

SRC_LXR = $(LEX)lexing.c $(LEX)err.c $(LEX)utils.c $(EXP)expansion.c	\
	$(EXP)expansion_utils.c $(EXP)exit_code.c $(EXP)exp_dquote.c		\
	$(EXP)exp_tok.c
UT_LXR = $(LEX)main_test.c $(SRC_LXR) $(MAN)/deployment/setup/setup.c

OBJ_LXR	= $(patsubst %.c, $(DIR_LX)%.o, $(UT_LXR))

lexing:	$(LIB) $(NAME_LX)

$(NAME_LX): $(OBJ_LXR)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_LXR) $(LIBFT) $(LIBMS) $(LIBFT) -lreadline
	@$(PRINT) $(BAN_LX)

dir_lexer: 
	@mkdir -p $(DIR_LX)$(EXP)

$(DIR_LX)$(LEX)%.o: $(LEX)%.c | dir_lexer
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_LX	= \
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
