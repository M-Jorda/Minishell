NAME_PR	= parser_ut

DIR_PR	= $(DIR_UT)
PRR		= $(MAN)/parser/parsing/

SRC_PRR = $(PRR)parsing.c $(PRR)expression.c $(PRR)command.c			\
	$(PRR)redirections.c $(PRR)ast_utils.c
UT_PRR = $(PRR)main_test.c $(PRR)print_ast.c $(SRC_PRR) $(SRC_SUP)		\
	$(SRC_LXR)

OBJ_PRR	= $(patsubst %.c, $(DIR_PR)%.o, $(UT_PRR))

parsing:	$(LIB) $(NAME_PR)

$(NAME_PR): $(OBJ_PRR)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_PRR) $(LIBFT) $(LIBMS) $(LIBFT) -lreadline
	@$(PRINT) $(BAN_PR)

dir_parser: 
	@mkdir -p $(DIR_PR)$(MAN)/parser/lexing/wildcard 
	@mkdir -p $(DIR_PR)$(PRR)

$(DIR_PR)$(PRR)%.o: $(PRR)%.c | dir_parser
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_PR	= \
" **********************************************" "\n" \
"*$(Y)  ______  _______  ______ _______ _______  $(O)*" "\n" \
"*$(Y) (_____ \(_______|_____ (_______|_______)  $(O)*" "\n" \
"*$(Y)  _____) )_______  _____) )______ _____     $(O)*" "\n" \
"*$(Y) |  ____/ _______|______ (_____ |  ___)    $(O)*" "\n" \
"*$(Y) | |     |_______|_____) )____) | |_____   $(O)*" "\n" \
"*$(Y) |_|     |_______|______/_______|_______)  $(O)*" "\n" \
"*$(V) Made by : alearroy / jjorda                $(O)*" "\n" \
"*$(V) Started : 04/04/2025                       $(O)*" "\n" \
"*$(V) Finished :                                 $(O)*" "\n" \
"**********************************************"
