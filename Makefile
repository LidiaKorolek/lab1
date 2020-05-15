all: geometry

geometry.o: src/geometry.cpp
	g++ -Wall -Werror --std=c++11 src/geometry.cpp -o build/geometry.o

AreaCircle.o: src/AreaCircle.cpp
	g++ -Wall -Werror --std=c++11 src/AreaCircle.cpp -o build/AreaCircle.o

AreaTriangle.o: src/AreaTriangle.cpp
	g++ -Wall -Werror --std=c++11 src/AreaTriangle.cpp -o build/AreaTriangle.o

PerimeterCircle.o: src/PerimeterCircle.cpp
	g++ -Wall -Werror --std=c++11 src/PerimeterCircle.cpp -o build/PerimeterCircle.o

PerimeterTriangle.o: src/PerimeterTriangle.cpp
	g++ -Wall -Werror --std=c++11 src/PerimeterTriangle.cpp -o build/PerimeterTriangle.o

geomerty: build/geometry.o build/AreaCircle.o build/AreaTriangle.o build/PerimeterCircle.o build/PerimeterTriangle.o 
	g++ -Wall -Werror --std=c++11 build/geometry.o build/AreaCircle.o build/AreaTriangle.o build/PerimeterCircle.o build/PerimeterTriangle.o -o bin/geometry