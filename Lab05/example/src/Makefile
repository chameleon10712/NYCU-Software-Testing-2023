CC := gcc

.PHONY: all
all: prog

prog: main.c
	$(CC) -fno-stack-protector -o $@ $<

.PHONY: clean
clean:
	rm -rf prog
