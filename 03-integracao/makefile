############################# Makefile ##########################
CFLAGS=-lm -Df1
all: prg
prg: integral-c.o integral-c-geral.o
        # O compilador faz a ligação entre os dois objetos
	gcc -lm -o prg integral-c.o integral-c-geral.o 
#-----> Distancia com o botão TAB ### e não com espaços
integral-c-geral.o: integral-c-geral.c
	gcc -DLINUX -o integral-c-geral.o -c integral-c-geral.c
integral-c.o: integral-c.c 
	gcc -o integral-c.o -c integral-c.c
clean:
	rm -rf *.o
cleanall: clean
	rm -rf prg
