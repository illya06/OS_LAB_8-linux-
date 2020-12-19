FLAGS = -pthread -fpermissive -Wint-to-pointer-cast -pg

myapp: main.o
	g++ main.o $(FLAGS) -o myapp

main.o: main.cpp
	g++ -c $(FLAGS) main.cpp

clean clear cl:
	rm *.o *.out *.txt myapp