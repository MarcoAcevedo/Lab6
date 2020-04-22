#include "Car.h"
#include "Automobile.h"
#include <iostream>
#include <string>

Car::Car() {

}
Car::Car(string c, string b, int y, bool d, bool e, bool g, string t, string bra, string m, string v)
:Automobile(c, b, y, d, e,g) {
	this->licensePlate = t;
	this->brand = bra;
	this->model = m;
	this->vin = v;
}
Car::~Car() {
	cout << "Destroying: ~Car()";
}

void Car::setLicensePlate(string t) {
	this->licensePlate = t;
}
string Car::getLicensePlate() {
	return this->licensePlate;
}

void Car::setBrand(string b) {
	this->brand = b;
}
string Car::getBrand() {
	return this->brand;
}

void Car::setModel(string m) {
	this->model = m;
}
string Car::getModel() {
	return 	this->model;
}

void Car::setVin(string v) {
	this->vin = v;
}
string Car::getVin() {
	return this->vin;
}

string Car::toString() {
	string str = "";
	str += ("Car Brand: " + this->brand + "\tModel: "+ this->model + "\tYear: " + to_string(this->year) + "\tColor: " + this->color);

	if (this->isElectric && (this->isGas || this->isDiesel)) {//Hybrid Automobile
		if (this->isGas && this->isDiesel) {
			str += "\nVehicle is Hybrid. Uses: Electricity, Gas and Diesel\t";
		}
		else {
			if (this->isGas) {
				str += "\nVehicle is Hybrid. Uses: Electricity and Gas\t";
			}
			else {
				str += "\nVehicle is Hybrid. Uses: Electricity and Diesel\t";
			}
		}

	}

	if (this->isElectric) {
		str += "\nVehicle is Electric\t";
	}
	if (this->isGas) {
		str += "\nVehicle uses Gas\t";
	}
	if (this->isDiesel) {
		str += "\nVehicle uses Diesel\t";
	}

	str += ("Vin: " + this->vin + "\tLicense Plate: " + this->licensePlate);

	str += "\n----------------------------------------------------------------------\n";

	return str;
}