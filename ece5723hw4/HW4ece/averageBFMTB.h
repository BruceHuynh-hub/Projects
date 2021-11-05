#include "averageBFM.h";

SC_MODULE(averageBFMTB) {
	sc_signal<sc_logic> rst, clk, start, stop;
	sc_signal<sc_lv<8>> inBus;
	sc_signal <sc_lv<8>> outBus;

	averageBFM<16>* myBFM;

	SC_CTOR(averageBFMTB) {
		myBFM = new averageBFM<16>("my-BFM-instance");
		myBFM->rst(rst);
		myBFM->clk(clk);
		myBFM->start(start);
		myBFM->stop(stop);
		myBFM->inBus(inBus);
		myBFM->outBus(outBus);

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