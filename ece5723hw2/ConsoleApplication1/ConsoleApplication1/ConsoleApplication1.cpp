// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "ConsoleApplication1.h"



Statemachine::Statemachine(wire& in, wire& clk, wire& rst, wire& out) {
    this->in = &in; this->clk = &clk; this->rst = &rst; this->out = &out;
    Nstate = 0;
    Pstate = 0;
}

void Statemachine::evl() {
    out->value = '0';

    switch (Pstate) {
    case 0: 
        if (in->value == '1') {
            Nstate = 1;
            out->value = '0';
        }
        else {
            Nstate = 0;
            out->value = '0';
        }
        break;
    
    case 1:
        if (in->value == '1') {
            Nstate = 1;
            out->value = '0';
        }
        else {
            Nstate = 2;
            out->value = '0';
        }
        break;

    case 2:
        if (in->value == '1') {
            Nstate = 1;
            out->value = '0';
        }
        else {
            Nstate = 3;
            out->value = '0';
        }
        break;

    case 3:
        if (in->value == '1') {
            Nstate = 4;
            out->value = '0';
        }
        else {
            Nstate = 0;
            out->value = '0';
        }
        break;

    case 4:
        if (in->value == '1') {
            Nstate = 1;
            out->value = '1';
        }
        else {
            Nstate = 2;
            out->value = '0';
        }
        break;


    }

    if (rst->value == '1')
        Pstate = 0;
    else if (clk->value == 'P')
        Pstate = Nstate;


}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
