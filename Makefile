all : myshell.out

myshell.out: myshell.c
	gcc -o myshell myshell.c

.PHONY: clean

clean:
	rm -f myshell.out
	
run: myshell.out
	./myshell.out
