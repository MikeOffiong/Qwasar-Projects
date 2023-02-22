CC=gcc
CFLAGS= -Wall -Wextra -Werror
OBJ = my_ngram.o

%.o: %.c
	$(CC) -c $< $(CFLAGS) -o $@

my_ngram: $(OBJ)
	$(CC) $^ $(CFLAGS) -o $@

.PHONY: clean

clean:
	rm -f *.o

fclean: clean
	rm -f my_ngram

re: fclean my_ngram 