FlightReservationSystem : Flight.o Reservation.o ReservationSystem.o main.o
	g++ Flight.o Reservation.o ReservationSystem.o main.o -o FlightReservationSystem

Flight.o : Flight.cpp
	g++ -c Flight.cpp

Reservation.o : Reservation.cpp
	g++ -c Reservation.cpp

ReservationSystem.o : ReservationSystem.cpp
	g++ -c ReservationSystem.cpp

main.o : main.cpp
	g++ -c main.cpp

Remove: 
	rm -f Flight.o Reservation.o ReservationSystem.o main.o FlightReservationSystem