# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ggalon <ggalon@student.42lyon.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/06 15:27:49 by ggalon            #+#    #+#              #
#    Updated: 2023/12/06 20:56:57 by ggalon           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# DIRECTORIES ==================================================================

SRCS_LIBFT_DIR	=	src/libft/

SRCS_PRINTF_DIR	=	src/ft_printf/

SRCS_GNL_DIR	=	src/get_next_line/

OBJS_DIR		=	obj/

OBJS_LIBFT_DIR	=	$(OBJS_DIR)libft/

OBJS_PRINTF_DIR	=	$(OBJS_DIR)ft_printf/

OBJS_GNL_DIR	=	$(OBJS_DIR)get_next_line/

INCL_DIR		=	inc/

# FILES ========================================================================

NAME_LIBFT	= 	libft.a

SRCS_LIBFT	=	ft_isalnum.c ft_isprint.c ft_memcmp.c ft_putchar_fd.c ft_split.c \
				ft_strlcat.c ft_strncmp.c ft_substr.c ft_atoi.c ft_isalpha.c \
				ft_itoa.c ft_memcpy.c ft_putendl_fd.c ft_strchr.c ft_strlcpy.c \
				ft_strnstr.c ft_tolower.c ft_bzero.c ft_isascii.c ft_arrayclear.c \
				ft_memmove.c ft_putnbr_fd.c ft_strdup.c ft_strlen.c ft_strrchr.c \
				ft_toupper.c ft_calloc.c ft_isdigit.c ft_memchr.c ft_memset.c \
				ft_putstr_fd.c ft_strjoin.c ft_strmapi.c ft_strtrim.c ft_striteri.c

SRCS_PRINTF =	ft_printf.c ft_putchar.c ft_putstr.c ft_putnbr.c ft_putunbr.c \
				ft_putptr.c ft_puthexlowernbr.c ft_puthexuppernbr.c \
				ft_countstr.c ft_countdecnbr.c ft_countdecunbr.c ft_counthexnbr.c \
				ft_countptrnbr.c ft_percent_count.c ft_percent_put.c

SRCS_GNL	=	get_next_line.c get_next_line_utils.c

OBJS_LIBFT	=	$(addprefix $(OBJS_LIBFT_DIR), $(SRCS_LIBFT:.c=.o))

OBJS_PRINTF	=	$(addprefix $(OBJS_PRINTF_DIR), $(SRCS_PRINTF:.c=.o))

OBJS_GNL	=	$(addprefix $(OBJS_GNL_DIR), $(SRCS_GNL:.c=.o))

INCL		=	$(addprefix $(INCL_DIR), libft.h get_next_line.h ft_printf.h)

# COMMANDS =====================================================================

CC			=	cc

CC_FLAGS	=	-Wall -Wextra -Werror

AR			=	ar

AR_FLAGS	=	-rc

# RULES ========================================================================

all:
	@echo "\n${BIBlue}Compilation of Libft source files...${NC}"
	@mkdir -p $(OBJS_DIR) $(OBJS_LIBFT_DIR) $(OBJS_PRINTF_DIR) $(OBJS_GNL_DIR)
	@$(MAKE) --no-print-directory $(NAME_LIBFT)
	@echo "\n${BIGreen}Libft Ready !${NC}"

$(NAME_LIBFT): $(OBJS_LIBFT) $(OBJS_PRINTF) $(OBJS_GNL)
	@echo "\n${BICyan}Creating the library...${NC}"
	$(AR) $(AR_FLAGS) $@ $^

$(OBJS_LIBFT_DIR)%.o: $(SRCS_LIBFT_DIR)%.c $(INCL) Makefile
	$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJS_PRINTF_DIR)%.o: $(SRCS_PRINTF_DIR)%.c $(INCL) Makefile
	$(CC) $(CC_FLAGS) -c $< -o $@

$(OBJS_GNL_DIR)%.o: $(SRCS_GNL_DIR)%.c $(INCL) Makefile
	$(CC) $(CC_FLAGS) -c $< -o $@

clean:
	@echo "\n${BIRed}Libft binary deletion...${NC}"
	rm -rf $(OBJS_DIR)

fclean:
	@echo "\n${BIRed}Libft deletion...${NC}"
	rm -rf $(OBJS_DIR)
	rm -f $(NAME_LIBFT)

re: fclean all

.PHONY: all clean fclean re

# COLORS =======================================================================

# Reset
NC=\033[0m

# Regular Colors
Black=\033[0;30m
Red=\033[0;31m
Green=\033[0;32m
Yellow=\033[0;33m
Blue=\033[0;34m
Purple=\033[0;35m
Cyan=\033[0;36m
White=\033[0;37m

# Bold
BBlack=\033[1;30m
BRed=\033[1;31m
BGreen=\033[1;32m
BYellow=\033[1;33m
BBlue=\033[1;34m
BPurple=\033[1;35m
BCyan=\033[1;36m
BWhite=\033[1;37m

# Underline
UBlack=\033[4;30m
URed=\033[4;31m
UGreen=\033[4;32m
UYellow=\033[4;33m
UBlue=\033[4;34m
UPurple=\033[4;35m
UCyan=\033[4;36m
UWhite=\033[4;37m

# Background
On_Black=\033[40m
On_Red=\033[41m
On_Green=\033[42m
On_Yellow=\033[43m
On_Blue=\033[44m
On_Purple=\033[45m
On_Cyan=\033[46m
On_White=\033[47m

# High Intensity
IBlack=\033[0;90m
IRed=\033[0;91m
IGreen=\033[0;92m
IYellow=\033[0;93m
IBlue=\033[0;94m
IPurple=\033[0;95m
ICyan=\033[0;96m
IWhite=\033[0;97m

# Bold High Intensity
BIBlack=\033[1;90m
BIRed=\033[1;91m
BIGreen=\033[1;92m
BIYellow=\033[1;93m
BIBlue=\033[1;94m
BIPurple=\033[1;95m
BICyan=\033[1;96m
BIWhite=\033[1;97m

# High Intensity backgrounds
On_IBlack=\033[0;100m
On_IRed=\033[0;101m
On_IGreen=\033[0;102m
On_IYellow=\033[0;103m
On_IBlue=\033[0;104m
On_IPurple=\033[0;105m
On_ICyan=\033[0;106m
On_IWhite=\033[0;107m
