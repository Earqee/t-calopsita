CPLEXFLAGS=-O3 -m64 -O -fPIC -fexceptions -DNDEBUG -DIL_STD -I/*****/cplex/include -I/*****/concert/include -L/*****/cplex/lib/x86-64_linux/static_pic -lilocplex -lcplex -L/*****/concert/lib/x86-64_linux/static_pic -lconcert -lm -pthread -std=c++17 -ldl

CFLAGS=-std=c++17 -static-libstdc++ -static-libgcc -Wall

all:$(path).o
	g++  $(path).o -o $(path).run $(CPLEXFLAGS) $(CFLAGS)

%.o: %.cpp %.hpp
	g++ -c $< -o $@ $(CFLAGS)

$(path).o: $(path).cpp
	g++ -c -o $(path).o $(path).cpp $(CPLEXFLAGS) $(CFLAGS)

clean:
	rm -f *.o
