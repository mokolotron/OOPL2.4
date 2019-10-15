#include "Dispatcher.h"
#include "Source.h"

using namespace std;

int main() {
	Dispatcher dispatcher;
	dispatcher.fill();
	dispatcher.onRace(1);
	dispatcher.show();
	dispatcher.onPark(1);
	dispatcher.show();
	return 0;
}