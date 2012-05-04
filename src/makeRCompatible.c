
#include "rcqp.h"
#include "makeRCompatible.h"


void rcqp_receive_error(int x)
{
/*	error("cqp error #%d\n", cderrno); */
	Rprintf("Error! Please close and restart R as rcqp may be in unknown state");
	
}

int rcqp_flush() {
  return(1);
}
