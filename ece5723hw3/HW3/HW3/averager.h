#include "D:\Expo 10-4-15-1\Expo 10-4-15\classVectorPrimitives.h"


class averager{

public:
	bus* start1;
	bus* end1;
	bus* D1;
	bus* C1;
	bus* R1;
	bus* Q1;
	//int present_stateS;
	//int next_stateS;
	//int present_stateE;
	//int next_stateE;
	int stateOn;
	int currAvg;
	bus avgBus = "00000000";

	averager(bus &start_input, bus &END, bus& D, bus& C, bus& R, bus& Q);
	~averager();
	void evl();
};