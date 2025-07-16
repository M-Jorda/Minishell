# Test lexer configuration
NAME_TEST_LEXER = test_lexer
DIR_TEST_LEXER = $(DIR_OBJ)/test_lexer/

# Lexer source files
LEX_DIR = $(MAN)/parser/lexing/
LEX_SRCS = $(LEX_DIR)lexer.c $(LEX_DIR)tokenizer.c $(LEX_DIR)token_classifier.c \
           $(LEX_DIR)quotes_handler.c $(LEX_DIR)lexer_utils.c

# Test source files
TEST_SRCS = $(LEX_DIR)main_test.c

# All sources for test
TEST_LEXER_SRCS = $(LEX_SRCS) $(TEST_SRCS)
TEST_LEXER_OBJS = $(patsubst %.c, $(DIR_TEST_LEXER)%.o, $(TEST_LEXER_SRCS))

# Test lexer rule
test_lexer: $(LIB) $(NAME_TEST_LEXER)

$(NAME_TEST_LEXER): $(TEST_LEXER_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(TEST_LEXER_OBJS) $(LIBS)
	@$(PRINT) $(BANNER_TEST_LEXER)

# Create directories for test
dir_test_lexer:
	@mkdir -p $(DIR_TEST_LEXER)$(LEX_DIR)

# Compile test objects
$(DIR_TEST_LEXER)%.o: %.c | dir_test_lexer
	@$(CC) $(CFLAGS) -c $< -o $@

# Run lexer tests
run_lexer_tests: $(NAME_TEST_LEXER)
	@$(PRINT) "$(G)Running lexer tests...$(O)"
	@./$(NAME_TEST_LEXER)

# Clean test files
clean_test_lexer:
	@$(RM) -rf $(DIR_TEST_LEXER)
	@$(RM) -f $(NAME_TEST_LEXER)
	@$(PRINT) "$(G)Test lexer files cleaned$(O)"

# Banner for test lexer
BANNER_TEST_LEXER = \
"**********************************************" "\n" \
"*$(Y)    _     _____ _  _ _____ ____           $(O)*" "\n" \
"*$(Y)   | |   | ____| \| | ____| ___|          $(O)*" "\n" \
"*$(Y)   | |   |  _| |  \\ |  _| |  _|           $(O)*" "\n" \
"*$(Y)   | |___| |___| . || |___| |___          $(O)*" "\n" \
"*$(Y)   |_____|_____|_|\\_|_____|____|          $(O)*" "\n" \
"*$(Y)        TEST SUITE READY                  $(O)*" "\n" \
"*$(V) Made by : jjorda                         $(O)*" "\n" \
"*$(V) Phase 2 : Basic Lexer                    $(O)*" "\n" \
"**********************************************"

.PHONY: test_lexer run_lexer_tests clean_test_lexer
