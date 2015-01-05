test.out: main.o bwindow.o Agent.o Boids.o 
	g++ -o test.out main.o bwindow.o Agent.o Boids.o -lX11 -L/usr/X11R6/lib
main.o: main.cpp 
	g++ -c main.cpp 
bwindow.o: bwindow.cpp bwindow.h
	g++ -c bwindow.cpp
Agent.o : Agent.cpp Agent.h
	g++ -c Agent.cpp
Boids.o : Boids.cpp Boids.h
	g++ -c Boids.cpp

clean :
	rm *.o *.out
