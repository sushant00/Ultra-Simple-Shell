OBJS = a.out

a.out: myshell.c
	gcc myshell.c

.PHONY: clean

clean:
	rm -f $(OBJS)
