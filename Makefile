all : myshell run

myshell: myshell.c
	gcc -o myshell myshell.c

.PHONY: clean

clean:
	rm -f myshell.out
	
run: myshell
	./myshell
