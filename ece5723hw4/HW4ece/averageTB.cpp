#include "averageTB.h"

void averageTB::display() {
    cout << "-------------------------------------------" << endl;
    cout << "inBus value: " << inBus.read() << " outBus value: " << outBus.read() << endl;
    
}

void averageTB::resetting() {
        wait(7, SC_NS);
        rst = SC_LOGIC_0;
        wait(11, SC_NS);
        rst = SC_LOGIC_1;
        wait(4, SC_NS);
        rst = SC_LOGIC_0;

}

void averageTB::clocking() {
    int i;
    clk = SC_LOGIC_1;
    for (i = 0; i < 50; i++) {
        clk = SC_LOGIC_0;
        wait(50, SC_NS);
        clk = SC_LOGIC_1;
        wait(50, SC_NS);
    }
}
 
void averageTB::evl() {
    while (true) {
   
        stop = SC_LOGIC_0;
        start = SC_LOGIC_0;
        wait(100, SC_NS);
        start = SC_LOGIC_1;
        wait(100, SC_NS);
        start = SC_LOGIC_0;
        wait(100, SC_NS);
        inBus = "00000100";
        wait(200, SC_NS);
        inBus = "00001010";
        wait(250, SC_NS);
        inBus = "00010000";
        wait(250, SC_NS);
        stop = SC_LOGIC_0;
        wait(100, SC_NS);
        stop = SC_LOGIC_1;
        wait(100, SC_NS);
        stop = SC_LOGIC_0;
        wait(2000, SC_NS);
        //wait();
    }
    //inBus = "00001010";
    //wait(250, SC_NS);
    //inBus = "10000000";
    //wait(250, SC_NS);
    //inBus = "00001010";
    //wait(250, SC_NS);
}


