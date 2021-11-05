#include "largerBFMTB.h"

int sc_main(int argc, char* argv[]) {

	largerBFMTB* myTB = new largerBFMTB("Testbench_BFM");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("largerTBtest");
	sc_trace(VCDFile, myTB->rst, "rst");
	sc_trace(VCDFile, myTB->clk, "clk");
	sc_trace(VCDFile, myTB->start, "start");
	sc_trace(VCDFile, myTB->stop, "stop");
	sc_trace(VCDFile, myTB->inBus, "inBus");
	sc_trace(VCDFile, myTB->outBus, "outBus");

	sc_start(5000, SC_NS);

	return 0;
}