###########################################
# variables a initialiser
###########################################


CC       = gcc
CFLAGS   = -c -g -Wall


LDFLAGS  = -g -o
LD       = gcc


#liste des fichiers objets
OFILES   = main.o foncs.o
###########################################
all:	appli

clean :
	rm -f *.o appli


#production de l'objet main.o (a completer)
main.o: 
	$(CC)  $(CFLAGS) main.c
	

# production de l'objet foncs.o (a completer)
foncs.o: 
	$(CC)  $(CFLAGS) foncs.c

# production de l'executable appli (a completer)
appli: $(OFILES)
	$(LD) $(OFILES) $(LDFLAGS)  appli
