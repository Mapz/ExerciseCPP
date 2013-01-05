#pragma once
#include <string>
#include <iostream>
using namespace std;
class person
{
public:
	person():
		name("Default Name"),
		address("Unknown Location"){}
	person(string n,string a):
		name(n),
		address(a){}
	string name,address;
	virtual void attack();
	string getName(void) const {return name;}
	string getAdd(void) const {return address;}
};


class kicker : public person {
	kicker();
	void attack();
};
