fclean_lib: 
	@make fclean -s -C $(DIR_LIBFT)
	@make fclean -s -C $(DIR_LIBMS)

fclean:		clean fclean_lib
	@$(RM) $(NAME) $(NAME_BNS) $(NAME_ALL) $(NAME_UT)

fclean_man:	clean_man fclean_lib
	@$(RM) $(NAME)

fclean_bns:	clean_bns fclean_lib
	@$(RM) $(NAME_BNS)

fclean_ut: clean_ut fclean_lib
	@$(RM) $(NAME_UT)