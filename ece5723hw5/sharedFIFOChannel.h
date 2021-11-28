#include "interfaceClasses.h"

template <class T, int numOfInitiators, int numOfTargets, int Max>
class sharedFIFO : public put_if<T>, public get_if<T>
{
	int goingTo, size, elems[numOfTargets], head[numOfTargets], target;
	T dataPlaced;
	T queueContents[numOfTargets][Max];
	sc_event dataAvailable[numOfTargets];
	sc_event dataReceived[numOfTargets];
	sc_event get_event, put_event;
	//sc_mutex busBusy;

	public:
		sharedFIFO() : goingTo(-1), size(Max){};
		~sharedFIFO() {};
		void put(int initiator, int target, T data){
			//busBusy.lock(); 
			if (elems[target] == size) wait(dataReceived[target]);
			queueContents[target][(head[target] + elems[target]) % size] = data;
			elems[target] = elems[target] + 1;
			for (int k = 0; k < Max; k++) {
				cout << "queueContents[" << target << "][" << k << "]: " << queueContents[target][k] << endl;
			}
			goingTo = target;
			dataAvailable[target].notify();
			wait(dataReceived[target]);
			//busBusy.unlock();
		}
		void get(int &initiator, int target, T &data){
			if (goingTo != target ) wait(dataAvailable[target]); // check if the target is correct and if its full
			data = queueContents[target][head[target]];
			elems[target] = elems[target] - 1;
			goingTo = -1; // prevent multiple gets of same data
			head[target] = (head[target] + 1) % size;
			dataReceived[target].notify();
		}
};
