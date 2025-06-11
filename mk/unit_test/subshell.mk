# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    subshell.mk                                        :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jjorda <jjorda@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/05/29 20:15:00 by jjorda            #+#    #+#              #
#    Updated: 2025/06/11 11:00:22 by jjorda           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_SS = subshell_ut

DIR_SS = $(DIR_UT)/
SBS = $(MAN)/parser/lexing/subshell/

SRC_SBS = $(SBS)subshell_parse.c $(SBS)subshell_utils.c $(SBS)subshell_validation.c
UT_SBS = $(SBS)main_test.c $(SRC_SBS) $(SRC_LXR) $(SRC_SUP)

OBJ_SBS = $(patsubst %.c, $(DIR_SS)%.o, $(UT_SBS))

subshell: $(LIB) $(NAME_SS)

$(NAME_SS): $(OBJ_SBS)
	@$(CC) $(CFLAGS) -o $@ $(OBJ_SBS) $(LIBS)
	@$(PRINT) $(BAN_SS)

dir_subshell: dir_lexer dir_setup
	@mkdir -p $(DIR_SS)$(SBS)

$(DIR_SS)$(SBS)%.o: $(SBS)%.c | dir_subshell
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SS)$(LEX)%.o: $(LEX)%.c | dir_subshell
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SS)$(SUP)%.o: $(SUP)%.c | dir_subshell
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

$(DIR_SS)$(EXP)%.o: $(EXP)%.c | dir_subshell
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

BAN_SS = \
"**********************************************" "\n" \
"*$(Y)    _____ _    _ ____   _____ _    _ ______ _      _      $(O)*" "\n" \
"*$(Y)   / ____| |  | |  _ \ / ____| |  | |  ____| |    | |     $(O)*" "\n" \
"*$(Y)  | (___ | |  | | |_) | (___ | |__| | |__  | |    | |     $(O)*" "\n" \
"*$(Y)   \___ \| |  | |  _ < \___ \|  __  |  __| | |    | |     $(O)*" "\n" \
"*$(Y)   ____) | |__| | |_) |____) | |  | | |____| |____| |____ $(O)*" "\n" \
"*$(Y)  |_____/ \____/|____/|_____/|_|  |_|______|______|______| $(O)*" "\n" \
"*$(V) SUBSHELL PARSING - Made by jjorda                        $(O)*" "\n" \
"*$(V) Parentheses and subshell support                         $(O)*" "\n" \
"*$(V) Started : 04/04/2025                                     $(O)*" "\n" \
"**********************************************"