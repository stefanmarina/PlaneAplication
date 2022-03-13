#ifndef _Flights_
#define _Flights_



#include <iostream>
#include <ctime>


class Flights
{
private:
	/*std::string OriginCountry;
	std::string DestinationCountry;

	int minute;
	int hour;
	int day;
	int month;
	int year;*/
	

public:
	void WriteFlight(int ID,std::string OCountry, std::string DCountry, int m, int h, int d, int mo, int y);
	void SaveFlight();
	bool checkTime(int m, int h, int d, int mo, int y);
};


#endif
