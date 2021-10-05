#include "averager.h"

averager::averager(bus& start_input, bus& END, bus& D, bus& C, bus& R, bus& Q) :

	start1(&start_input), end1(&END), D1(&D), C1(&C), R1(&R), Q1(&Q)

{}
	void averager::evl() {
		int gotNone = 0;
		int got0 = 1;
		int got01 = 2;
		int got010 = 3;
		string currAvgSTRING = "00000000";
		//present_stateS = next_stateS;
		if (R1->v == "1") {
			/*Q->fill('0'); */
			avgBus.v = currAvgSTRING;
		}
		else {

			//if (start_input[0]-> == "0" && start_input[1].v == "1" && start_input[2].v == "0") {
			//	stateOn = 1;
			//}

			if (start1->v == "010") {
				stateOn = 1;
				Q1->v = "X";
				/*end1->v = "000";*/
			}
			if (end1->v == "010") {
				stateOn = 0;
				Q1->v = avgBus.v;
				/*start1->v = "000";*/
			}

			//if (end_input[0].v == "0" && end_input[1].v == "0" && end_input[2].v == "0") {
			//	stateOn = 1;
			//}

			if (stateOn == 1) {
				avgBus = avgBus / D1;

				
			}

		}
	}
			//present_stateS = next_stateS;
			//if (start_input->v == "0" && present_stateS == gotNone) {
			//	next_stateS = got0;
			//}
			//else if (start_input->v == "1" && present_stateS == gotNone) {
			//	next_stateS = gotNone;
			//}

			//if (start_input->v == "0" && present_stateS == got0) {
			//	next_stateS = got0;
			//}
			//else if (start_input->v == "1" && present_stateS == got0) {
			//	next_stateS = got01;
			//}

			//if (start_input->v == "0" && present_stateS == got01) {
			//	next_stateS = got010;
			//}
			//else if (start_input->v == "1" && present_stateS == got01) {
			//	next_stateS = got01;
			//}

			//if (start_input->v == "0" && present_stateS == got010) {
			//	next_stateS = got0;
			//}
			//else if (start_input->v == "1" && present_stateS == got010) {
			//	next_stateS = got01;
			//}



			// finding end pulse

			//present_stateE = next_stateE;
			//if (end_input->v == "0" && present_stateE == gotNone) {
			//	next_stateE = got0;
			//}
			//else if (end_input->v == "1" && present_stateE == gotNone) {
			//	next_stateE = gotNone;
			//}

			//if (end_input->v == "0" && present_stateE == got0) {
			//	next_stateE = got0;
			//}
			//else if (end_input->v == "1" && present_stateE == got0) {
			//	next_stateE = got01;
			//}

			//if (end_input->v == "0" && present_stateE == got01) {
			//	next_stateE = got010;
			//}
			//else if (end_input->v == "1" && present_stateE == got01) {
			//	next_stateE = got01;
			//}

			//if (end_input->v == "0" && present_stateE == got010) {
			//	next_stateE = got0;
			//}
			//else if (end_input->v == "1" && present_stateE == got010) {
			//	next_stateE = got01;
			//}

			//// start or end the averaging

			//if (present_stateS == got010) {
			//	stateOn = 1;
			//}

			//if (present_stateE == got010) {
			//	stateOn = 0;
			//}

