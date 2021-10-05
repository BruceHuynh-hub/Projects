#include "averager.h"


int main() {

	int bit_num;
	int keepgoing;
	int wantEnd;
	int wantStart;
	cout << "Enter N amount of bits: "; cin >> bit_num;
	bus d(bit_num);
	bus q(bit_num);
	bus start_input(3);
	bus END(3);
	bus c, r;

	averager* myAveragerTest = new averager(start_input, END, d, c, r, q);

	do {
		cout << "Enter " << bit_num << " bits for d: "; cin >> d;
		c = "P";
		cout << "Would you like to enter a start pulse? (1/0): "; cin >> wantStart;
		if (wantStart == 1) {
			cout << "Enter 3 bits for start: "; cin >> start_input;
		}
		cout << "Would you like to enter an end pulse? (1/0): "; cin >> wantEnd;
		if (wantEnd == 1) {
			cout << "Enter 3 bits for end: "; cin >> END;
		}
		myAveragerTest->evl();


		cout << "q output: " << q << '\n';

		cout << "stateOn = " << myAveragerTest->stateOn << '\n';
		cout << "avgBus.v = " << myAveragerTest->avgBus << '\n';
		cout << "start = " << start_input << '\n';
		cout << "end = " << END << '\n';
		cout << "start[0] = " << start_input[0] << '\n';
		cout << "start[1] = " << start_input[1] << '\n';
		cout << "start[2] = " << start_input[2] << '\n';


		
		cout << "Continue? (1/0): "; cin >> keepgoing;
		
	} while (keepgoing > 0);
	return 0;
} 
