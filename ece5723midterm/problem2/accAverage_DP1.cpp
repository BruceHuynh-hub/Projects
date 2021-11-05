/*--------------------------------------------------------------------------------------------------------------------------------------------*/
/*-- Methodologies for System Level Design and Modeling - ECE 5723
/*-- Homework 3: C++ RT-level design and modeling
/*-- by Nooshin Nosrati
/*--------------------------------------------------------------------------------------------------------------------------------------------*/

#include "accAverage_DP1.h"

accAverage_DP::accAverage_DP(bus& A_, bus& B_, bus& F_, bus& c_, bus& g_, bus& W_) :
	A(&A_), B(&B_), F(&F_), c(&c_), g(&g_), W(&W_){
		

	// instantiate modules

	mainDemux = new Demux(*A, *B, *F, A00, B00, A01, B01, A10, B10, A11, B11);
	//cout << "A00: " << A00 << " B00: " << B00 << " A01: " << A01 << " B01: " << B01 << " A10: " << A10 << " B10: " << B10 << " A11: " << A11 << " B11: " << B11 << endl;
	AB_Adder = new Adder(A11, B11, cin, *c, W11);
	// AND gate
	W10 = A10 && B10;
	// Twos complement
	NOTout = ~A01; 	// NOT gate
	TwosCompAdder = new Adder(NOTout, const1, cin, cout01, W01);
	// Minimum
	minComparator = new Comparator(A00, B00, lt, eq, *g); // lt and eq not used
	minMux = new Mux(A00, B00, *g, W00);

	// Final output W
	W_Mux = new Mux4x1(W00, W01, W10, W11, *F, *W);

	// bus cin = "0";
	// bus const1 = "1";
	//	bus W11, W10, W01, W00, A11, B11, A10, B10, A01, B01, A00, B00, NOTout, cout01, lt, gt, eq;
}

void accAverage_DP::evl(){
	// perform evaluate function on the modules
	mainDemux->evl();
	//cout << "A00: " << A00 << " B00: " << B00 << " A01: " << A01 << " B01: " << B01 << " A10: " << A10 << " B10: " << B10 << " A11: " << A11 << " B11: " << B11 << endl;
	AB_Adder->evl();
	TwosCompAdder->evl();
	minComparator->evl();
	minMux->evl();
	W_Mux->evl();

}
