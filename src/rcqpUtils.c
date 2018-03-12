/* ===========================================================================
* File: "rcqpUtils.c"
*                        Created: 2012-01-13 18:49:02
*              Last modification: 2016-06-10 15:42:46
* Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
*          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
* Copyright (c) 2011-2016 
* All rights reserved.
* ===========================================================================
*/
	
#include "rcqp.h"
#define CALLDEF(name, n)  {#name, (DL_FUNC) &name, n}

static const R_CallMethodDef CallEntries[] = {
	{"rcqpCmd_alg2cpos", (DL_FUNC) &rcqpCmd_alg2cpos, 2},
	{"rcqpCmd_attribute_size", (DL_FUNC) &rcqpCmd_attribute_size, 1},
	{"rcqpCmd_attributes", (DL_FUNC) &rcqpCmd_attributes, 2},
	{"rcqpCmd_corpus_info", (DL_FUNC) &rcqpCmd_corpus_info, 1},
	{"rcqpCmd_cpos2alg", (DL_FUNC) &rcqpCmd_cpos2alg, 2},
	{"rcqpCmd_cpos2id", (DL_FUNC) &rcqpCmd_cpos2id, 2},
	{"rcqpCmd_cpos2lbound", (DL_FUNC) &rcqpCmd_cpos2lbound, 2},
	{"rcqpCmd_cpos2rbound", (DL_FUNC) &rcqpCmd_cpos2rbound, 2},
	{"rcqpCmd_cpos2str", (DL_FUNC) &rcqpCmd_cpos2str, 2},
	{"rcqpCmd_cpos2struc", (DL_FUNC) &rcqpCmd_cpos2struc, 2},
	{"rcqpCmd_drop_subcorpus", (DL_FUNC) &rcqpCmd_drop_subcorpus, 1},
	{"rcqpCmd_dump_subcorpus", (DL_FUNC) &rcqpCmd_dump_subcorpus, 3},
	{"rcqpCmd_fdist1", (DL_FUNC) &rcqpCmd_fdist1, 5},
	{"rcqpCmd_fdist2", (DL_FUNC) &rcqpCmd_fdist2, 6},
	{"rcqpCmd_full_name", (DL_FUNC) &rcqpCmd_full_name, 1},
	{"rcqpCmd_getRegistry", (DL_FUNC) &rcqpCmd_getRegistry, 0},
	{"rcqpCmd_id2cpos", (DL_FUNC) &rcqpCmd_id2cpos, 2},
	{"rcqpCmd_id2freq", (DL_FUNC) &rcqpCmd_id2freq, 2},
	{"rcqpCmd_id2str", (DL_FUNC) &rcqpCmd_id2str, 2},
	{"rcqpCmd_lexicon_size", (DL_FUNC) &rcqpCmd_lexicon_size, 1},
	{"rcqpCmd_list_corpora", (DL_FUNC) &rcqpCmd_list_corpora, 0},
	{"rcqpCmd_list_subcorpora", (DL_FUNC) &rcqpCmd_list_subcorpora, 1},
	{"rcqpCmd_query", (DL_FUNC) &rcqpCmd_query, 3},
	{"rcqpCmd_regex2id", (DL_FUNC) &rcqpCmd_regex2id, 2},
	{"rcqpCmd_setRegistry", (DL_FUNC) &rcqpCmd_setRegistry, 1},
	{"rcqpCmd_str2id", (DL_FUNC) &rcqpCmd_str2id, 2},
	{"rcqpCmd_struc2cpos", (DL_FUNC) &rcqpCmd_struc2cpos, 2},
	{"rcqpCmd_struc2str", (DL_FUNC) &rcqpCmd_struc2str, 2},
	{"rcqpCmd_structural_attribute_has_values", (DL_FUNC) &rcqpCmd_structural_attribute_has_values, 1},
	{"rcqpCmd_subcorpus_size", (DL_FUNC) &rcqpCmd_subcorpus_size, 1},
    {NULL, NULL, 0}
};

/* Needed for cross-compilation (mingw) */
int yydebug = 0;

/* 
 * ------------------------------------------------------------------------
 * 
 * "R_init_rcqp()" --
 * 
 * This function is automatically called by R when the package is loaded.
 * 
 * ------------------------------------------------------------------------
 */
void
R_init_rcqp(DllInfo * info)
{
	char *	stdregdir = cl_standard_registry();	
    R_registerRoutines(info, NULL, CallEntries, NULL, NULL);
    R_useDynamicSymbols(info, FALSE);
    R_forceSymbols(info, TRUE);
   
    if (stdregdir == NULL) {
		rcqp_print_R_message("The registry directory is not defined.");
		rcqp_print_R_message("See ?cqi_setRegistry for more info on how to set the registry.");
	} else {
		rcqp_start_cwb();
	}
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqp_print_R_message()" --
 * 
 * This function invokes the R proc message() from the C code.
 * 
 * ------------------------------------------------------------------------
 */
void
rcqp_print_R_message(char* inMsg)
{
	SEXP	expr;	
	PROTECT(expr = lang2(install("message"), mkString(inMsg)));
	eval(expr, R_GlobalEnv);
	UNPROTECT(1);
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqp_error_code()" --
 * 
 * CQI_ERROR_GENERAL_ERROR          	0x0201	513
 * CQI_ERROR_CONNECT_REFUSED        	0x0202	514
 * CQI_ERROR_USER_ABORT             	0x0203	515
 * CQI_ERROR_SYNTAX_ERROR           	0x0204	516
 * CQI_CL_ERROR_NO_SUCH_ATTRIBUTE   	0x0401	1025
 * CQI_CL_ERROR_WRONG_ATTRIBUTE_TYPE	0x0402	1026
 * CQI_CL_ERROR_OUT_OF_RANGE        	0x0403	1027
 * CQI_CL_ERROR_REGEX               	0x0404	1028
 * CQI_CL_ERROR_CORPUS_ACCESS       	0x0405	1029
 * CQI_CL_ERROR_OUT_OF_MEMORY       	0x0406	1030
 * CQI_CL_ERROR_INTERNAL            	0x0407	1031
 * CQI_CQP_ERROR_GENERAL            	0x0501	1281
 * CQI_CQP_ERROR_NO_SUCH_CORPUS     	0x0502	1282
 * CQI_CQP_ERROR_INVALID_FIELD      	0x0503	1283
 * CQI_CQP_ERROR_OUT_OF_RANGE       	0x0504	1284
 * 
 * ------------------------------------------------------------------------
 */
void rcqp_error_code(int inCode)
{
	if (inCode != 0) {
		switch (inCode) {
			case 516:
			error("Syntax error\n");
			break;
			
			case 1025:
			error("Error: no such attribute\n");
			break;
			
			case 1026:
			error("Error: wrong attribute type\n");
			break;
			
			case 1028:
			error("Regex error\n");
			break;
			
			case 1029:
			error("Error corpus access\n");
			break;
			
			case 1030:
			error("Error: out of memory\n");
			break;
			
			case 1031:
			error("Internal error\n");
			break;
			
			case 1282:
			error("Error: no such corpus\n");
			break;
			
			case 1283:
			error("Error: invalid field\n");
			break;
			
			case 1027:
			case 1284:
			error("Error: out of range\n");
			break;
			
			default:
			error("cqp returned error code #%d\n", inCode);
			break;
			
		}
	} 
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqp_query_has_semicolon()" --
 * 
 * Copied from query_has_semicolon in cqpserver.c.
 * CQP queries must be terminated with a single semicolon;
 * multiple semicolons will produce an error to occur -- so we
 * have to check and add a semicolon if necessary.
 * 
 * ------------------------------------------------------------------------
 */
int
rcqp_query_has_semicolon(char *query)
{
  char *p;

  if (query == NULL || *query == 0)
    return 0;
  p = query + strlen(query); 
  while (--p > query)           /* stop at first non-blank char or at first string character */
    if (!(*p == ' ' || *p == '\t')) break;
  return (*p == ';') ? 1 : 0;
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqp_get_attr_type()" --
 * 
 * 
 * ------------------------------------------------------------------------
 */
int
rcqp_get_attr_type(SEXP inType)
{
	char *		type;
	
	if (!isString(inType) || length(inType) != 1) error("type must be a string");
	type = (char*)CHAR(STRING_ELT(inType,0));
	if (!strcmp("a",type)) {
		return ATT_ALIGN;
	} else if (!strcmp("p",type)) {
		return ATT_POS;
	} else if (!strcmp("s",type)) {
		return ATT_STRUC;
	} else {
		error("invalid attribute type. Must be 'a', 'p', or 's'.");
	} 
	return 0;
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqp_get_field_type()" --
 * 
 * 
 * ------------------------------------------------------------------------
 */
FieldType
rcqp_get_field_type(SEXP inField)
{
	char *		field;
	
	if (!isString(inField) || length(inField) != 1) error("type must be a string");
	field = (char*)CHAR(STRING_ELT(inField,0));
	if (!strcmp("match",field)) {
		return MatchField;
	} else if (!strcmp("matchend",field)) {
		return MatchEndField;
	} else if (!strcmp("target",field)) {
		return TargetField;
	} else if (!strcmp("keyword",field)) {
		return KeywordField;
	} else {
	    return NoField;
	} 
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqp_send_error()" --
 * 
 * ------------------------------------------------------------------------
 */
void rcqp_send_error()
{
/*	error("cqp error #%d\n", cderrno); */
	Rprintf("Error! Please close and restart R as rcqp may be in unknown state");
	
}


