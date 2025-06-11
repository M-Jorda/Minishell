include Makefile.mk

# ************************************ ALL *********************************** #

all:	$(NAME)

$(NAME):	$(OBJS)
	@ar rcs $@ $(OBJS)
	@rm -rf .tmp
# @$(PRINT) ""
# @$(PRINT) ""
	@$(PRINT) $(LIBFT_BANNER)

$(OBJSDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) -c $< -o $@

# ********************************** A.OUT *********************************** #

$(APP):
	@$(FINDBYNAME) $(APP) -delete
	@$(PRINT) "$(G)'$(APP)' files removed"

# ********************************** CLEAN *********************************** #

clean:
	@$(RM) -rf $(OBJSDIR)
	@$(FINDBYNAME) '*.o' -delete
	@$(PRINT) "$(G)object files removed"

# ********************************** FCLEAN ********************************** #

fclean:	clean
	@$(RM) -f $(NAME)
	@$(PRINT) "$(G)Library removed"

# ************************************ RE ************************************ #

re:	fclean all

# ********************************** PHONY *********************************** #

.PHONY:	all a.out clean bonus fclean re

# ********************************* LOADING ********************************** #

# TMPDIR := $(shell mkdir -p .tmp)
# TOTAL_FILES := $(words $(SRCS))
# BAR_WIDTH := $(TOTAL_FILES)

# $(OBJSDIR)/%.o: %.c
# 	@mkdir -p $(dir $@)
# 	@$(CC) $(CFLAGS) -c $< -o $@
# 	@if [ ! -f .tmp/counter ]; then echo "0" > .tmp/counter; fi
# 	@echo "$$(($$(cat .tmp/counter) + 1))" > .tmp/counter
# 	@curr_count=$$(cat .tmp/counter); \
# 	if [ ! -f .tmp/history ]; then touch .tmp/history; fi; \
# 	echo "$(CC) $(CFLAGS) -c $< -o $@" >> .tmp/history; \
# 	clear; \
# 	lines=$$(tput lines); \
# 	history_lines=$$((lines - 3)); \
# 	tput cup $$((lines - 3)) 0; \
# 	printf "Compiling file %d/$(TOTAL_FILES)...\n" "$$curr_count"; \
# 	printf "["; \
# 	printf "%*s" "$$curr_count" | tr ' ' '#'; \
# 	printf "%*s" "$$(($(BAR_WIDTH) - $$curr_count))" | tr ' ' '.'; \
# 	printf "]\n"; \
# 	tput cup 0 0; \
# 	cat .tmp/history | tail -n $$history_lines
