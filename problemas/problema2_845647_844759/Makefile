PROG:=main
SRCS:=main.cc

CXX:= g++ -march=native -O3

OBJS:=$(SRCS:.cc=.o)

all: $(PROG)

$(PROG): $(OBJS)
	$(CXX) -o $@ $(OBJS)

.cc.o:
	$(CXX) -c $<

.cc.s:
	$(CXX) -c -S $<

edit:
	geany -s *.h *.cc &

clean:
	@rm -f $(PROG) $(OBJS) core *.s

#cuenta.o: cuenta.cc cuenta.h 
main.o: main.cc cuenta.h divisa.h nomina.h plazosF.h corrientes.h     #Esto no se si funciona 
