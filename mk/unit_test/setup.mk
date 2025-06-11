NAME_SUP= setup_ut

DIR_SUP	= $(DIR_UT)
SUP		= $(MAN)/deployment/setup/

SRC_SUP	= $(SUP)setup.c 
UT_SUP	= $(SUP)main_test.c $(SRC_SUP)

OBJ_SUP	= $(patsubst %.c, $(DIR_SUP)%.o, $(UT_SUP))

setup:	$(LIB) $(NAME_SUP)

$(NAME_SUP):	$(OBJ_SUP)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_SUP) $(LIBS)
	@$(PRINT) $(BAN_SUP)

dir_setup:
	@mkdir -p $(DIR_SUP)$(SUP)

$(DIR_SUP)$(SUP)%.o: $(SUP)%.c | dir_setup
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_SUP	= \
"**********************************************" "\n" \
"*$(Y)      _    _______ _______ _     _ ______   $(O)*" "\n" \
"*$(Y)     | |  (_______)_______) |   | (_____ \  $(O)*" "\n" \
"*$(Y)      \ \  _____   _      | |   | |_____) ) $(O)*" "\n" \
"*$(Y)       \ \|  ___) | |     | |   | |  ____/  $(O)*" "\n" \
"*$(Y)   _____) ) |_____| |_____| |___| | |       $(O)*" "\n" \
"*$(Y)  (______/|_______)\______)\______|_|       $(O)*" "\n" \
"*$(V) Made by : alearroy / jjorda                $(O)*" "\n" \
"*$(V) Started : 04/04/2025                       $(O)*" "\n" \
"*$(V) Finished :                                 $(O)*" "\n" \
"**********************************************"
