#include "sharedFIFOPutGet.h"

SC_MODULE (sharedFIFOPutGet_TB) {
	
	sharedFIFO<sc_lv<8>, 1, 4, 3> * BusA;
	initiators<0, 3>* INI0;
	targets<0, 5>* TAR0;
	targets<1, 5>* TAR1;
	targets<2, 5>* TAR2;
	targets<3, 5>* TAR3;
	
	SC_CTOR(sharedFIFOPutGet_TB) {
		BusA = new sharedFIFO<sc_lv<8>, 1, 4, 3>;

		INI0 = new initiators<0, 3>("Initiator0");
		INI0->out(*BusA);

		TAR0 = new targets<0, 5>("Target0");
		TAR0->in(*BusA);
		TAR1 = new targets<1, 5>("Target1");
		TAR1->in(*BusA);
		TAR2 = new targets<2, 5>("Target2");
		TAR2->in(*BusA);
		TAR3 = new targets<3, 5>("Target3");
		TAR3->in(*BusA);
	}
};

