#include <systemc.h>
#include "A:\SystemC Modeling Codes-1\SystemC Modeling Codes\4_partsLibrary\partsLibrary.h"

SC_MODULE(accAverage_DP) {

public:
	sc_in<sc_logic> rst, clk, enableReg, selMux, selTri, parallel_load_en, shift_en;
	sc_in<sc_lv<8>> inBus;
	sc_out <sc_lv<8>> outBus;

	sc_signal<sc_lv<8>> outOpr, outMux, outReg, outAdd;
	sc_uint<8> inBus_uint, outReg_uint, outOpr_uint;
	sc_logic zero = SC_LOGIC_0;
	

	// instantiation
	octalMux2to1* myMux;
	dRegisterRaE* myReg;
	octalTriState* myTri;
	nBitAdder* myAdder;
	rShifterRaEL* myShifter;

	SC_CTOR(accAverage_DP) {
		outOpr = "00000000";
		outMux = "00000000";
		outReg = "00000000";



		myMux = new octalMux2to1("Multiplexer");
		myMux->sel(selMux);
		myMux->ain(outOpr);
		myMux->bin(inBus);
		myMux->yout(outMux);


		myReg = new dRegisterRaE("Register");
		myReg->clk(clk);
		myReg->rst(rst);
		myReg->cen(enableReg);
		myReg->regin(outMux);
		myReg->regout(outReg);



		myTri = new octalTriState("Tri-State");
		myTri->sel(selTri);
		myTri->ain(outReg);
		myTri->yout(outBus);

		myAdder = new nBitAdder("8-bit-adder");
		myAdder->ain(inBus);
		myAdder->bin(outReg);
		//myAdder->ci();
		myAdder->addout(outAdd);
		//myAdder->co();



		myShifter = new rShifterRaEL("Bit-shifter");
		myShifter->rst(rst);
		myShifter->clk(clk);
		myShifter->pld(parallel_load_en);
		myShifter->sen(shift_en);
		//myShifter->sin();
		myShifter->parin(outAdd);
		myShifter->shftout(outOpr);



			cout << "outOpr: " << outOpr;
		


	}
};