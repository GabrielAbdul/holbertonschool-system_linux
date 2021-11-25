CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

strace_0: trace_command.c
	$(CC) $(CFLAGS) trace_command.c -o strace_0

strace_1: trace_command_name.c
	$(CC) $(CFLAGS) trace_command_name.c -o strace_1

strace_2: trace_command_return_value.c
	$(CC) $(CFLAGS) trace_command_return_value.c -o strace_2
clean:
		$(RM) *~ $(NAME)

oclean:
		$(RM) $(OBJ)

fclean: clean oclean

re: oclean all