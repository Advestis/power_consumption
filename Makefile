CXX = g++
CXXFLAGS = -std=c++11 -g
LD = $(CXX)
LDFLAGS = -lm -lrt

all : launch

launch : launch.o Rapl.o
	$(LD) $(LDFLAGS) -o $@ $^

launch.o : launch.cpp Rapl.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<

Rapl.o : Rapl.cpp Rapl.h
	$(CXX) $(CXXFLAGS) -c -o $@ $< 

clean :
	rm -f *.o 
	rm -f rapl.csv
