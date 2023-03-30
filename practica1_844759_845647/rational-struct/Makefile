#------------------------------------------------------------------------------
# File:   Makefile
# Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
# Date:   febrero 2023
# Coms:   Práctica 1 de TecPro
#         Sirve para compilar el main
#------------------------------------------------------------------------------

PROG:=main
SRCS:=rational.cc main.cc

CXX:= g++ -O2

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

rational.o: rational.cc rational.h
main.o: main.cc rational.h
main.s: main.cc rational.h
