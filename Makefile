# COLORS

PURPLE			=	\x1b[0m\x1b[38;2;153;37;190m
LIGHT_PURPLE	=	\x1b[0m\x1b[38;2;184;102;210m
DARK_PURPLE		=	\x1b[1m\x1b[38;2;107;26;133m
DARK_GREEN		=	\x1b[1m\x1b[38;2;51;133;26m

# TARGET

NAME			=	push_swap

LIBFT			=	libft.a
LIBFT_DIR		=	libft
LIBFT_PATH		=	$(LIBFT_DIR)/$(LIBFT)

# FLAGS

MAKEFLAGS		+=	-s
CFLAGS			=	-Wall -Werror -Wextra -g -Ilibft -Ilibft/printf
ARFLAGS			=	rcs

# FILES

FILES			=	push_swap						\
\
					push swap rotate reverse_rotate	\
\

SRC				=	$(addsuffix .c, $(FILES))
OBJ				=	$(addsuffix .o, $(FILES))

# RULES

all				:	$(NAME)

$(LIBFT_PATH)	:
					$(MAKE) -C $(LIBFT_DIR) $(LIBFT) -j $$(nproc)

$(NAME)			:	$(SRC) | $(LIBFT_PATH)
					$(CC) $(CFLAGS) $^ $(LIBFT_PATH) -o $@
					echo -e '$(LIGHT_PURPLE) \tCompiled$(DARK_PURPLE) $@'

clean			:
					$(MAKE) -C $(LIBFT_DIR) $@

fclean			:
					$(MAKE) -C $(LIBFT_DIR) $@
					$(RM) $(NAME)
					echo -e '$(LIGHT_PURPLE) \tCleaned$(DARK_PURPLE) $(NAME)'

re				:	fclean all

# bonus			:	

.PHONY			=	all clean fclean re