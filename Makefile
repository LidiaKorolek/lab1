.PHONY: clean all

all: bin/program

bin/program: build/src/geometry.o build/src/PerimeterCircle.o build/src/PerimeterTriangle.o build/src/AreaCircle.o build/src/AreaTriangle.o
	g++ -Wall -Werror --std=c++17 build/src/geometry.o build/src/PerimeterCircle.o build/src/PerimeterTriangle.o build/src/AreaCircle.o build/src/AreaTriangle.o -o bin/program
	
build/src/geometry.o : src/geometry.cpp
	g++ -Wall -Werror -c --std=c++17 src/geometry.cpp -o build/src/geometry.o

build/src/PerimeterCircle.o : src/PerimeterCircle.cpp
	g++ -Wall -Werror -c --std=c++17 src/PerimeterCircle.cpp -o build/src/PerimeterCircle.o
	
build/src/PerimeterTriangle.o : src/PerimeterTriangle.cpp
	g++ -Wall -Werror -c --std=c++17 src/PerimeterTriangle.cpp -o build/src/PerimeterTriangle.o
	
build/src/AreaCircle.o : src/AreaCircle.cpp
	g++ -Wall -Werror -c --std=c++17 src/AreaCircle.cpp -o build/src/AreaCircle.o
	
build/src/AreaTriangle.o : src/AreaTriangle.cpp
	g++ -Wall -Werror -c --std=c++17 src/AreaTriangle.cpp -o build/src/AreaTriangle.o
	
clean: 
	rm -rf build/*.o bin/*.exe
