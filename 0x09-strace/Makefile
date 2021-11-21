CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

strace_0: trace_command.c
	$(CC) $(CFLAGS) trace_command.c -o strace_0

clean:
		$(RM) *~ $(NAME)

oclean:
		$(RM) $(OBJ)

fclean: clean oclean

re: oclean all