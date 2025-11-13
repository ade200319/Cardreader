PROG = main.exe
SRC = main.c functions.c  safeinput.c     # <-- lägg till alla .c-filer här
CFLAGS = -Wall -Werror -g -I.
LIBS =
all: $(PROG)

$(PROG): $(SRC)
	$(CC) -o $@ $(CFLAGS) $(SRC) $(LIBS)

clean:
	rm -f $(PROG)

.PHONY: all clean
