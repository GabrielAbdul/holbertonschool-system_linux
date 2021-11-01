CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

0-hreadelf: 0-hreadelf.c
	$(CC) $(CFLAGS) 0-hreadelf.c -o 0-hreadelf

clean:
		$(RM) *~ $(NAME)

oclean:
		$(RM) $(OBJ)

fclean: clean oclean

re: oclean all