#include "Testbench.h"
#include <sysc/datatypes/fx/sc_ufixed.h>
#include <sysc/datatypes/bit/sc_lv.h>

void Testbench::inputing() {

	typedef sc_dt::sc_ufixed<8, 1, SC_RND> fixed_type;


	wait(13, SC_NS);
	x = "10001000";
	wait(200, SC_NS);
	double inBusval = x.read().to_uint();
	inBusval = inBusval / 128; // shift 7 bits for 1 integer part and 7 fractional parts
	cout << "inBusval: " << inBusval << endl ;

	double res = 1, sign = 1, factorial = 1, pow = 1; // cos taylor series for 4 iterations
	for (int i = 1; i < 5; i++) {
		sign = sign * -1;
		factorial = factorial * (2 * i - 1) * (2 * i);
		pow = pow * inBusval * inBusval;
		res = res + sign * pow / factorial;
	}


	//double n, bin, f1 = 0.0, f2, f3 = 0.1;
	//int x, x1 = 0;
	//int fact = 1, rem, temp, i;

	//n = res;

	//x = n;
	//f2 = n - x;
	//while (x != 0) {
	//	rem = x % 2;
	//	x1 = x1 + rem * fact;
	//	x = x / 2;
	//	fact = fact * 10;
	//}

	//for (i = 1; i <= 8; i++) {
	//	f2 = f2 * 2;
	//	temp = f2;
	//	f1 = f1 + f3 * temp;

	//	if (temp == 1)
	//		f2 = f2 - temp;

	//	f3 = f3 / 10;
	//}
	//bin = x1 + f1;
	//bin = bin * 10000000;
	

	
	//sc_lv<8> sd = res;


	cout << "res = " << res << endl;
	//cout << "l = " << sd << endl;
	//cout << "Equivalent Binary value = " << bin;
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

void Testbench::start_end() {

}