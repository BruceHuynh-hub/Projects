#include "Testbench.h"
#pragma once

int sc_main(int argc, char** argv) {

	Testbench TOP("Testbench");

	sc_trace_file* vcdfile;
	vcdfile = sc_create_vcd_trace_file("cosTaylorSeries");
	sc_trace(vcdfile, TOP.clk, "clk");
	sc_trace(vcdfile, TOP.rst, "rst");
	sc_trace(vcdfile, TOP.start, "start");
	sc_trace(vcdfile, TOP.x, "x");
	sc_trace(vcdfile, TOP.out, "out");
	sc_trace(vcdfile, TOP.ready, "ready");


	sc_start(1000, SC_NS);

	return 0;
}
