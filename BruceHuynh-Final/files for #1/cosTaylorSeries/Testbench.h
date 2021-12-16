#pragma once
#include "Taylor.h"

SC_MODULE(Testbench) {
	sc_signal<sc_logic> clk, rst, start;
	sc_signal<sc_lv<8>> x;
	sc_signal<sc_lv<8>> out;
	sc_signal<sc_logic> ready;

	cosTaylorSeries* CTS;

	SC_CTOR(Testbench) {

		CTS = new cosTaylorSeries("cosTaylorSeries");
		(*CTS)(clk, rst, start, x, out, ready);


		SC_THREAD(inputing);
		SC_THREAD(reseting);
		SC_THREAD(clocking);
		SC_THREAD(start_end);
	}

	
	void inputing();
	void reseting();
	void clocking();
	void start_end();

};