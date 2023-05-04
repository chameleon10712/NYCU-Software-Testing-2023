CC := gcc

.PHONY: all
all: prog

prog: main.c
	$(CC) -o $@ $<

.PHONY: clean
clean:
	rm -rf prog