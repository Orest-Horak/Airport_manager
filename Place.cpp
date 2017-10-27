#include <iostream>
#include <string>
#include "Place.h"
using namespace std;


Place::Place() :number(0), status(false)
{

}

Place::Place(const Place& ob)
{
	this->number = ob.number;
	this->status = ob.status;
	this->passenger.set_name(ob.passenger.get_name());
	this->passenger.set_surname(ob.passenger.get_surname());
}

void Place::set_passenger(string _name, string _surname)
{
	if (_name != "")
	{
		status = true;
	}
	else 
	{
		status = false;
	}
	this->passenger.set_name(_name);
	this->passenger.set_surname(_surname);
}

void Place::kick_passenger()
{
	status = false;
	this->passenger.set_name("");
	this->passenger.set_surname("");
}

Place::Place(int _number, bool _status)
{
	number = _number;
	status = _status;
}

void Place::set_status(bool _status)
{
	status = _status;
}

bool Place::get_status()const
{
	return status;
}

void Place::set_number(int _number)
{
	number = _number;
}

int Place::get_number() const
{
	return number;
}

//void info() const;
Place::~Place()
{
	number = 0;
	status = false;
}

ostream& operator << (ostream& os, Place& place)
{
	os << place.number<< ' ' << place.status<<' '<< place.passenger;
	return os;
}

istream& operator>> (istream& is, Place &place)
{
	is >> place.number >> place.status;
	return is;
}
