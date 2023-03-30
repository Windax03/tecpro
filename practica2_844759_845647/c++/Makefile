#------------------------------------------------------------------------------
# File:   Makefile
# Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
# Date:   febrero 2023
# Coms:   Práctica 1 de TecPro
#         Sirve para compilar el main
#------------------------------------------------------------------------------

PROG:=main
SRCS:=main.cc add.cc read.cc write.cc dup.cc push.cc jumpif.cc mul.cc over.cc swap.cc programa.cc programaSuma.cc programaCuenta.cc programaFactorial.cc

CXX:= g++ -O2

OBJS:=$(SRCS:.cc=.o)

all: $(PROG) main.s

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s


main.s: main.cc instruccion.h add.h read.h write.h dup.h push.h jumpif.h mul.h over.h swap.h programa.h programaSuma.h programaCuenta.h programaFactorial.h
