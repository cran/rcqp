/* ===========================================================================
 * File: "rcqpUtils.h"
 *                        Created: 2012-01-13 18:49:02
 *              Last modification: 2012-01-19 12:02:03
 * Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
 *          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
 * (c) Copyright: 2011-2012
 * All rights reserved.
 * ===========================================================================
 */


#ifndef	RCQP_UTILS_H
#define RCQP_UTILS_H
#pragma once



/* Prototypes
 * ----------
 */

void R_init_rcqp(DllInfo * info);

void rcqp_error_code(int inCode);

int rcqp_query_has_semicolon(char *query);

int rcqp_get_attr_type(SEXP inType);

FieldType rcqp_get_field_type(SEXP inField);

void rcqp_send_error();

#endif  /* RCQP_UTILS_H */
