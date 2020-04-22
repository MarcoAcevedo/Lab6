#pragma once
#include <iostream>
#include <string>
#include "Automobile.h"
class Car : public Automobile{
private:
	string licensePlate, brand, model, vin;
	

public:
	Car();
	Car(string, string, int, bool, bool, bool, string, string, string, string);
	~Car();

	void setLicensePlate(string);
	string getLicensePlate();

	void setBrand(string);
	string getBrand();

	void setModel(string);
	string getModel();

	void setVin(string);
	string getVin();

	string toString();
};

