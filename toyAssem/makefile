CC = gcc
CFLAGS = -Wall -g

IDIR = ../toyAssem/include
ODIR = ../toyAssem/src
OBJDIR = objects
BINDIR = bin

SRC = $(wildcard $(ODIR)/*.c)
OBJ = $(patsubst $(ODIR)/%.c, $(OBJDIR)/%.o, $(SRC))

all: objfolder binfolder bin/main

bin/main: $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

binfolder:
	@ echo "Criando diretório do executável..."
	mkdir $(BINDIR)

objfolder:
	@ echo "Criando diretório dos arquivos objeto..."
	mkdir $(OBJDIR)

$(OBJDIR)/manager3.o: $(ODIR)/manager3.c
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJDIR)/%.o: $(ODIR)/%.c $(IDIR)/%.h
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f $(BINDIR)/* $(OBJDIR)/*
	rmdir $(BINDIR) $(OBJDIR)

run:
	$(BINDIR)/main
