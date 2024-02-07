build:
	g++ -Wall -std=c++20 main.cpp -o main.exe

ctest:
	rm -f tests.exe
	g++ -Wall -std=c++20 tests.cpp -o tests.exe

gtest:
	rm -f tests.exe
	g++ -g -std=c++20 -Wall tests.cpp -o tests.exe -lgtest -lgtest_main -lpthread

run:
	./main.exe

runtest:
	./tests.exe

brun:
	g++ -Wall -std=c++20 main.cpp -o main.exe
	./main.exe

btest:
	make gtest
	make runtest

clean:
	rm -f program.exe
	rm -f tests.exe

valgrind:
	valgrind --tool=memcheck --leak-check=yes ./main.exe

valgrindTest:
	valgrind --tool=memcheck --leak-check=yes ./tests.exe
