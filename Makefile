.PHONY: clean all
 
all: bin/program
 
bin/program: build/geometry.o build/PerimeterCircle.o build/PerimeterTriangle.o build/AreaCircle.o build/AreaTriangle.o
    g++ -Wall -Werror --std=c++17 build/geometry.o build/PerimeterCircle.o build/PerimeterTriangle.o build/AreaCircle.o build/AreaTriangle.o -o bin/program
   
build/geometry.o : src/geometry.cpp
    g++ -Wall -Werror -c --std=c++17 src/geometry.cpp -o build/geometry.o
 
build/PerimeterCircle.o : src/PerimeterCircle.cpp
    g++ -Wall -Werror -c --std=c++17 src/PerimeterCircle.cpp -o build/PerimeterCircle.o
   
build/PerimeterTriangle.o : src/PerimeterTriangle.cpp
    g++ -Wall -Werror -c --std=c++17 src/PerimeterTriangle.cpp -o build/PerimeterTriangle.o
   
build/AreaCircle.o : src/AreaCircle.cpp
    g++ -Wall -Werror -c --std=c++17 src/AreaCircle.cpp -o build/AreaCircle.o
   
build/AreaTriangle.o : src/AreaTriangle.cpp
    g++ -Wall -Werror -c --std=c++17 src/AreaTriangle.cpp -o build/AreaTriangle.o
   
clean:
    rm -rf build/*.o bin/*.exe
