# Debug expansion configuration
NAME_DEBUG_EXPANSION = debug_expansion
DIR_DEBUG_EXPANSION = $(DIR_OBJ)/debug_expansion/

# Debug source files
DEBUG_EXP_SRCS = $(EXP_DIR)debug_expansion.c $(EXP_DIR)expansion.c $(EXP_DIR)var_expansion.c \
                 $(EXP_DIR)exit_code.c $(EXP_DIR)expansion_utils.c $(SUP_DEPS) $(CUP_DEPS)

DEBUG_EXPANSION_OBJS = $(patsubst %.c, $(DIR_DEBUG_EXPANSION)%.o, $(DEBUG_EXP_SRCS))

# Debug expansion rule
debug_expansion: $(LIB) dir_debug_expansion $(NAME_DEBUG_EXPANSION)

$(NAME_DEBUG_EXPANSION): $(DEBUG_EXPANSION_OBJS)
	@$(CC) $(CFLAGS) -o $@ $(DEBUG_EXPANSION_OBJS) $(LIBS)
	@$(PRINT) "$(G)Debug expansion executable created$(O)"

# Create directories for debug
dir_debug_expansion:
	@mkdir -p $(DIR_DEBUG_EXPANSION)$(EXP_DIR)
	@mkdir -p $(DIR_DEBUG_EXPANSION)$(SUP)
	@mkdir -p $(DIR_DEBUG_EXPANSION)$(CUP)

# Compile debug objects
$(DIR_DEBUG_EXPANSION)%.o: %.c | dir_debug_expansion
	@$(CC) $(CFLAGS) -c $< -o $@

# Run debug
run_debug_expansion: $(NAME_DEBUG_EXPANSION)
	@$(PRINT) "$(G)Running expansion debug...$(O)"
	@./$(NAME_DEBUG_EXPANSION)

# Clean debug files
clean_debug_expansion:
	@$(RM) -rf $(DIR_DEBUG_EXPANSION)
	@$(RM) -f $(NAME_DEBUG_EXPANSION)

.PHONY: debug_expansion run_debug_expansion clean_debug_expansion
