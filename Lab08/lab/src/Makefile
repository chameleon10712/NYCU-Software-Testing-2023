CC := gcc

.PHONY: all
all: prog

prog: main.c equations
	$(CC) -o $@ $<

equations: equations_gen.py
	python3 $< > $@

.PHONY: clean
clean:
	rm -rf prog equations answer_input