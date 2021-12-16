#include <systemc.h>

class stack_push_if: virtual public sc_interface
	{
		public:
			virtual void b_push(sc_lv<8> ) = 0;
			virtual void init() = 0;
};

class stack_pop_if: virtual public sc_interface
	{
		public:
			virtual void b_pop(sc_lv<8> &) = 0;
};

