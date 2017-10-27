#pragma once
#include <iostream>
#include <string>

using namespace std;
class Airport
{
protected:
	string name;
	string city;
public:
	Airport();
	Airport(string _name, string _city);
	void set_name(string _name);
	void set_city(string _city);

	string get_name() const;
	string get_city() const;

	//void info() const;
	~Airport();
	friend istream& operator >> (istream& os, Airport& airport);
};