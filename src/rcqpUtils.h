/* ===========================================================================
 * File: "rcqpUtils.h"
 *                        Created: 2012-01-13 18:49:02
 *              Last modification: 2016-06-10 14:27:17
 * Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
 *          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
 * Copyright (c) 2011-2016 
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

void rcqp_print_R_message(char* inMsg);


#endif  /* RCQP_UTILS_H */
