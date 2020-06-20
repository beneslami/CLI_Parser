MODULES = src

all:
	(cd $(MODULES); make)

	gcc -g -c main.c -o main.o
	gcc -g main.o -L $(MODULES) -lcli -o exe

clean:
	(cd $(MODULES); make clean)
	rm -rf *.o exe
