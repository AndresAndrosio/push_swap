
TESTS = test_sa test_pa test_ra test_rra test_sb test_pb test_rb test_rrb \
        test_selection_sort test_arg_checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-return-type -g -I.. -I../libft
RM = rm -f

COMMON_SRCS = ../movements/a.c \
              ../movements/b.c \
              ../lst_funcs/add_node.c

COMMON_SRCS += $(wildcard ../arg_funcs/*.c)

SELECTION_SRCS = ../selection_sort.c \
                 ../lst_funcs/lstsize.c

LIBFT = ../libft/libft.a

HEADERS = ../ft_push_swap.h ../libft/libft.h

all: test

test: $(TESTS)
	./test_sa
	./test_pa
	./test_ra
	./test_rra
	./test_sb
	./test_pb
	./test_rb
	./test_rrb
	./test_selection_sort
	./test_arg_checker

test_sa test_pa test_ra test_rra test_sb test_pb test_rb test_rrb: %: %.c $(COMMON_SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $< $(COMMON_SRCS) $(LIBFT) -o $@

test_selection_sort: test_selection_sort.c $(COMMON_SRCS) $(SELECTION_SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $< $(COMMON_SRCS) $(SELECTION_SRCS) $(LIBFT) -o $@

test_arg_checker: test_arg_checker.c $(COMMON_SRCS) $(HEADERS) $(LIBFT)
	$(CC) $(CFLAGS) $< $(COMMON_SRCS) $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C ../libft

clean:
	$(RM) $(TESTS)
	$(RM) ../libft/*.o

fclean: clean
	$(RM) $(LIBFT)

re: fclean all

.PHONY: all test clean fclean re
