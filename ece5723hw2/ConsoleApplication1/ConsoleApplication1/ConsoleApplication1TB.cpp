
#include "ConsoleApplication1.h"





int main()
{
    int ij;
    wire in;
    wire clk;
    wire rst;
    wire out;


    Statemachine* Statemachine1 = new Statemachine(in, clk, rst, out);

    rst.value = '1';
    Statemachine1->evl();
    rst.value = '0';

    do {
        for (int i = 0; i < 20; i++) {
            cout << "\n Enter 1 bit for the input: "; cin >> in.value;
            clk.value = 'P';
            Statemachine1->evl();
            cout << "\n" << out.value;
        }

        cout << "\n" << "Continue (0 or 1)?"; cin >> ij;

    } while (ij > 0);



}
