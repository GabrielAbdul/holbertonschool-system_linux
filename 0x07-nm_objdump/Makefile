CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic

hnm: 0-nm.c
	$(CC) $(CFLAGS) 0-nm.c -o hnm

hobjdump: 1-objdump.c
	$(CC) $(CFLAGS)  1-objdump.c -o hobjdump

clean:
		$(RM) *~ $(NAME)

oclean:
		$(RM) $(OBJ)

fclean: clean oclean

re: oclean all