#pragma once
#include <string>
#include <iostream>
using namespace std;

class Bus
{
private:
	int number;
	string driver;
	int number_race;
public:
	Bus() {
		number = 0;
		driver = "default driver";
		number_race = 0;
	};

	Bus(int _number, string _driver, int _number_race) {
		number = _number;
		driver = _driver;
		number_race = _number_race;
	}

	void fill() {
		cout << "ENTER: number , driver name , number race" << endl;
		cin >> number >> driver >> number_race;
	}

	int get_number() {
		return number;
	}

	bool operator == (const Bus &obj) const {
		return number == obj.number;
	}

	void show() {
		cout <<' '<< number << ' ' << driver << ' ' << number_race<<endl;
	}
};

