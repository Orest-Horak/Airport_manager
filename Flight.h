#pragma once
#include <iostream>
#include <string>
#include"Plane.h"
using namespace std;
class Flight
{
protected:
	string Departure_time;
	string Arrival_time;
	string Place_of_departure;
	string Place_of_landing;
	Plane plane;
public:
	Flight();
	Flight(string _Place_of_departure, string _Place_of_landing, string _Departure_time, string _Arrival_time, string _airplane_number, int _number_of_places);
	void set_plane(string _airplane_number, int _number_of_places);

	//void set_Departure_time(string _Departure_time);
	//string get_Departure_time() const;

	//void set_Arrival_time(string _Arrival_time);
	//string get_Arrival_time() const;

	//string get_Place_of_departure() const;
	//void set_Place_of_departure(string _Place_of_departure);

	//string get_Place_of_landing() const;
	//void set_Place_of_landing(string _Place_of_landing);
	void info() const;
	void write_flight()const;
	~Flight();
	friend istream& operator >> (istream& os, Flight& flight);
};
