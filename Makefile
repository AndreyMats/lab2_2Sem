CC=g++
CFLAGS =-c -Wall
CXX = clang++

hello: main.o
	$(CC) main.o -o hello

main.o: lab2/main.cpp
	$(CC) $(CFLAGS) lab2/main.cpp

unit_test: unit_test_driver.o
	$(CXX) unit_test_driver.o

clean:
	rm -rf *.o hello