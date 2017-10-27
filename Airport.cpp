#include <iostream>
#include <string>
#include <fstream>
#include "Airport.h"
using namespace std;

Airport::Airport() :name(""), city("")
{

}

Airport::Airport(string _name, string _city)
{
	name = _name;
	city = _city;
}

void Airport::set_name(string _name)
{
	name = _name;
}

void Airport::set_city(string _city)
{
	_city = city;
}

string Airport::get_name() const
{
	return name;
}

string Airport::get_city() const
{
	return city;
}

//void info() const;
Airport::~Airport()
{
	string path = name;
	path += ".txt";
	fstream file(path, fstream::out);
	file << name << ' '<<city<< endl;
	file.close();

	name = "";
	city = "";
}

istream& operator >> (istream& is, Airport& airport)
{
	is >> airport.name >> airport.city;
	return is;
}