all: mylib

# mylib

mylib: libmylib.a
libmylib.a: palin.o ana.o
	ar -rs $@ $^
        
palin.o: palin.c mylib.h
	cc -c -Wall palin.c

ana.o: ana.c mylib.h
	cc -c -Wall ana.c

clean:
	rm *.o 
