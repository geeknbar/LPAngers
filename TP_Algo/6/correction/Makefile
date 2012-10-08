CCOPTS=-Wall
TARGETS=6.1 6.2
LDPATH=../mylib

%: %.c
	gcc $(CCOPTS) -o $@ $@.c

all: $(TARGETS)

6.1: 6.1.c
	gcc $(CCOPTS) -o $@ $@.c -L$(LDPATH) -lmylib

6.2: 6.2.c
	gcc $(CCOPTS) -o $@ $@.c -L$(LDPATH) -lmylib

clean:
	rm $(TARGETS)
