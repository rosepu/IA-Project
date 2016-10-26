CC = g++
CFLAGS = -g -Wall
OBJS = *.cpp

PROG = Greedy+TS
SRCDIR = src
IDDIR = Instancias
BINDIR = bin
KDIR_P = mkdir -p
i=1

comp:$(PROG)

run:$(PROG)
	$(BINDIR)/$(PROG) Instancia$(i).rwsp

$(PROG):
	$(KDIR_P) $(BINDIR)
	$(CC) $(SRCDIR)/$(OBJS) -o $(BINDIR)/$(PROG) $(CFLAGS)
