#include "largerTOP.h"

SC_MODULE(largerTB) {

	sc_signal<sc_logic> rst, clk, start, stop, regEn, triEn;
	sc_signal<sc_lv<8>> inBus, outBus;
	largerTOP* myTop;

	SC_CTOR(largerTB) {

		myTop = new largerTOP("TopMod");
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
	void display();
	void evl();

};