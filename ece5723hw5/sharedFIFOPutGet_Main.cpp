#include "sharedFIFOPutGet_TB.h"
int sc_main (int argc , char *argv[]) {
   sharedFIFOPutGet_TB MultiWay("sharedFIFOPutGet1");
   sc_start();
   return 0;
}

