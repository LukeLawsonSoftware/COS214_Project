make:
	g++ -c *.cpp
	g++ -o main *.o

clean:
	rm *.o

run:
	./main

memory:
	valgrind --leak-check=yes ./main

debug:
	g++ -g *.cpp
	gdb ./a.out