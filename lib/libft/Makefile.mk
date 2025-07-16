# *********************************** NAME *********************************** #

NAME	= libft.a

# ****************************** SHELL COMMAND ******************************* #

CC			= clang
RM			= rm
FINDBYNAME	= find -name
PRINT		= echo
WAIT1		= sleep 1
WAIT0.3		= sleep 0.3
ERASE		= printf "\033[2K\r"

# *********************************** REPO *********************************** #

OBJSDIR	= obj

# ********************************** FILES *********************************** #

SRCS	= $(SRC_CON) $(SRC_MEM) $(SRC_PRT) $(SRC_SCH) $(SRC_MAN) $(SRC_SEA) \
		$(SRC_LST) $(SRC_FIL) $(SRC_ERR) $(SRC_MAT)

CONV	= convertion/ft_
SRC_CON	= $(CONV)atoi.c $(CONV)itoa.c $(CONV)tolower.c $(CONV)toupper.c		\
		

MEM		= memory/ft_
SRC_MEM	= $(MEM)calloc.c $(MEM)mallocfailed.c $(MEM)split_arg.c				\
		$(MEM)split.c $(MEM)strdup.c $(MEM)strjoin.c $(MEM)leak.c			\
		$(MEM)strmapi.c $(MEM)strtrim.c $(MEM)substr.c $(MEM)free_vctr.c	\
		$(MEM)strjoin_f.c $(MEM)realloc.c $(MEM)free_arr.c

PRT		= print/ft_
PF		= $(PRT)printf/ft_
PER		= $(PRT)printerr/ft_
SRC_PRT	= $(PRT)putchar_fd.c $(PRT)putendl_fd.c $(PRT)putnbr_fd.c			\
		$(PRT)putstr_fd.c													\
		$(PF)printf.c $(PF)printf_utils.c									\
		$(PER)printerr.c $(PER)printerr_utils.c

SCH		= search/ft_
SRC_SCH	= $(SCH)isalnum.c $(SCH)isalpha.c $(SCH)isascii.c $(SCH)isdigit.c	\
		$(SCH)isprint.c $(SCH)count_word.c $(SCH)isesc.c $(SCH)find_quotes.c\
		$(SCH)isspace.c $(SCH)contains_char.c $(SCH)poschar.c				\
		$(SCH)count_arr.c $(SCH)ismeta.c $(SCH)eov.c

MAN		= manipulation/ft_
SRC_MAN	= $(MAN)bzero.c $(MAN)memcpy.c $(MAN)memmove.c $(MAN)memset.c		\
		$(MAN)striteri.c $(MAN)strlcat.c $(MAN)strlcpy.c $(MAN)strcat.c		\
		$(MAN)strcpy.c $(MAN)strncpy.c $(MAN)strcpy_esc.c					\
		$(MAN)getlast_vctr.c

SEA		= str_search/ft_
SRC_SEA	= $(SEA)memchr.c $(SEA)strcmp.c $(SEA)memcmp.c $(SEA)strchr.c		\
		$(SEA)strlen.c $(SEA)strncmp.c $(SEA)strnstr.c $(SEA)strrchr.c		\
		$(SEA)strlen_esc.c

LST		= list/ft_
SRC_LST	= $(LST)lstnew.c $(LST)lstadd_back.c $(LST)lstn_3.c $(LST)lstlast.c	\
		$(LST)lstadd_front.c $(LST)lstn_2.c $(LST)lstsize.c					\
		$(LST)lstleak.c $(LST)lstrem_n.c $(LST)lstinsert.c					\
		$(LST)lstreplace_n.c

FIL		= file/
GNL		= $(FIL)gnl/get_next_line
SRC_FIL	= $(GNL).c $(GNL)_utils.c $(GNL)_fd.c $(GNL)_utils_fd.c				\
		$(FIL)ft_closefd.c $(FIL)ft_readfile.c

# ERR		= error/ft_
# SRC_ERR	= $(ERR)err.c

MAT		= math/ft_
SRC_MAT	= $(MAT)ran.c

# ********************************* OBJECTS ********************************** #

OBJS	= $(patsubst %.c, $(OBJSDIR)/%.o, $(SRCS))

APP		= a.out

# ********************************** BANNER ********************************** #

LIBFT_BANNER	= \
	"" "\n" \
	"" "\n" \
	"$(G)Library $@ successfully created$(O)" "\n" \
	"*****************************************" "\n" \
	"*$(Y)   _     __________  _______ _______   $(O)*" "\n" \
	"*$(Y)  (_)   (_____)__  \(_______)_______)  $(O)*" "\n" \
	"*$(Y)   _       _ ____)  )_____      _      $(O)*" "\n" \
	"*$(Y)  | |     | |  __  (|  ___)    | |     $(O)*" "\n" \
	"*$(Y)  | |_____| |_|__)  ) |        | |     $(O)*" "\n" \
	"*$(Y)  |_______)___)____/|_|        |_|     $(O)*" "\n" \
	"*$(V)  Made by : jjorda                     $(O)*" "\n" \
	"*$(V)  Finished : 27/09/2024                $(O)*" "\n" \
	"*$(V)  all a.out clean bonus fclean re      $(O)*" "\n" \
	"*****************************************"

# *********************************** COLOR ********************************** #

# BLACK
O	= \033[0m

#RED
R	= \033[0;31m
#GREEN
G	= \033[0;32m
#YELLOW
Y	= \033[0;33m
#VIOLET
V	= \033[0;34m