.PHONY: clean all

all: bin/program bin/test

bin/program: build/src/geometry.o build/src/PerimeterCircle.o build/src/PerimeterTriangle.o build/src/AreaCircle.o build/src/AreaTriangle.o build/src/IntersectCircle.o build/src/Intersection.o build/src/SegmentCheck.o build/src/TriangleAndCircleInf.o build/src/CircleCheck.o
	g++ -Wall -Werror --std=c++17 build/src/geometry.o build/src/PerimeterCircle.o build/src/PerimeterTriangle.o build/src/AreaCircle.o build/src/AreaTriangle.o build/src/IntersectCircle.o build/src/Intersection.o build/src/SegmentCheck.o build/src/TriangleAndCircleInf.o build/src/CircleCheck.o -o bin/program
	
bin/test: build/test/test.o build/src/PerimeterCircle.o build/src/PerimeterTriangle.o build/src/AreaCircle.o build/src/AreaTriangle.o build/src/IntersectCircle.o build/src/SegmentCheck.o build/src/Intersection.o build/src/TriangleAndCircleInf.o build/src/CircleCheck.o
	g++ -Wall -Werror -std=c++17 -I thirdparty/catch2 build/test/test.o build/src/PerimeterCircle.o build/src/PerimeterTriangle.o build/src/AreaCircle.o build/src/AreaTriangle.o build/src/IntersectCircle.o build/src/SegmentCheck.o build/src/Intersection.o build/src/TriangleAndCircleInf.o build/src/CircleCheck.o -o bin/test
	
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

build/src/IntersectCircle.o : src/IntersectCircle.cpp
	g++ -Wall -Werror -c --std=c++17 src/IntersectCircle.cpp -o build/src/IntersectCircle.o

build/src/Intersection.o : src/Intersection.cpp
	g++ -Wall -Werror -c --std=c++17 src/Intersection.cpp -o build/src/Intersection.o

build/src/TriangleAndCircleInf.o : src/TriangleAndCircleInf.cpp
	g++ -Wall -Werror -c --std=c++17 src/TriangleAndCircleInf.cpp -o build/src/TriangleAndCircleInf.o

build/src/SegmentCheck.o : src/SegmentCheck.cpp
	g++ -Wall -Werror -c --std=c++17 src/SegmentCheck.cpp -o build/src/SegmentCheck.o

build/src/CircleCheck.o : src/CircleCheck.cpp
	g++ -Wall -Werror -c --std=c++17 src/CircleCheck.cpp -o build/src/CircleCheck.o
	
build/test/test.o : test/test.cpp
	g++ -Wall -Werror -c --std=c++17 -I thirdparty/catch2 -I src test/test.cpp -o build/test/test.o
	
clean: 
	rm -rf build/*.o bin/*.exe
