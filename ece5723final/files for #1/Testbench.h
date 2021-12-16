#pragma once
#include "5723problem1.h"

SC_MODULE(Testbench) {
	sc_signal<sc_logic> clk, rst, start;
	sc_signal<float> x;
	sc_signal<float> out;
	sc_signal<sc_logic> ready;
	cosTaylorSeries* CTS;




	SC_CTOR(Testbench) {

		CTS = new cosTaylorSeries("cosTaylorSeries");
		(*CTS)(clk, rst, start, x, out, ready);


		SC_THREAD(inputing);
		SC_THREAD(reseting);
		SC_THREAD(clocking);
		sensitive << clk;

		SC_THREAD(display)
		sensitive << clk;
	}

	
	void inputing();
	void reseting();
	void clocking();
	void display();


};