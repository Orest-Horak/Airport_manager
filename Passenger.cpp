#include <iostream>
#include <string>
#include "Passenger.h"
using namespace std;


Passenger::Passenger() :name(""), surname("")
{

}

Passenger::Passenger(const Passenger& ob)
{
	this->name = ob.name;
	this->surname = ob.surname;
}

Passenger::Passenger(string _name, string _surname)
{
	name = _name;
	surname = _surname;
}

void Passenger::set_name(string _name)
{
	name = _name;
}

string Passenger::get_name() const
{
	return name;
}

void Passenger::set_surname(string _surname)
{
	surname = _surname;
}

string Passenger::get_surname() const
{
	return surname;
}

//void info() const;
Passenger::~Passenger()
{
	name = "";
	surname = "";
}

ostream& operator << (ostream& os, Passenger& passenger)
{
	os << passenger.name << ' ' << passenger.surname;
	return os;
}

istream& operator >> (istream& is, Passenger& passenger)
{
	is >> passenger.name >> passenger.surname;
	return is;
}