#include "averageBFMTB.h"

int sc_main(int argc, char* argv[]) {

	averageBFMTB* myAVGBFMTB = new averageBFMTB("Testbench");

	sc_trace_file* VCDFile;
	VCDFile = sc_create_vcd_trace_file("averageTB");
	sc_trace(VCDFile, myAVGBFMTB->rst, "rst");
	sc_trace(VCDFile, myAVGBFMTB->clk, "clk");
	sc_trace(VCDFile, myAVGBFMTB->start, "start");
	sc_trace(VCDFile, myAVGBFMTB->stop, "stop");
	sc_trace(VCDFile, myAVGBFMTB->inBus, "inBus");
	sc_trace(VCDFile, myAVGBFMTB->outBus, "outBus");

	sc_start(5000, SC_NS);

	return 0;
}