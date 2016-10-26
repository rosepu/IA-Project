CC = g++
CFLAGS = -g -Wall
OBJS = *.cpp

PROG = Greedy+TS
SRCDIR = src
IDDIR = Instancias
BINDIR = bin
KDIR_P = mkdir -p

i=1
seed = 1000

comp:$(PROG)

run:$(PROG)
	$(BINDIR)/$(PROG) Instancia$(i).rwsp $(seed)

$(PROG):
	$(KDIR_P) $(BINDIR)
	$(CC) $(SRCDIR)/$(OBJS) -o $(BINDIR)/$(PROG) $(CFLAGS)
