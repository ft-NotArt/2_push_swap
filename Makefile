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
CFLAGS			=	-Wall -Werror -Wextra -g -I. -Ilibft -Ilibft/printf
ARFLAGS			=	rcs

# FILES

FILES			=	push_swap						\
\
					ps_instru/push					\
					ps_instru/swap					\
					ps_instru/rotate				\
					ps_instru/reverse_rotate		\
\
					pars/pars 						\
\
					ps_list/ps_lstnew				\
					ps_list/ps_lstsize				\
					ps_list/ps_lstlast				\
					ps_list/ps_lstsecond_to_last	\
					ps_list/ps_lstadd_back			\
					ps_list/ps_lstclear				\
					ps_list/stacks_init				\
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
#					pactl set-sink-mute 0 false
#					pactl set-sink-volume 0 +500%

clean			:
					$(MAKE) -C $(LIBFT_DIR) $@

fclean			:
					$(MAKE) -C $(LIBFT_DIR) $@
					$(RM) $(NAME)
					echo -e '$(LIGHT_PURPLE) \tCleaned$(DARK_PURPLE) $(NAME)'

re				:	fclean all

# bonus			:	

.PHONY			=	all clean fclean re#!/bin/bash
