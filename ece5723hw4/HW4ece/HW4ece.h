#include "accAverage_CU.h"
#include "accAverage_DP.h"

SC_MODULE(accAverage_Top) {
	sc_in<sc_logic> rst, clk, start, stop;
	sc_in<sc_lv<8>> inBus;
	sc_out <sc_lv<8>> outBus;

	sc_signal<sc_logic> enableReg, selMux, selTri, parallel_load_en, shift_en;

	accAverage_DP* myDatapath;
	accAverage_CU* myController;



	SC_CTOR(accAverage_Top) {
		myController = new accAverage_CU("controller");
		myController->clk(clk);
		myController->rst(rst);
		myController->start(start);
		myController->stop(stop);
		myController->enableReg(enableReg);
		myController->selMux(selMux);
		myController->selTri(selTri);
		myController->parallel_load_en(parallel_load_en);
		myController->shift_en(shift_en);


		myDatapath = new accAverage_DP("datapath");
		myDatapath->rst(rst);
		myDatapath->clk(clk);
		myDatapath->inBus(inBus);
		myDatapath->outBus(outBus);
		myDatapath->enableReg(enableReg);
		myDatapath->selMux(selMux);
		myDatapath->selTri(selTri);
		myDatapath->parallel_load_en(parallel_load_en);
		myDatapath->shift_en(shift_en);

	}
};