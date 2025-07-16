# Test expansion configuration
NAME_TEST_EXP = test_expansion
DIR_TEST_EXP = $(DIR_OBJ)/test_expansion/

# Expansion source files
EXP_DIR = $(MAN)/parser/lexing/expansion/
EXP_SRCS = $(EXP_DIR)expansion.c $(EXP_DIR)var_expansion.c $(EXP_DIR)exit_code.c \
           $(EXP_DIR)exp_dquote.c $(EXP_DIR)exp_tok.c $(EXP_DIR)expansion_utils.c \
           $(EXP_DIR)quote_removal.c

# Lexer dependencies
LEX_DIR = $(MAN)/parser/lexing/
LEX_DEPS = $(LEX_DIR)lexer.c $(LEX_DIR)tokenizer.c $(LEX_DIR)token_classifier.c \
           $(LEX_DIR)quotes_handler.c $(LEX_DIR)lexer_utils.c

# Test source files
TEST_EXP_SRCS = $(EXP_DIR)main_test.c

# All sources for test
EXPANSION_TEST_SRCS = $(EXP_SRCS) $(LEX_DEPS) $(TEST_EXP_SRCS)
EXPANSION_TEST_OBJS = $(patsubst %.c, $(DIR_TEST_EXP)%.o, $(EXPANSION_TEST_SRCS))

# Test expansion rule
test_expansion: $(LIB) $(NAME_TEST_EXP)

$(NAME_TEST_EXP): $(EXPANSION_TEST_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(EXPANSION_TEST_OBJS) $(LIBS)
	@$(PRINT) $(BANNER_TEST_EXP)

# Create directories for test
dir_test_expansion:
	@mkdir -p $(DIR_TEST_EXP)$(EXP_DIR)
	@mkdir -p $(DIR_TEST_EXP)$(LEX_DIR)

# Compile test objects
$(DIR_TEST_EXP)%.o: %.c | dir_test_expansion
	@$(CC) $(CFLAGS) -c $< -o $@

# Run expansion tests
run_expansion_tests: $(NAME_TEST_EXP)
	@$(PRINT) "$(G)Running expansion tests...$(O)"
	@./$(NAME_TEST_EXP)

# Clean test files
clean_test_expansion:
	@$(RM) -rf $(DIR_TEST_EXP)
	@$(RM) -f $(NAME_TEST_EXP)
	@$(PRINT) "$(G)Test expansion files cleaned$(O)"

# Banner for test expansion
BANNER_TEST_EXP = \
"**********************************************" "\n" \
"*$(Y)    _____ _  _ ____   ____   _  _  ____   $(O)*" "\n" \
"*$(Y)   | ____| \| |  _ \ / ___| | || ||  _ \  $(O)*" "\n" \
"*$(Y)   |  _| |  \| | |_) \___ \ | || || |_) | $(O)*" "\n" \
"*$(Y)   | |___| . ||  __/ ___) ||_||_||  __/  $(O)*" "\n" \
"*$(Y)   |_____|_|\\_|_|   |____/       |_|     $(O)*" "\n" \
"*$(Y)        EXPANSION TEST SUITE              $(O)*" "\n" \
"*$(V) Made by : jjorda                         $(O)*" "\n" \
"*$(V) Phase 3 : Quotes & Expansion             $(O)*" "\n" \
"**********************************************"

.PHONY: test_expansion run_expansion_tests clean_test_expansion
