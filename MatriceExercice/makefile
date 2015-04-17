LINUX=
CC=gcc
CFLAGS=-Wall -g
#-----------------
debug : all
  $(CFLAGS) += " -g"
#----------------------------------------------
all : serveur client 
#----------------------------------------------
serveur : serveur.o xdr_matrice2.o
	gcc -g -o serveur serveur.o xdr_matrice2.o ${LINUX}
#----------------------------------------------
client : client.o xdr_matrice2.o
	gcc -g -o client client.o xdr_matrice2.o ${LINUX}
#----------------------------------------------
%.o : %.c
	gcc -o $@ $(CFLAGS) -c $^

clean :
	/bin/rm -f *.o serveur client *~ core* pok* *.ps
