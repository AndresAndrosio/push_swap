TESTS = test_sa test_pa test_ra test_rra

CC = cc
CFLAGS = -Wall -Wextra -Werror -Wno-return-type -g -I.. -I../libft
RM = rm -f

COMMON_SRCS = ../movements/a.c ../utils/stack.c

all: test

test: $(TESTS)
	./test_sa
	./test_pa
	./test_ra
	./test_rra

test_sa: test_sa.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_sa.c $(COMMON_SRCS) -o $@

test_pa: test_pa.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_pa.c $(COMMON_SRCS) -o $@

test_ra: test_ra.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_ra.c $(COMMON_SRCS) -o $@

test_rra: test_rra.c $(COMMON_SRCS) ../ft_push_swap.h ../libft/libft.h
	$(CC) $(CFLAGS) test_rra.c $(COMMON_SRCS) -o $@

clean:
	$(RM) $(TESTS)

fclean: clean

re: fclean all

.PHONY: all test clean fclean re
