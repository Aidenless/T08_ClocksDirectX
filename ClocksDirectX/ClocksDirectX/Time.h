#pragma once

#include <ctime>
#include <string>

using namespace std;

//--------Time class
class Time {
public:
	Time();				//default constructor
	Time(const Time&);	//copy constructor
	Time(int, int, int);	//simple constructor
	Time(long);			//conversion constructor
	Time(const string&);	//conversion constructor
	~Time();				//destructor
	int getHours() const;	//return a data member value, hrs_
	int getMinutes() const;	//return a data member value, mins_
	int getSeconds() const;	//return a data member value, secs_
	void setTime(int, int, int);	//set the time to 3 given values
	void readInTime();	//input time from user
	void displayTime() const;	//display in 00:00:00 digital clock format
	bool isSameAs(const Time&) const;	//check if same as another
	bool isEarlierThan(const Time&) const;	//check if strictly earlier than
	bool isValid() const; 	//check if is valid
	void increment(long);	//add a number of seconds to time
	Time plus(long s) const; 	//create a time from handle + s
	Time plus(const Time& t) const; 	//create a time from handle + t

private:
	long inSeconds_;
	string toString() const;	//return formatted string from Time ("HH:MM:SS")
};