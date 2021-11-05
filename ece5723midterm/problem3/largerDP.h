#include "A:\systemCece5723midterm\systemCece5723midterm\partsLibrary.h"


SC_MODULE(largerDP) {
public:

	sc_in<sc_logic> clk, rst, triEn, regEn;
	sc_in<sc_lv<8>> inBus;
	sc_out<sc_lv<8>> outBus;

	sc_signal<sc_logic> compGT, compLT, compEQ;
	sc_signal<sc_lv<8>> outMux, outReg;


	// instantiation
	octalMux2to1* myMux;
	dRegisterRaE* myReg;
	octalTriState* myTri;
	Comparator8bit* myComparator;

	SC_CTOR(largerDP) {
		outMux, outReg = "00000000";

		myComparator = new Comparator8bit("Comparator");
		myComparator->inA(inBus);
		myComparator->inB(outReg);
		myComparator->gt(compGT);
		myComparator->lt(compLT); // not used
		myComparator->eq(compEQ); // not used

		myMux = new octalMux2to1("Multiplexer");
		myMux->sel(compGT);
		myMux->ain(outReg);
		myMux->bin(inBus);
		myMux->yout(outMux);

		myReg = new dRegisterRaE("Register");
		myReg->clk(clk);
		myReg->rst(rst);
		myReg->cen(regEn);
		myReg->regin(outMux);
		myReg->regout(outReg);

		myTri = new octalTriState("Tri-State");
		myTri->sel(triEn);
		myTri->ain(outReg);
		myTri->yout(outBus);

	}

};
