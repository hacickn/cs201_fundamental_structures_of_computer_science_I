LibrarySystem : SimpleLibrarySystem.o SimpleStudent.o StudentList.o main.o
	g++ SimpleLibrarySystem.o SimpleStudent.o StudentList.o main.o -o LibrarySystem

SimpleLibrarySystem.o : SimpleLibrarySystem.cpp
	g++ -c SimpleLibrarySystem.cpp

SimpleStudent.o : SimpleStudent.cpp
	g++ -c SimpleStudent.cpp

StudentList.o : StudentList.cpp
	g++ -c StudentList.cpp

main.o : main.cpp
	g++ -c main.cpp

Remove: 
	rm -f SimpleLibrarySystem.o SimpleStudent.o StudentList.o main.o LibrarySystem