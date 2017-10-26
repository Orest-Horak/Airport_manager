#pragma once
#include <iostream>
#include <string>

using namespace std;
class Passenger
{
protected:
	string name;
	string surname;
public:
	Passenger();
	Passenger(const Passenger& ob);
	Passenger(string _name, string _surname);
	void set_name(string _name);
	string get_name() const;
	void set_surname(string _surname);
	string get_surname() const;
	//void info() const;
	~Passenger();

	friend ostream& operator << (ostream& os, Passenger& passenger);
	friend istream& operator >> (istream& os, Passenger& passenger);
};
