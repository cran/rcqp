/* ===========================================================================
 * File: "makeRCompatible.h"
 *                        Created: 2012-01-13 18:49:02
 *              Last modification: 2012-01-19 12:02:10
 * Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
 *          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
 * (c) Copyright: 2011-2012
 * All rights reserved.
 * ===========================================================================
 */

#ifndef	RCQP_MAKE_R_COMPATIBLE_H
#define RCQP_MAKE_R_COMPATIBLE_H

#include "R_ext/Print.h"

/* #include <stdio.h> */

void rcqp_send_error();
void rcqp_receive_error(int x);
int rcqp_flush();

/*
#define exit(x) rcqp_receive_error(x)
#define fprintf(x,...) Rprintf(__VA_ARGS__)
#define vfprintf(x,y,z) Rvprintf(y,z)

#define fflush(stdout) rcqp_flush() 
#define fflush(stderr) rcqp_flush() 

#define printf Rprintf

#define putchar(x) Rprintf("%d", x)
#define fputc(x, y) Rprintf("%d", x)

#define puts Rprintf

#define stdout NULL
*/

#endif  /* RCQP_MAKE_R_COMPATIBLE_H */
