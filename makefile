all: loopy.c
	gcc loopy.c

clean:
	rm a.out
	rm log.txt
	rm *~

run: a.out
	./a.out
