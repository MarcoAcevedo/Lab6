#include "Automobile.h"
#include <iostream>
#include <string>
using namespace std;

Automobile::Automobile() {
	this->color = "Default Color";
	this->brand = "Default Brand";
	this->year = 0;
	this->isGas=false;
	this->isDiesel = false;
	this->isElectric = false;
}

Automobile::Automobile(string c, string b, int y , bool d, bool e, bool g) {
	this->color = c;
	this->brand = b;
	this->year = y;
	this->isGas =g;
	this->isDiesel = d;
	this->isElectric = e;
}

Automobile::~Automobile() {
	cout << "Destroying: ~Automobile()";
}

void Automobile::setColor(string c) {
	this->color = c;
}
string Automobile::getColor() {
	return this->color;
}

void Automobile::setBrand(string b) {
	this->brand = b;
}
string Automobile::getBrand() {
	return this-> brand;
}

void Automobile::setYear(int y) {
	this->year = y;
}
int Automobile::getYear() {
	return this->year;
}

void Automobile::setIsGas(bool g) {
	this->isGas=g;
}
bool Automobile::getIsGas() {
	return this->isGas;
}

void Automobile::setIsDiesel(bool d) {
	this->isDiesel = d;
}
bool Automobile::getIsDiesel() {
	return this->isDiesel;
}

void Automobile::setIsElectric(bool e) {
	this->isElectric = e;
}
bool Automobile::getIsElectric() {
	return this->isElectric;
}

string Automobile::toString() {
	string rtn = "";
	rtn+= ("Automobile Brand: " + this->brand + "\tColor: "+this->color+"\tYear: "+to_string(this->year));
	
	if (this->isElectric && (this->isGas || this->isDiesel) ) {//Hybrid Automobile
		if (this->isGas && this->isDiesel) {
			rtn+= "\nVehicle is Hybrid. Uses: Electricity, Gas and Diesel.";
		}
		else {
			if (this->isGas) {
				rtn += "\nVehicle is Hybrid. Uses: Electricity and Gas.";
			}
			else {
				rtn += "\nVehicle is Hybrid. Uses: Electricity and Diesel.";
			}
		}

	}

	if (this->isElectric) {
		rtn += "\nVehicle is Electric.";
	}
	if (this->isGas) {
		rtn += "\nVehicle uses Gas.";
	}
	if (this->isDiesel) {
		rtn += "\nVehicle uses Diesel.";
	}



	rtn += "\n----------------------------------------------------\n\n";

	return rtn;
}