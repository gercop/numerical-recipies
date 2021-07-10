############################# Makefile ##########################
CFLAGS=-lm -Df1
all: prg
prg: derivada.o geral.o
        # O compilador faz a ligação entre os dois objetos
	gcc -lm -o prg derivada.o geral.o 
#-----> Distancia com o botão TAB ### e não com espaços
geral.o: geral.c
	gcc -DLINUX -o geral.o -c geral.c
derivada-a.o: derivada-a.c 
	gcc -o derivada.o -c derivada.c
clean:
	rm -rf *.o
cleanall: clean
	rm -rf prg
