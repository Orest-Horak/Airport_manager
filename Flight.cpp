#include <iostream>
#include <string>
#include <fstream>
#include "Flight.h"
using namespace std;

Flight::Flight()
{
}

Flight::Flight(string _Place_of_departure, string _Place_of_landing, string _Departure_time, string _Arrival_time, string _airplane_number, int _number_of_places)
{
	Place_of_departure = _Place_of_departure;
	Place_of_landing = _Place_of_landing;
	Departure_time = _Departure_time;
	Arrival_time = _Arrival_time;
	plane.set_airplane_number(_airplane_number);
	plane.set_number_of_places(_number_of_places);
}

void Flight::info() const
{
	cout << Place_of_departure <<' '<< Place_of_landing<<' ' << Departure_time <<' '<< Arrival_time;
	cout << " Bort " << plane.get_airplane_number() << " with " << plane.get_number_of_places() << " places" << endl;
	plane.get_places();
}
void Flight::set_plane(string _airplane_number, int _number_of_places)
{
	plane.set_airplane_number(_airplane_number);
	plane.set_number_of_places(_number_of_places);
}

void Flight::write_flight()const
{
	string path = Place_of_departure+"-"+Place_of_landing;
	path += ".txt";
	fstream file(path, fstream::out);
	file << Place_of_departure<<' ' << Place_of_landing << ' ' << Departure_time << ' ' << Arrival_time << ' ' << plane.get_airplane_number() << ' ' << plane.get_number_of_places() << endl;
	file.close();
}

Flight::~Flight()
{
}

istream& operator >> (istream& os, Flight& flight)
{
	string _airplane_number;
	int _number_of_places;
	os >> flight.Place_of_departure >> flight.Place_of_landing >> flight.Departure_time >> flight.Arrival_time >> _airplane_number >> _number_of_places;
	flight.set_plane(_airplane_number, _number_of_places);
	return os;
}