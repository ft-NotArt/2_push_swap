# COLORS

PURPLE			=	\x1b[0m\x1b[38;2;153;37;190m
LIGHT_PURPLE	=	\x1b[0m\x1b[38;2;184;102;210m
DARK_PURPLE		=	\x1b[1m\x1b[38;2;107;26;133m
DARK_GREEN		=	\x1b[1m\x1b[38;2;51;133;26m

# TARGET

NAME			=	push_swap
CHECKER			=	checker

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
					ps_pars/pars 					\
\
					ps_list/ps_lstnew				\
					ps_list/ps_lstsize				\
					ps_list/ps_lstlast				\
					ps_list/ps_lstsecond_to_last	\
					ps_list/ps_lstadd_back			\
					ps_list/ps_lstclear				\
					ps_list/stacks					\
\
					ps_sort/sort_array				\
					ps_sort/sort_stack				\
					ps_sort/sort_stage_one			\
					ps_sort/sort_stage_two			\
					ps_sort/sort_stage_three		\
					ps_sort/sort_utils				\
\

SRC				=	$(addsuffix .c, $(FILES))
OBJ				=	$(addsuffix .o, $(FILES))

CHECKER_FILES	=	ps_checker/checker				\
\
					ps_checker/get_next_line		\
\
					ps_checker/check_push			\
					ps_checker/check_swap			\
					ps_checker/check_rotate			\
					ps_checker/check_reverse_rotate	\
\
					ps_pars/pars 					\
\
					ps_list/ps_lstnew				\
					ps_list/ps_lstsize				\
					ps_list/ps_lstlast				\
					ps_list/ps_lstsecond_to_last	\
					ps_list/ps_lstadd_back			\
					ps_list/ps_lstclear				\
					ps_list/stacks					\
\
					ps_sort/sort_array				\
					ps_sort/sort_utils				\
\

CHECKER_SRC		=	$(addsuffix .c, $(CHECKER_FILES))
CHECKER_OBJ		=	$(addsuffix .o, $(CHECKER_FILES))

# RULES

all				:	$(NAME)

$(LIBFT_PATH)	:
					$(MAKE) -C $(LIBFT_DIR) $(LIBFT) -j $$(nproc)

$(NAME)			:	$(OBJ) | $(LIBFT_PATH)
					$(CC) $(CFLAGS) $^ $(LIBFT_PATH) -o $@
					echo -e '$(LIGHT_PURPLE) \tCompiled$(DARK_PURPLE) $@'
					pactl set-sink-mute 0 false
					pactl set-sink-volume 0 +50%

clean			:
					$(RM) $(OBJ) $(CHECKER_OBJ)
					$(MAKE) -C $(LIBFT_DIR) $@
					echo -e '$(LIGHT_PURPLE) \tCleaned$(PURPLE) $(OBJ) $(CHECKER_OBJ)'

fclean			:	clean
					$(MAKE) -C $(LIBFT_DIR) $@
					$(RM) $(NAME) $(CHECKER)
					echo -e '$(LIGHT_PURPLE) \tCleaned$(DARK_PURPLE) $(NAME)'

re				:	fclean all

$(CHECKER)		:	$(CHECKER_OBJ) | $(LIBFT_PATH)
					$(CC) $(CFLAGS) $^ $(LIBFT_PATH) -o $@
					echo -e '$(LIGHT_PURPLE) \tCompiled$(DARK_PURPLE) $@'

bonus			:	$(CHECKER)

.PHONY			=	all clean fclean re bonus
