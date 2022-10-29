 
CC=g++
CFLAGS=-I. -I./source
OBJ = obj/dtd.o obj/degtodec.o

all: $(OBJ)
	$(CC) $(OBJ) -o dtd

obj/dtd.o: dtd.cpp
	$(CC) $(CFLAGS) -c -o obj/dtd.o dtd.cpp

obj/degtodec.o: source/degtodec.cpp
	$(CC) $(CFLAGS) -c -o obj/degtodec.o source/degtodec.cpp

#obj/JulianDay.o : source/JulianDay.h source/JulianDay.cpp
#	$(CC) $(CFLAGS) -c -o obj/JulianDay.o source/JulianDay.cpp

#obj/SolarPhysics.o : source/SolarPhysics.h source/SolarPhysics.cpp
#	$(CC) $(CFLAGS) -c -o obj/SolarPhysics.o source/SolarPhysics.cpp

clean:
	rm -rf obj/*.o
	rm dtd
