/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*-- Methodologies for System Level Design and Modeling - ECE 5723
/*-- Homework 3: C++ RT-level design and modeling
/*-- by Nooshin Nosrati
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

#include "classVectorPrimitives.h"

class accAverage_DP {
	bus *A;
	bus* B;
	bus *F;
	bus *W;
	bus* c;
	bus* g;

	Adder* AB_Adder;
	Adder* TwosCompAdder;
	Demux* mainDemux;
	Mux* minMux;
	Mux4x1* W_Mux;
	Comparator* minComparator;

	bus cin = "0";
	bus const1 = "1";
	bus W11, W10, W01, W00, A11, B11, A10, B10, A01, B01, A00, B00, NOTout, cout01, lt, gt, eq;

public:
	accAverage_DP(bus& A, bus& B, bus& F, bus& c, bus& g, bus& W);
	~accAverage_DP();
	void evl();
};
