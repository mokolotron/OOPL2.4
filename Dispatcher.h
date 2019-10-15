#pragma once
#include "Bus.h"
#include <conio.h>
#include <list>
#include <stdexcept>
#include <fstream>
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
			cout << "isnt this Bus in the Park" << endl;
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
		cout<<endl << "In Park:" << endl;
		for (Bus& bus : Park)
			bus.show();
		
		cout<<endl << "In Race:" << endl;
		for (Bus& bus : Race)
			bus.show();
		cout << endl << endl;
	}

	void fill_from_file() {
		int number, race;
		string  name ;
		ifstream File("Input.txt");
		try {
			if (!File.is_open()) throw std::runtime_error("Could not open file");
			while (true) {
				File >> number >> name >> race;
				if (File.eof()) break;
				Bus tbus(number, name, race);
				Park.push_front(tbus);
			}
		}
		catch (std::exception& ex) {
			cout << "Error! " << ex.what() << endl;
		}
		File.close();
	}
};

