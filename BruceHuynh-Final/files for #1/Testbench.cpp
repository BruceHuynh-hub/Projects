#include "Testbench.h"
#include <sysc/datatypes/bit/sc_lv.h>

void Testbench::inputing() {

	x = 0.10546875;
	wait(20, SC_NS);
	start = SC_LOGIC_1;
	wait(20, SC_NS);
	start = SC_LOGIC_0;
}


void Testbench::clocking() {
	while (true)
	{
		clk = sc_logic('0');
		wait(10, SC_NS);
		clk = sc_logic('1');
		wait(10, SC_NS);
	}
}

void Testbench::reseting() {
	rst = (sc_logic)'0';
	wait(5, SC_NS);
	rst = (sc_logic)'1';
	wait(5, SC_NS);
	rst = (sc_logic)'0';
};

void Testbench::display() {
	cout << "start = " << start << endl;
	cout << "x = " << x << endl;

	if (ready == SC_LOGIC_1) {
		cout << "cos(" << x << ") is " << out;
	}

};