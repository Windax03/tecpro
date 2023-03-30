#------------------------------------------------------------------------------
# File:   Makefile
# Authors: Jorge Leris - 845647 / Angel Villanueva - 844759
# Date:   marzo 2023
# Coms:   Problema 4 de TecPro
#------------------------------------------------------------------------------


PROG:=main
SRCS:=main.cc

CXX:= g++ -Wall

OBJS:=$(SRCS:.cc=.o)
DEPS:=$(SRCS:.cc=.d)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c -MMD $<

edit:
	geany -i -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) $(DEPS) core *.s *.gch

# Dependencias
-include $(DEPS)
