TESTS = test_sa test_pa test_ra test_rra test_sb test_pb test_rb test_rrb \
	test_selection_sort

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-return-type -g -I.. -I../libft
RM = rm -f

COMMON_SRCS = ../movements/a.c ../movements/b.c ../lst_funcs/add_node.c
LIBFT = ../libft/libft.a

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

test_sa: test_sa.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_sa.c $(COMMON_SRCS) -o $@

test_pa: test_pa.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_pa.c $(COMMON_SRCS) -o $@

test_ra: test_ra.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_ra.c $(COMMON_SRCS) -o $@

test_rra: test_rra.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_rra.c $(COMMON_SRCS) -o $@

test_sb: test_sb.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_sb.c $(COMMON_SRCS) -o $@

test_pb: test_pb.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_pb.c $(COMMON_SRCS) -o $@

test_rb: test_rb.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_rb.c $(COMMON_SRCS) -o $@

test_rrb: test_rrb.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_rrb.c $(COMMON_SRCS) -o $@

test_selection_sort: test_selection_sort.c $(COMMON_SRCS) ../selection_sort.c ../lst_funcs/lstsize.c ../ft_push_swap.h ../libft/libft.h $(LIBFT)
	$(CC) $(CFLAGS) test_selection_sort.c $(COMMON_SRCS) ../selection_sort.c ../lst_funcs/lstsize.c $(LIBFT) -o $@

$(LIBFT):
	$(MAKE) -C ../libft

clean:
	$(RM) $(TESTS)

fclean: clean

re: fclean all

.PHONY: all test clean fclean re
