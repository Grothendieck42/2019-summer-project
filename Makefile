All:
ifeq ($(shell uname -s),Darwin)
	g++ -std=c++17 hello.cpp -o hello
else
	g++ -std=c++17 hello.cpp -o hello.exe
endif

clean:
ifeq ($(shell uname -s),Darwin)
	rm -f *.o a.out
else
	rm -f *.o *.exe
endif