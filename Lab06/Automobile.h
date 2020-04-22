#pragma once
#include <iostream>
#include <string>
using namespace std;

class Automobile{
protected:
	string color;
	string brand;
	int year;
	bool isDiesel; 
	bool isElectric;
	bool isGas;

public:
	Automobile();
	Automobile(string, string, int, bool,bool,bool);
	~Automobile();

	void setColor(string);
	string getColor();

	void setBrand(string);
	string getBrand();

	void setYear(int);
	int getYear();

	void setIsGas(bool);
	bool getIsGas();

	void setIsDiesel(bool);
	bool getIsDiesel();

	void setIsElectric(bool);
	bool getIsElectric();

	string toString();
};