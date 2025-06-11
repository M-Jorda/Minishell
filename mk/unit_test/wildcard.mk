NAME_WC	= wcard_ut

DIR_WC	= $(DIR_UT)
WCD		= $(MAN)/parser/lexing/wildcard/

SRC_WCD = $(WCD)wildcard.c $(WCD)wc_files.c $(WCD)wc_match.c $(WCD)wc_tokens.c
UT_WCD = $(WCD)main_test.c $(SRC_WCD)

OBJ_WCD	= $(patsubst %.c, $(DIR_WC)%.o, $(UT_WCD))

wildcard:	$(LIB) $(NAME_WC)

$(NAME_WC): $(OBJ_WCD)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_WCD) $(LIBFT) $(LIBMS) $(LIBFT) -lreadline
	@$(PRINT) $(BAN_WC)

dir_wcard: 
	@mkdir -p $(DIR_WC)$(WCD)

$(DIR_WC)$(WCD)%.o: $(WCD)%.c | dir_wcard
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_WC	= \
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
