#include "largerBFM.h"

SC_MODULE(largerBFMTB) {

	sc_signal<sc_logic> rst, clk, start, stop;
	sc_signal<sc_lv<8>> inBus;
	sc_signal<sc_lv<8>> outBus;

	largerBFM<16>* lTB;

	SC_CTOR(largerBFMTB) {
		lTB = new largerBFM<16>("My_largerBFM_instance");
		lTB->start(start);
		lTB->stop(stop);
		lTB->rst(rst);
		lTB->clk(clk);
		lTB->inBus(inBus);
		lTB->outBus(outBus);

		SC_THREAD(resetting);
		SC_THREAD(clocking);
		SC_METHOD(display);
		sensitive << clk;
		SC_THREAD(evl);
		sensitive << clk << rst;

	}
	void resetting();
	void clocking();
	void display();
	void evl();
};