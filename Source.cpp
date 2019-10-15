#include "Dispatcher.h"
#include "Source.h"

using namespace std;

int main() {
	Dispatcher dispatcher;
	int input = 1;
	while (input != 0) {
		cout << "1 to fill lists" << endl <<
			"2 to show Buses " << endl <<
			"3 to start new race" << endl <<
			"4 to end race" << endl <<
			"0 to exit" << endl;
		cin >> input;
		switch (input)
		{
		case 1: cout<<" 1 to fill from keyboard, 2 to fill from file"; 
			cin >> input; 
			if (input == 1) dispatcher.fill();
			else if (input == 2) dispatcher.fill_from_file();
			break;
		case 2: dispatcher.show() ; break;
		case 3: cout << "Enter number of bus which must to start ";
				cin >> input;
				dispatcher.onRace(input);
				break;
		case 4: cout << "Enter number of bus which must to stop ";
			cin >> input;
			dispatcher.onPark(input);
			break; 
		default:
			break;
		}
		system("pause");
		system("cls");
	}

	return 0;
}