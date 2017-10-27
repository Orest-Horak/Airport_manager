#pragma once
#include <iostream>
#include <string>
#include "Passenger.h"

using namespace std;
class Place
{
protected:
	int number;
	bool status;
	Passenger passenger;
public:
	Place();
	Place(const Place& ob);
	Place(int _number,bool _status);
	void set_passenger(string _name, string _surname);
	void kick_passenger();
	void set_status(bool _status);
	bool get_status()const;
	void set_number(int _number);
	int get_number() const;
	//void info() const;
	~Place();

	friend ostream& operator << (ostream& os, Place& place);
	friend istream& operator >> (istream& os, Place& place);
};
