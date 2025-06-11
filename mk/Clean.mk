clean_lib:
	@make clean -s -C $(DIR_LIBFT)
	@make clean -s -C $(DIR_LIBMS)

clean:		clean_lib
	@$(RM)r $(DIR_OBJ)

clean_man:	clean_lib
	@$(RM)r $(DIR)/$(MAN)

clean_bns:	clean_lib
	@$(RM)r $(DIR_BNS)/$(BNS)

clean_ut:	clean_lib
	@$(RM)r $(DIR_UT)