main: main.o addFunc.o libfuncs.a
	gcc -omain main.o addFunc.o -L. -ladd -lfuncs -Wl -rpath,.
funcs.o: funcs.c
	gcc -c funcs.c
addFunc.o: addFunc.c funcs.h
	gcc -c addFunc.c
main.o: main.c addFunc.h funcs.h
	gcc -c main.c
test.o: test.c funcs.h
	gcc -c test.c
test: test.o funcs.o
	gcc -otest test.o funcs.o /root/Unity/src/unity.c
runtests:test
	./test
clean: 
	rm --force main test *.so *.a *.o
funs1.o: funs1.c
	gcc -c funs1.c

libfuncs.a: funcs.o
	ar cr libfuncs.a funcs.o
libfuns1.so: funs1.o
	gcc -fPIC -shared -olibfuns1.so funs1.o
