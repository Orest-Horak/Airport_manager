#include <iostream>
#include <string>
#include "Header.h"
using namespace std;

void main()
{
	Airport airport;
	Plane plane(10,"AN251");
	Passenger passenger;
	Flight flight("Lviv","London","28.10.2017", "29.10.2017","AN251",10);

	string operation = "";
	do
	{
		cin >> operation;
		if (operation == "create_passenger")
		{
			cin >> passenger;
		}
		else if (operation == "create_airport")
		{
			Airport airport1;
			cin >> airport1;
		}
		else if (operation == "create_flight")
		{
			Flight flight1;
			cin >> flight1;
		}
		else if (operation == "create_plane")
		{
			Plane plane1;
			cin >> plane1;
		}
		else if (operation == "info_plane")
		{
			plane.info();
		}
		else if (operation == "info_flight")
		{
			flight.info();
		}
		else if (operation == "new_order")
		{
			string name, surname, flight;
			int place;
			cin >> name>> surname>> flight >> place;
			plane.set_place(name, surname, place);
			plane.info();
		}
		else if (operation == "delete_order")
		{
			string name, surname, flight;
			int place;
			cin >> name >> surname >> flight >> place;
			plane.set_place("", "", place);
			plane.info();
		}
		else if (operation == "show_income")
		{
			double suma = 0;
			for (int i = 0; i < plane.get_number_of_places(); i++)
			{
				if (plane.check_place(i)) 
				{
					if(i<plane.get_number_of_places()/2.0)
					{
						suma += 500;
					}
					else 
					{
						suma += 100;
					}
				}
			}
			cout << "Our income is " << suma << endl;
		}
		else if (operation.find("exit") == 0)
		{
		}
		else if (operation == "help")
		{
			cout << "create_passenger <name> <surname>" << endl;
			cout << "create_airport <name> <city>" << endl;
			cout << "create_flight <place_of_departure>  <place_of_landing> <departure_time> <Arrival_time> <airplane_number> <number_of_places>" << endl;
			cout << "create_plane <airplane_number> <number_of_places>" << endl;
			cout << "info_plane <airplane_number>" << endl;
			cout << "info_flight <place of departure>" << endl;
			cout << "new_order <name> <surname> <flight> <place>" << endl;
			cout << "delete_order <name> <surname> <flight> <place>" << endl;
			cout << "show_income" << endl;
		}
		else
		{
			cout << "Unsupported operation!" << endl;
		}
	} while (operation != "exit");

	flight.write_flight();
	plane.write_plane();

	system("pause");
}
