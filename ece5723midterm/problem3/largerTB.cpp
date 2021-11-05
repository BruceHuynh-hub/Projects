#include "A:\systemCece5723midterm\systemCece5723midterm\largerTB.h"
#include <iostream>

void largerTB::display() {
    cout << "-------------------------------------------" << endl;
    cout << "inBus value: " << inBus.read() << " outBus value: " << outBus.read() << endl;

}

void largerTB::resetting() {
    wait(7, SC_NS);
    rst = SC_LOGIC_0;
    wait(11, SC_NS);
    rst = SC_LOGIC_1;
    wait(4, SC_NS);
    rst = SC_LOGIC_0;

}

void largerTB::clocking() {
    int i;
    clk = SC_LOGIC_1;
    for (i = 0; i < 50; i++) {
        clk = SC_LOGIC_0;
        wait(50, SC_NS);
        clk = SC_LOGIC_1;
        wait(50, SC_NS);
    }
}

void largerTB::evl() {
    while (true) {
        // Scenario 1
        //inBus = "00000000";
        //stop = SC_LOGIC_0;
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //start = SC_LOGIC_1;
        //wait(100, SC_NS);
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //inBus = "10000100";
        //wait(200, SC_NS);
        //inBus = "00001010";
        //wait(250, SC_NS);
        //inBus = "00010000";
        //wait(250, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_1;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(2000, SC_NS);

        // Scenario 2
        //inBus = "00000000";
        //stop = SC_LOGIC_0;
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //start = SC_LOGIC_1;
        //wait(100, SC_NS);
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //inBus = "10000000";
        //wait(400, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_1;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(2000, SC_NS);

        // Scenario 3
        //inBus = "10001111";
        //stop = SC_LOGIC_0;
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //start = SC_LOGIC_1;
        //wait(100, SC_NS);
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //inBus = "11100100";
        //wait(200, SC_NS);
        //inBus = "11111010";
        //wait(250, SC_NS);
        //inBus = "10010000";
        //wait(250, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_1;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(2000, SC_NS);

        // Scenario 4
        //inBus = "00000000";
        //stop = SC_LOGIC_0;
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //start = SC_LOGIC_1;
        //wait(100, SC_NS);
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //inBus = "10000100";
        //wait(200, SC_NS);
        //inBus = "00001010";
        //wait(250, SC_NS);
        //inBus = "00010000";
        //wait(250, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_1;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(1500, SC_NS);
        //inBus = "00000100";
        //stop = SC_LOGIC_0;
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //start = SC_LOGIC_1;
        //wait(100, SC_NS);
        //start = SC_LOGIC_0;
        //wait(100, SC_NS);
        //inBus = "00001000";
        //wait(200, SC_NS);
        //inBus = "00000001";
        //wait(250, SC_NS);
        //inBus = "00000010";
        //wait(250, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_1;
        //wait(100, SC_NS);
        //stop = SC_LOGIC_0;
        //wait(2000, SC_NS);

    }

}