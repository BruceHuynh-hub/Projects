#include "largerDP.h"
#include "largerCU.h"

SC_MODULE(largerTOP) {

	sc_in<sc_lv<8>> inBus;
	sc_in<sc_logic> clk, rst, start, stop;
	sc_out<sc_lv<8>> outBus;

	sc_signal<sc_logic> triEn, regEn;


	largerDP* myDP;
	largerCU* myCU;

	SC_CTOR(largerTOP) {
		myDP = new largerDP("datapath");
		myDP->rst(rst);
		myDP->clk(clk);
		myDP->inBus(inBus);
		myDP->triEn(triEn);
		myDP->regEn(regEn);
		myDP->outBus(outBus);


		myCU = new largerCU("controller");
		myCU->start(start);
		myCU->stop(stop);
		myCU->rst(rst);
		myCU->clk(clk);
		myCU->triEn(triEn);
		myCU->regEn(regEn);
	}
};