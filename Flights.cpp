#include "Flights.h"

#include <iostream>
#include <fstream>
#include <ctime>

#pragma warning(disable : 4996)

void Flights::WriteFlight(int ID,std::string OCountry, std::string DCountry, int m, int h, int d, int mo, int y)
{
	std::fstream file;
	file.open("flights.txt", std::ios::app);
	if (!file.is_open())
		std::cout << "Error" << std::endl;
	else
	{
		file.seekg(0, std::ios::beg);
		file << std::endl;
		file.seekg(0, std::ios::beg);
		file << ID << ";" << OCountry << ";" << DCountry << ";" << m << ";" << h << ";" << d << ";" << mo << ";" << y;
	}


}

void Flights::SaveFlight()
{
	int ID; 
	std::string OCountry; 
	std::string DCountry; 
	int m, h, d, mo, y;

	std::cout << "Add a flight\n";
	std::cout << "Flight ID (****): ";
	std::cin >> ID;
	std::cout << "Origin Country: ";
	std::cin >> OCountry;
	std::cout << "Destinatio Country: ";
	std::cin >> DCountry;
	Time:
	std::cout << "Time of departure \n ";
	std::cout << "Minute: ";
	std::cin >> m;
	std::cout << "Hour: ";
	std::cin >> h;
	std::cout << "Day: ";
	std::cin >> d;
	std::cout << "Mounth: ";
	std::cin >> mo;
	std::cout << "Year ";
	std::cin >> y;
	if(checkTime(m,h,d,mo,y))
	WriteFlight(ID,OCountry,DCountry,m,h,d,mo,y);
	else
	{
		std::cout << "Departure time invalid!";
		goto Time;

	}
}

bool Flights::checkTime(int m, int h, int d, int mo, int y)
{
	time_t now = time(0);
	tm* ltm = localtime(&now);


	if (y >= 2020 && y <= 2030 && y > 1900 + ltm->tm_year)
		if (mo >= 1 && mo <= 12 && 1 + ltm->tm_mon)
			if (d >= 1 && d <= 31 && ltm->tm_mday)
				if (h >= 1 && h <= 24 && 5 + ltm->tm_hour)
					if (m >= 0 && m <= 59 && 30 + ltm->tm_min)
						return true;
					else
						return false;
				else
					return false;
			else
				return false;
		else
			return false;
	else
		return false;

}