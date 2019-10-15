#pragma once
#include "Bus.h"
#include <conio.h>
#include <list>
using namespace std;
class Dispatcher
{
private:
	list<Bus> Park;
	list<Bus> Race;
public:
	Dispatcher() {
		list<Bus> Park;
		list<Bus> Race;
	}

	void onRace(int _number) {
		bool succes;
		list<Bus>::iterator it = Park.begin();
		list<Bus>::iterator end = Park.end();
		int position = get_Bus(_number, it, end);
		if (position != -1) {
			advance(it, position);
			Race.push_back(*it);
			Park.remove(*it);
		}
		else {
			cout << "isnt this Bus in the Race" << endl;
		}
	};

	void onPark(int _number) {
		list<Bus>::iterator it = Race.begin();
		list<Bus>::iterator end = Race.end();
		int position = get_Bus(_number, it, end);
		
		if ( position != -1) {
			advance(it, position);
			Park.push_back(*it);
			Race.remove(*it);
		}
		else {
			cout << "isnt this Bus in the Race" << endl;
		}
	}


	void fill() {
		Bus tempBus;
		int input;
		while (true) {
			tempBus.fill();
			Park.push_front(tempBus);
			cout << "Enter 0 to exit" << endl;
			cin >> input;
			if (input == 0) break;
		}
	}


	int get_Bus(int number, list<Bus>::iterator it, list<Bus>::iterator end) {
		int position = -1;
		for (; it != end; it++) {
			position++;
			if (it->get_number() == number) {
				return position;
			}
		}
		return position;
	}

	void show() {
		cout << "In Park:" << endl;
		for (Bus& bus : Park)
			bus.show();

		cout << "In Race:" << endl;
		for (Bus& bus : Race)
			bus.show();
	}

};

