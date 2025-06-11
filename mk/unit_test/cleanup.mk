NAME_CUP= cleanup_ut

DIR_CUP	= $(DIR_OBJ)/
CUP		= $(MAN)/deployment/cleanup/

SRC_CUP	= $(CUP)cleanup.c 
UT_CUP	= $(CUP)main_test.c $(SRC_CUP) $(SRC_SUP)

OBJ_CUP	= $(patsubst %.c, $(DIR_CUP)%.o, $(UT_CUP))

cleanup:	$(LIB) $(NAME_CUP)

$(NAME_CUP):	$(OBJ_CUP)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_CUP) $(LIBS)
	@$(PRINT) $(BAN_CUP)

dir_cleanup: dir_setup
	@mkdir -p $(DIR_CUP)$(CUP)

$(DIR_CUP)$(CUP)%.o: $(CUP)%.c | dir_cleanup
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIR_CUP)$(SUP)%.o: $(SUP)%.c | dir_cleanup
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_CUP	= \
"**********************************************" "\n" \
"*$(Y)    ______ _       _______        ______    $(O)*" "\n" \
"*$(Y)   / _____) |     (_______)  /\  |  ___ \   $(O)*" "\n" \
"*$(Y)  | /     | |      _____    /  \ | |   | |  $(O)*" "\n" \
"*$(Y)  | |     | |     |  ___)  / /\ \| |   | |  $(O)*" "\n" \
"*$(Y)  | \_____| |_____| |_____| |__| | |   | |  $(O)*" "\n" \
"*$(Y)   \______)_______)_______)______|_|   |_|  $(O)*" "\n" \
"*$(V) Made by : alearroy / jjorda                $(O)*" "\n" \
"*$(V) Started : 04/04/2025                       $(O)*" "\n" \
"*$(V) Finished :                                 $(O)*" "\n" \
"**********************************************"
