#include "Automobile.h"
#include "Car.h"
#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib> 
#include <ctime> 
#include <algorithm>

using namespace std;

void menu();
bool selectOption();
void printCar();
void addCar();
char inputChar;
void delay(int);
Car carList[1024];
bool exitVar = false;
int numCars = 0;
bool inputYesorNo(string);

int main() {
	while (! exitVar) {
		menu();
		exitVar = selectOption();
	}
}

void menu() {
	system("CLS");
	cout << "Car System: Type option, then press Enter\n\n";
	cout << "1. Enter a new car\n";
	cout << "2. View all cars\n";
	cout << "3. Exit\n\n";
}

bool selectOption() {
	cin >> inputChar;
	switch (inputChar) {
	case '1'://Enter a new car
		addCar();
		return false;
		break;

	case '2'://View all cars
		printCar();
		return false;
		break;

	case '3'://Exit
		return true;
		break;

	default:
		system("CLS");
		cout << "\nInvalid menu selection. Type option number only then press 'Enter'\n";
		cin.clear();
		cin.ignore(10000, '\n');
		delay(1);
		return false;
		break;
	}
	return false;
}

void addCar() {
	string color;
	string autoBrand;
	int year;
	bool isDiesel;
	char inputChar;
	bool isElectric;
	bool isGas;
	string licensePlate, carBrand, model, vin;
	
	system("CLS");
	cout << "Adding new car to the system.\n";

	cout << "\nType Car's License Plate or Registration; then press 'Enter' \n";
	cin >> licensePlate;

	if (numCars!=0) {
		string cmp;
		for (int i = 0; i < numCars; i++) {
			cmp = carList[i].getLicensePlate();
			if (cmp == licensePlate) {
				cout << "Car already in the system.\n";
				delay(3);
				return;
			}
		}
	}

	cout << "\nType Car Brand; then press 'Enter' \n";
	cin >> carBrand;

	cout << "\nType Car Model; then press 'Enter' \n";
	cin >> model;

	cout << "\nType Car's Year; then press 'Enter' NUMBERS ONLY \n";
	cin >> year;

	cout << "\nType Car's Color; then press 'Enter' \n";
	cin >> color;

	cout << "\nType Car's VIN (17 alpha-numerical-characters only) then press 'Enter' \n";
	cin >> vin;

	cout << "\nIs the car Electric? Type 'y' for yes or 'n' for no. Type only 1 letter.\n";
	isElectric = inputYesorNo("\nIs the car Electric? Type 'y' for yes or 'n' for no. Type only 1 letter.\n");

	cout << "\nDoes the Car use Diesel? Type 'y' for yes or 'n' for no. Type only 1 letter.\n";
	isDiesel = inputYesorNo("\nDoes the Car use Diesel? Type 'y' for yes or 'n' for no. Type only 1 letter.\n");

	cout << "\nDoes the Car use regular Gas? Type 'y' for yes or 'n' for no. Type only 1 letter.\n";
	isGas = inputYesorNo("\nDoes the Car use regular Gas? Type 'y' for yes or 'n' for no. Type only 1 letter.\n");

	Car newCar = Car(color, carBrand, year, isDiesel, isElectric, isGas, licensePlate, carBrand, model, vin);

	carList[numCars++] = newCar;
}

void printCar() {
	system("CLS");
	for (int i = 0;i<numCars;i++) {
		cout << carList[i].toString();
	}
	cout << "Type in any key then press 'Enter' to continue.\n\n";
	cin >> inputChar;
	cin.clear();
	cin.ignore(10000, '\n');
	system("CLS");
}

void delay(int i) {
	chrono::seconds dura(i);
	this_thread::sleep_for(dura);
}

bool inputYesorNo(string messege) {
	cin >> inputChar;
	while (!cin || (inputChar != 'y' && inputChar != 'n')) {
		cin.clear();
		cin.ignore(10000, '\n');
		system("CLS");
		cout << "\nError. Type either the letter 'y' or 'n'. Nothing else typed is valid \n";
		cout << messege;
		cin >> inputChar;
	}
	if (inputChar=='y') {
		return true;
	}
	return false;
}