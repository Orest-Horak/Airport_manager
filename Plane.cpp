#include <iostream>
#include <string>
#include <fstream>
#include "Plane.h"
using namespace std;

Plane::Plane() : number_of_places(0), airplane_number("")
{
	places = new Place[0];
}

Plane::Plane(int _number_of_places, string _airplane_number)
{
	number_of_places = _number_of_places;
	airplane_number = _airplane_number;
	places = new Place[number_of_places];
	for (int i = 0; i < number_of_places; i++)
	{
		places[i].set_number(i);
	}
}

void Plane::set_number_of_places(int _number_of_places)
{
	if (number_of_places != _number_of_places)
	{
		number_of_places = _number_of_places;
		places = new Place[number_of_places];
		for (int i = 0; i < number_of_places; i++)
		{
			places[i].set_number(i);
		}
	}
}

int Plane::get_number_of_places()const
{
	return number_of_places;
}

void Plane::set_airplane_number(string _airplane_number)
{
	airplane_number = _airplane_number;
}

string Plane::get_airplane_number()const
{
	return airplane_number;
}

void Plane::get_places() const
{
	for (int i = 0; i < number_of_places; i++)
	{
		cout << places[i] << endl;
	}

}

void Plane::set_place(string _name, string _surname, int _place) 
{
	places[_place].set_passenger(_name,_surname);
}

void Plane::get_free_places() const
{
	for (int i = 0; i < number_of_places; i++)
	{
		if (places[i].get_status() == false)
		{
			cout << places[i] << endl;
		}
	}


}

void Plane::write_plane()const
{
	string path = airplane_number;
	path += ".txt";
	fstream file (path,fstream::out);
	file << airplane_number << endl;
	file << number_of_places << endl;
	for (int i = 0; i < number_of_places; i++)
	{
		file << places[i] << endl;
	}
	file.close();
}

bool Plane::check_place(int number)
{
	if (places[number].get_status()) 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

void Plane::read_plane(string _airplane_number)
{
	string path = _airplane_number;
	path += ".txt";
	fstream file(path, fstream::in);
	file >> _airplane_number;
	file >> number_of_places;
	places = new Place[number_of_places];
	for (int i = 0; i < number_of_places; i++)
	{
		file >> places[i];
	}
	file.close();
}

void Plane::info() const 
{
	cout << "Plane " << airplane_number << " with " << number_of_places << " places"<<endl;
	for (int i = 0; i < number_of_places; i++)
	{
		cout << places[i] << endl;
	}
}

Plane::~Plane()
{
	delete[] places;
}

istream& operator >> (istream& os, Plane& plane) 
{
	os>>plane.airplane_number >> plane.number_of_places;
	plane.set_number_of_places(plane.number_of_places);
	plane.info();
	return os;
}