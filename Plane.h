#pragma once
#include <iostream>
#include <string>
#include "Place.h"

using namespace std;
class Plane
{
protected:
	Place* places;
	int number_of_places;
	string airplane_number;
public:
	Plane();
	Plane(int _number_of_places, string _airplane_number);
	void set_number_of_places(int _number_of_places);
	int get_number_of_places()const;
	bool check_place(int number);
	void set_airplane_number(string _airplane_number);
	string get_airplane_number()const;
	void set_place(string _name, string _surname, int _place);
	void get_places() const;
	void get_free_places() const;
	void write_plane()const;
	void read_plane(string _airlane_number);
	void info() const;
	~Plane();

	friend istream& operator >> (istream& os, Plane& plane);
};