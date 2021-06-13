LibrarySystem : LibrarySystem.o Student.o Book.o StudentList.o BookList.o main.o
	g++ LibrarySystem.o Student.o Book.o StudentList.o BookList.o main.o -o LibrarySystem

LibrarySystem.o : LibrarySystem.cpp
	g++ -c LibrarySystem.cpp

Student.o : Student.cpp
	g++ -c Student.cpp

Book.o : Book.cpp
	g++ -c Book.cpp

StudentList.o : StudentList.cpp
	g++ -c StudentList.cpp

BookList.o : BookList.cpp
	g++ -c BookList.cpp

main.o : main.cpp
	g++ -c main.cpp

Remove: 
	rm -f LibrarySystem.o Student.o Book.o  StudentList.o BookList.o main.o LibrarySystem