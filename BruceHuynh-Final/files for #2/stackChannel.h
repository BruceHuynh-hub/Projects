#include "interfaceClasses.h"

class stack : public stack_push_if, public stack_pop_if {
public:
	stack() {tos=0;};
	void b_push(sc_lv<8> data);
	void init();
	void b_pop(sc_lv<8> &data);
	sc_event pop_event, push_event;

private:
	sc_lv<8> contents[17];
	int tos;
};
