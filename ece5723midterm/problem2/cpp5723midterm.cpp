#include "A:\cpp5723midterm\cpp5723midterm\accAverage_DP1.h"
#include <iostream>

int main()
{
	int shouldContinue = 1;
	bus busA("00000000");
	bus busB("00000000");
	bus busF("00");
	bus W(8, 'X');
	bus g, c;

	accAverage_DP* myALU = new accAverage_DP(busA, busB, busF, c, g, W);

	do {

		cout << "Enter busA value: ";
		cin >> busA;
		cout << "Enter busB value: ";
		cin >> busB;
		cout << "Enter busF value: ";
		cin >> busF;
		myALU->evl();
		cout << "busA: " << busA << " busB: " << busB << " busF: " << busF << endl;
		cout << "W: " << W << " c: " << c << " g: " << g << endl;
		cout << "Continue? 1:0" << endl;
		cout << "try: " << not1('0');
		cin >> shouldContinue;

	} while (shouldContinue == 1);
};
