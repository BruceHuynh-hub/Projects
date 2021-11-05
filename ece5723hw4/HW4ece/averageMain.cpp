//#include "averageTB.h"
//
//int sc_main(int argc, char* argv[]) {
//
//	averageTB* myAVGTB = new averageTB("Testbench");
//
//	sc_trace_file* VCDFile;
//	VCDFile = sc_create_vcd_trace_file("averageTB");
//	sc_trace(VCDFile, myAVGTB->rst, "rst");
//	sc_trace(VCDFile, myAVGTB->clk, "clk");
//	sc_trace(VCDFile, myAVGTB->start, "start");
//	sc_trace(VCDFile, myAVGTB->stop, "stop");
//	sc_trace(VCDFile, myAVGTB->inBus, "inBus");
//	sc_trace(VCDFile, myAVGTB->outBus, "outBus");
//
//	sc_start(5000, SC_NS);
//
//	return 0;
//}