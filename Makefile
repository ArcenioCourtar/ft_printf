CC			:= cc
NAME		:= libftprintf.a
LIBFT		:= libft/libft.a
OBJFILES	:= ft_printf.o
HEADERFILE	:= ft_printf.h
CFLAGS		:= -Wall -Werror -Wextra

all: $(NAME)

$(NAME): $(LIBFT) $(OBJFILES)
	ar -rcs $(NAME) $(OBJFILES)

re: fclean all

ft_%.o: ft_%.c $(HEADERFILE)
	cc -c $(CFLAGS) -o $@ $<

clean:
	$(MAKE) clean -C libft
	rm -f $(OBJFILES)

fclean:
	$(MAKE) fclean -C libft
	rm -f $(OBJFILES) $(NAME)

$(LIBFT):
	$(MAKE) -C libft
	cp $(LIBFT) $(NAME)

# test: all
# 	@cc test.c $(NAME) -o test
# 	@./test

# test_s: all
# 	@cc test.c $(NAME) -o test -fsanitize=address
# 	@./test

# Ensures that these commands run even if there's a file
# with the same name is in the folder.
# Not needed for all, and re? ?_?
.PHONY: clean fclean bonus re all
