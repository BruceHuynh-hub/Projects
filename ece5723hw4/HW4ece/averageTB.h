#include "HW4ece.h"

SC_MODULE(averageTB) {

	int ij;
	int NumOfInputs;
	sc_signal<sc_logic> rst, clk, start, stop, enableReg, selMux, selTri;
	sc_signal<sc_lv<8>> inBus, outBus;
	accAverage_Top* myTop;

	SC_CTOR(averageTB) {

		myTop = new accAverage_Top("Top-module");
		myTop->rst(rst);
		myTop->clk(clk);
		myTop->start(start);
		myTop->stop(stop);
		myTop->inBus(inBus);
		myTop->outBus(outBus);


		SC_THREAD(resetting);
		SC_THREAD(clocking);
		SC_METHOD(display);
		sensitive << clk;
		SC_THREAD(evl);
		sensitive << clk << rst;
	}

	void resetting();
	void clocking();
	void evl();
	void display();
};

