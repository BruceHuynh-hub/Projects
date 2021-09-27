#include "D:\Logic Modeling Cpp Codes v21\Logic Modeling Cpp Codes v21\18_Logic Class Inheritance_Wire\inheritedLogicClassesPrimitives.h"



class Statemachine {
	wire *in, *clk, *rst, *out;

	int Nstate, Pstate;
public:
	Statemachine(wire& in, wire& rst, wire& clk, wire& out);
	~Statemachine();
	void evl();

};