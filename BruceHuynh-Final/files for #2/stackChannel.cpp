#include "stackChannel.h"

void stack::b_push(sc_lv<8> data) {
	cout << "Pushing" << endl;
	cout << "tos = " << tos << endl;
	if (tos == 17)
	{
		cout << "waiting for pop event" << endl;
		wait(pop_event);
		contents[tos++] = data;

		push_event.notify();
		}
	else if (tos < 17){
		contents[tos++] = data;
	}

}
void stack::init() {
	tos = 0;
}
void stack::b_pop(sc_lv<8>& data) {
	cout << "Popping" << endl;
	cout << "tos = " << tos << endl;
	if (tos == 0)
	{
		cout << "waiting for push event" << endl;
		wait(push_event);
		data = contents[--tos];
		pop_event.notify();
		}
	else if (tos > 0) {
		data = contents[--tos];
		pop_event.notify();
	}

}
