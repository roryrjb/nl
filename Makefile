PREFIX = /usr/local
CFLAGS = -static -Wall
NAME = nl

$(NAME): main.o
	$(CC) $(CFLAGS) -o $(NAME) $<

install: $(NAME)
	mkdir -p $(DESTDIR)$(PREFIX)/bin
	install -m755 $(NAME) $(DESTDIR)$(PREFIX)/bin/

clean:
	rm -vf $(NAME) *.o
