GCC = g++
GCC_FLAGS = -I include -std=c++17
PROGRAMA = raytracer

$(PROGRAMA): background.o main.o
	$(GCC) $(GCC_FLAGS) -o raytracer *.o

background.o: src/background.cpp include/CG/background.h
	$(GCC) $(GCC_FLAGS) -c src/background.cpp

main.o: src/main.cpp
	$(GCC) $(GCC_FLAGS) -c src/main.cpp

clean:
	rm *.o $(PROGRAMA)