/* ===========================================================================
* File: "rcqpCommands.c"
*                        Created: 2012-01-13 18:49:02
*              Last modification: 2016-06-10 15:12:43
* Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
*          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
* Copyright (c) 2011-2016 
* All rights reserved.
* ===========================================================================
*/
	
#include "rcqp.h"

static Rboolean sPathInitialized = FALSE;

#define RCQP_ATT_HASH_SIZE 16384

#define RCQ_CHECK_INITIALIZED 	if (!sPathInitialized) { \
		error("the path registry has not been initialized.\nSee ?cqi_setRegistry for more info on how to set the registry."); \
	} 


/* 
 * ------------------------------------------------------------------------
 * 
 * "void rcqp_start_cwb()" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
void rcqp_start_cwb()
{
	int			ac = 1;
	char *		av[1];

	if (sPathInitialized == TRUE) {
		error("the cwb library has already been initialized");
	} 
	sPathInitialized = TRUE;
	av[0] = "rcqp";
	which_app = cqp;
	silent = 1; 
	paging = 0;
	autoshow = 0;
	auto_save = 0;
	server_log = 0;
	enable_macros = 0;

	initialize_cqp(ac, av);
	make_attribute_hash(RCQP_ATT_HASH_SIZE);
}


/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_getRegistry()" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_getRegistry()
{
	SEXP		result = R_NilValue;
	char *		regStr;
	
	regStr = cl_standard_registry();
	if (regStr != NULL) {
		result = PROTECT(allocVector(STRSXP, 1));
		SET_STRING_ELT(result, 0, mkChar(regStr));
		UNPROTECT(1);
	} 
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_setRegistry(SEXP inPath)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_setRegistry(SEXP inPath)
{
	SEXP		result = R_NilValue;
	char *		regStr;
	
	if (sPathInitialized == TRUE) {
		error("the path registry has already been initialized");
	} 
	regStr = (char*)CHAR(STRING_ELT(inPath,0));
	if( access(regStr, F_OK) != -1 ) {
		// Path exists
		setenv("CORPUS_REGISTRY",regStr,1);		
		rcqp_start_cwb();
	} else {
		error("%s: no such file", regStr);
	}
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_list_corpora()" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_list_corpora()
{
	SEXP			result = R_NilValue;
	CorpusList *	cl;
	int				i = 0, n = 0;
	
	RCQ_CHECK_INITIALIZED
	
	/* First count corpora */
	for (cl = FirstCorpusFromList(); cl != NULL; cl = NextCorpusFromList(cl)) {
		if (cl->type == SYSTEM) n++;
	}

	result = PROTECT(allocVector(STRSXP, n));

	/* Then build list of names */
	for (cl = FirstCorpusFromList(); cl != NULL; cl = NextCorpusFromList(cl)) {
		if (cl->type == SYSTEM) {
			SET_STRING_ELT(result, i, mkChar(cl->name));
			i++;
		}
	}
	
	UNPROTECT(1);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_full_name(SEXP inCorpus)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_full_name(SEXP inCorpus)
{
	SEXP			result = R_NilValue;
	char *			c;
	CorpusList *	cl;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inCorpus) || length(inCorpus) != 1) error("invalid corpus name");
	PROTECT(inCorpus);

	c = (char*)CHAR(STRING_ELT(inCorpus,0));
	cl = findcorpus(c, SYSTEM, 0);

	if (cl == NULL || !access_corpus(cl)) {
		UNPROTECT(1);
		return R_NilValue;
	} else {
		result = PROTECT(allocVector(STRSXP, 1));
		SET_STRING_ELT(result, 0, mkChar(cl->corpus->name));
	}
	
	UNPROTECT(2);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_charset(SEXP inCorpus)" --
 * 
 * This is a dummy function until the registry extensions are implemented
 * in CWB.
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_charset(SEXP inCorpus)
{
	SEXP			result = R_NilValue;
	
	error("feature not yet implemented in CQP");

	RCQ_CHECK_INITIALIZED

	if (!isString(inCorpus) || length(inCorpus) != 1) error("invalid corpus name");

	result = PROTECT(allocVector(STRSXP, 1));
	SET_STRING_ELT(result, 0, mkChar("latin1"));

	UNPROTECT(1);
		
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_properties(SEXP inCorpus)" --
 * 
 * The CQI_CORPUS_PROPERTIES switch is not yet implemented in cqpserver.
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_properties(SEXP inCorpus)
{
	error("feature not yet implemented in CQP");

	RCQ_CHECK_INITIALIZED

	return R_NilValue;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_attributes(SEXP inCorpus, SEXP inType)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_attributes(SEXP inCorpus, SEXP inType)
{
	SEXP			result = R_NilValue;
	char 			*c;
	CorpusList		*cl;
	Attribute *		a;
	int				i = 0, n = 0, type;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inCorpus) || length(inCorpus) != 1) error("invalid corpus name");
	PROTECT(inCorpus);

	c = (char*)CHAR(STRING_ELT(inCorpus,0));
	type = rcqp_get_attr_type(inType);
	
	cl = findcorpus(c, SYSTEM, 0);
	if (cl == NULL || !access_corpus(cl)) {
		UNPROTECT(1);
		rcqp_error_code(CQI_CQP_ERROR_NO_SUCH_CORPUS);
	} else {
		/* First count attributes */
		for (a = first_corpus_attribute(cl->corpus); a != NULL; a = next_corpus_attribute()) {
			if (a->type == type) n++;
		}
		
		result = PROTECT(allocVector(STRSXP, n));
		
		/* Then build list of names */
		for (a = first_corpus_attribute(cl->corpus); a != NULL; a = next_corpus_attribute()) {
			if (a->type == type) {
				SET_STRING_ELT(result, i, mkChar(a->any.name));
				i++;
			}
		}
	}

	UNPROTECT(2);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_attribute_size(SEXP inAttribute)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_attribute_size(SEXP inAttribute)
{
	SEXP			result = R_NilValue;
	char *			a;
	Attribute *		attribute;
	int				size;
	int				found = 0;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);

	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	
	/* Need to try all possible attribute types */
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute != NULL) {
		size = cl_max_cpos(attribute);
		if (size < 0) {
			UNPROTECT(1);
			rcqp_send_error();
		} else {
			found = 1;
		}
	} else {
		attribute = cqi_lookup_attribute(a, ATT_STRUC);
		if (attribute != NULL) {
			size = cl_max_struc(attribute);
			if (size < 0) {
				size = 0;
			} else {
				found = 1;
			}
		} else {
			attribute = cqi_lookup_attribute(a, ATT_ALIGN);
			if (attribute != NULL) {
				size = cl_max_alg(attribute);
				if (size < 0) {
					UNPROTECT(1);
					rcqp_send_error();
				} else {
					found = 1;
				}
			} else {
				UNPROTECT(1);
				rcqp_error_code(cqi_errno);
			}
		}
	}

	if (found) {
		result = PROTECT(allocVector(INTSXP, 1));
		INTEGER(result)[0] = size;
	} 
	
	UNPROTECT(2);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_structural_attribute_has_values(SEXP inAttribute)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_structural_attribute_has_values(SEXP inAttribute)
{
	SEXP			result = R_NilValue;
	char *			a;
	Attribute *		attribute;
	
	
	RCQ_CHECK_INITIALIZED

	/* rcqp_initialize(); */
	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);

	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	
	attribute = cqi_lookup_attribute(a, ATT_STRUC);
	if (attribute != NULL) {
		result = PROTECT(allocVector(LGLSXP, 1));
		LOGICAL(result)[0] = (cl_struc_values(attribute) != 0);
	} else {
		rcqp_error_code(cqi_errno);
	}

	UNPROTECT(2);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_corpus_info(SEXP inCorpus)" --
 * 
 * The CQI_CORPUS_INFO switch is not yet implemented in cqpserver.
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_corpus_info(SEXP inCorpus)
{
	SEXP			result = R_NilValue;
	char *			c;
	CorpusList *	cl;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inCorpus) || length(inCorpus) != 1) error("invalid corpus name");
	PROTECT(inCorpus);

	c = (char*)CHAR(STRING_ELT(inCorpus,0));
	cl = findcorpus(c, SYSTEM, 0);

	if (cl == NULL || !access_corpus(cl)) {
		rcqp_error_code(CQI_CQP_ERROR_NO_SUCH_CORPUS);
	} else {
		describe_corpus(cl->corpus);
	}
	
	UNPROTECT(1);
		
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_lexicon_size(SEXP inAttribute)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_lexicon_size(SEXP inAttribute)
{
	SEXP			result = R_NilValue;
	char *			a;
	Attribute *		attribute;
	int 			size;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);

	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	attribute = cqi_lookup_attribute(a, ATT_POS);

	if (attribute != NULL) {
		size = cl_max_id(attribute);
		if (size < 0) {
			UNPROTECT(1);
			Rprintf("negative size");
			rcqp_send_error();
		} else {
			result = PROTECT(allocVector(INTSXP, 1));
			INTEGER(result)[0] = size;
		}
	} else {
		UNPROTECT(1);
		return R_NilValue;
	}
	
	UNPROTECT(2);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_str2id(SEXP inAttribute, SEXP inStrs)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_str2id(SEXP inAttribute, SEXP inStrs)
{
	SEXP			result = R_NilValue;
	int				idx;
	int				len, i;
	char 			*a, *str;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isString(inStrs)) error("argument 'strs' must be a vector of strings");
	PROTECT(inStrs);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inStrs);
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {			
			str = (char*)CHAR(STRING_ELT(inStrs,i));
			idx = cl_str2id(attribute, str);
			if (idx < 0) {
				idx = -1;
			} 
			INTEGER(result)[i] = idx;
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_id2str(SEXP inAttribute, SEXP inIds)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_id2str(SEXP inAttribute, SEXP inIds)
{
	SEXP			result = R_NilValue;
	int				idx;
	int				len, i;
	char 			*a, *str;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inIds)) error("argument 'ids' must be a vector of integers");
	PROTECT(inIds);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inIds);
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(STRSXP, len));	
		
		for (i=0; i<len; i++) {
			idx = INTEGER(inIds)[i];	
			str = cl_id2str(attribute, idx);
            /* Sends "" if str == NULL (cpos out of range) */
			if (str != NULL) {
				SET_STRING_ELT(result, i, mkChar(str));
			} 
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_id2freq(SEXP inAttribute, SEXP inIds)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_id2freq(SEXP inAttribute, SEXP inIds)
{
	SEXP			result = R_NilValue;
	int				idx;
	int				len, i, f;
	char 			*a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inIds)) error("argument 'ids' must be a vector of integers");
	PROTECT(inIds);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inIds);
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {
			idx = INTEGER(inIds)[i];	
			f = cl_id2freq(attribute, idx);
			/* Return 0 if ID is out of range */
			if (f < 0) f = 0;
			INTEGER(result)[i] = f;
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_id2cpos(SEXP inAttribute, SEXP inId)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_id2cpos(SEXP inAttribute, SEXP inId)
{
	SEXP			result = R_NilValue;
	int				idx;
	int				len, i;
	int *			cposlist;
	char 			*a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inId) || length(inId) != 1) error("argument 'id' must be an integer");
	PROTECT(inId);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	idx = INTEGER(inId)[0];
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		cposlist = cl_id2cpos(attribute, idx, &len);
		result = PROTECT(allocVector(INTSXP, len));	
		
		if (cposlist == NULL) {
			UNPROTECT(2);
			rcqp_error_code(cqi_errno);
		} else {
			for (i=0; i<len; i++) {
				INTEGER(result)[i] = cposlist[i];
			}
			free(cposlist);
		} 
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cpos2id(SEXP inAttribute, SEXP inCpos)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_cpos2id(SEXP inAttribute, SEXP inCpos)
{
	SEXP			result = R_NilValue;
	int				cpos;
	int				len, i, id;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inCpos)) error("argument 'cpos' must be a vector of integers");
	PROTECT(inCpos);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inCpos);
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {
			cpos = INTEGER(inCpos)[i];	
			id = cl_cpos2id(attribute, cpos);
            /* Return -1 if cpos is out of range */
			if (id < 0) id = -1;
			INTEGER(result)[i] = id;
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cpos2str(SEXP inAttribute, SEXP inCpos)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_cpos2str(SEXP inAttribute, SEXP inCpos)
{
	SEXP			result = R_NilValue;
	int				cpos;
	int				len, i;
	char 			*a, *str;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inCpos)) error("argument 'cpos' must be a vector of integers");
	PROTECT(inCpos);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inCpos);
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(STRSXP, len));	
		
		for (i=0; i<len; i++) {
			cpos = INTEGER(inCpos)[i];	
			str = cl_cpos2str(attribute, cpos);
            /* Sends "" if str == NULL (cpos out of range) */
			if (str != NULL) {
				SET_STRING_ELT(result, i, mkChar(str));
			} 
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cpos2struc(SEXP inAttribute, SEXP inIds)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_cpos2struc(SEXP inAttribute, SEXP inCpos)
{
	SEXP			result = R_NilValue;
	int				cpos;
	int				len, i, struc;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inCpos)) error("argument 'cpos' must be a vector of integers");
	PROTECT(inCpos);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inCpos);
	
	attribute = cqi_lookup_attribute(a, ATT_STRUC);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {
			cpos = INTEGER(inCpos)[i];	
			struc = cl_cpos2struc(attribute, cpos);
            /* Return -1 if cpos is out of range */
			if (struc < 0) struc = -1;
			INTEGER(result)[i] = struc;
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cpos2lbound(SEXP inAttribute, SEXP inCpos)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_cpos2lbound(SEXP inAttribute, SEXP inCpos)
{
	SEXP			result = R_NilValue;
	int				cpos;
	int				len, i, struc, lb, rb;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inCpos)) error("argument 'cpos' must be a vector of integers");
	PROTECT(inCpos);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inCpos);
	
	attribute = cqi_lookup_attribute(a, ATT_STRUC);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {
			cpos = INTEGER(inCpos)[i];	
			struc = cl_cpos2struc(attribute, cpos);
			/* Return -1 if cpos is out of range */
			if (struc < 0) {
				struc = -1;
			} else {
				if (cl_struc2cpos(attribute, struc, &lb, &rb)) {
					struc = lb;
				} else {
					struc = -1;
				}
			}
			INTEGER(result)[i] = struc;
		}
	}
	
	UNPROTECT(3);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cpos2rbound(SEXP inAttribute, SEXP inCpos)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_cpos2rbound(SEXP inAttribute, SEXP inCpos)
{
	SEXP			result = R_NilValue;
	int				cpos;
	int				len, i, struc, lb, rb;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inCpos)) error("argument 'cpos' must be a vector of integers");
	PROTECT(inCpos);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inCpos);
	
	attribute = cqi_lookup_attribute(a, ATT_STRUC);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {
			cpos = INTEGER(inCpos)[i];	
			struc = cl_cpos2struc(attribute, cpos);
			/* Return -1 if cpos is out of range */
			if (struc < 0) {
				struc = -1;
			} else {
				if (cl_struc2cpos(attribute, struc, &lb, &rb)) {
					struc = rb;
				} else {
					struc = -1;
				}
			}
			INTEGER(result)[i] = struc;
		}
	}
	
	UNPROTECT(3);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_alg2cpos(SEXP inAttribute, SEXP inAlg)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_alg2cpos(SEXP inAttribute, SEXP inAlg)
{
	SEXP			result = R_NilValue;
	int				alg, s1, s2, t1, t2;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	if (!isVector(inAlg) || length(inAlg) != 1) error("argument 'alg' must be an integer");
	PROTECT(inAttribute);
	PROTECT(inAlg);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));

	alg = asInteger(inAlg);
	if (alg == NA_INTEGER) {
		UNPROTECT(2);
	    error("invalid 'alg' value (too large or NA)");
	}

	attribute = cqi_lookup_attribute(a, ATT_ALIGN);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		if (cl_alg2cpos(attribute, alg, &s1, &s2, &t1, &t2)) {
			result = PROTECT(allocVector(INTSXP, 4));	
			INTEGER(result)[0] = s1;
			INTEGER(result)[1] = s2;
			INTEGER(result)[2] = t1;
			INTEGER(result)[3] = t2;
		} else {
			rcqp_send_error();
		} 
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cpos2alg(SEXP inAttribute, SEXP inCpos)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_cpos2alg(SEXP inAttribute, SEXP inCpos)
{
	SEXP			result = R_NilValue;
	int				cpos;
	int				len, i, alg;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inCpos)) error("argument 'cpos' must be a vector of integers");
	PROTECT(inCpos);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inCpos);
	
	attribute = cqi_lookup_attribute(a, ATT_ALIGN);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, len));	
		
		for (i=0; i<len; i++) {
			cpos = INTEGER(inCpos)[i];	
			alg = cl_cpos2alg(attribute, cpos);
            /* Return -1 if cpos is out of range */
			if (alg < 0) alg = -1;
			INTEGER(result)[i] = alg;
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_struc2cpos(SEXP inAttribute, SEXP inStruc)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_struc2cpos(SEXP inAttribute, SEXP inStruc)
{
	SEXP			result = R_NilValue;
	int				struc, start, end;
	char *			a;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inStruc) || length(inStruc) != 1) error("argument 'struc' must be an integer");
	PROTECT(inStruc);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	struc = INTEGER(inStruc)[0];
	
	attribute = cqi_lookup_attribute(a, ATT_STRUC);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		if (cl_struc2cpos(attribute, struc, &start, &end)) {
			result = PROTECT(allocVector(INTSXP, 2));	
			INTEGER(result)[0] = start;
			INTEGER(result)[1] = end;
		} else {
			UNPROTECT(2);
			rcqp_send_error(cqi_errno);
		} 
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_struc2str(SEXP inAttribute, SEXP inIds)" --
 * 
 * Function gets value of struc_num'th instance of the specified s-attribute.
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_struc2str(SEXP inAttribute, SEXP inIds)
{
	SEXP			result = R_NilValue;
	int				idx;
	int				len, i;
	char 			*a, *str;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isVector(inIds)) error("argument 'ids' must be a vector of integers");
	PROTECT(inIds);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	len = length(inIds);
	
	attribute = cqi_lookup_attribute(a, ATT_STRUC);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(STRSXP, len));	
		
		for (i=0; i<len; i++) {
			idx = INTEGER(inIds)[i];	
			str = cl_struc2str(attribute, idx);
            /* Sends "" if str == NULL (cpos out of range) */
			if (str != NULL) {
				SET_STRING_ELT(result, i, mkChar(str));
			} 
		}
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_idlist2cpos(SEXP inAttribute, SEXP inIds)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_idlist2cpos(SEXP inAttribute, SEXP inIds)
{
	SEXP			result = R_NilValue;
	
	error("feature not yet implemented in CQP");

	RCQ_CHECK_INITIALIZED

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_regex2id(SEXP inAttribute, SEXP inRegex)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_regex2id(SEXP inAttribute, SEXP inRegex)
{
	SEXP			result = R_NilValue;
	int *			idlist;
	int				len, i;
	char 			*a, *r;
	Attribute *		attribute;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inAttribute) || length(inAttribute) != 1) error("argument 'attribute' must be a string");
	PROTECT(inAttribute);
	if (!isString(inRegex) || length(inRegex) != 1) error("argument 'regexp' must be a string");
	PROTECT(inRegex);
	
	a = (char*)CHAR(STRING_ELT(inAttribute,0));
	r = (char*)CHAR(STRING_ELT(inRegex,0));
	
	attribute = cqi_lookup_attribute(a, ATT_POS);
	if (attribute == NULL) {
		UNPROTECT(2);
		rcqp_error_code(cqi_errno);
	} else {
		idlist = cl_regex2id(attribute, r, 0, &len);
		if (idlist == NULL) {
			if (cderrno != CDA_OK) {
				UNPROTECT(2);
				rcqp_send_error();
			} else {
				result = PROTECT(allocVector(INTSXP, 0));	
			} 
		} else {
			result = PROTECT(allocVector(INTSXP, len));	
			
			for (i=0; i<len; i++) {
				INTEGER(result)[i] = idlist[i];
			}
			free(idlist);
		} 
	}
	
	UNPROTECT(3);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_cqp(SEXP inQuery)" --
 * 
 *  
 * 
 * ------------------------------------------------------------------------
SEXP rcqpCmd_cqp(SEXP inQuery)
{
	SEXP			result = R_NilValue;
	char			*query;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inQuery) || length(inQuery) != 1) error("invalid query name");
	
	PROTECT(inQuery);

	query = (char*)CHAR(STRING_ELT(inQuery,0));	

	
	query_lock = 0;
		
	if (!cqp_parse_string(query)) {
		rcqp_error_code(CQI_CQP_ERROR_GENERAL);
	} 

	query_lock = 0;

	UNPROTECT(1);

	return result;
}
*/



/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_query(SEXP inMother, SEXP inChild, SEXP inQuery)" --
 * 
 *  
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_query(SEXP inMother, SEXP inChild, SEXP inQuery)
{
	SEXP			result = R_NilValue;
	char			*child, *mother, *query, *c, *sc;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inMother) || length(inMother) != 1) error("invalid corpus name");
	if (!isString(inChild) || length(inChild) != 1) error("invalid subcorpus name");
	if (!isString(inQuery) || length(inQuery) != 1) error("invalid query name");
	
	PROTECT(inMother);
	PROTECT(inChild);
	PROTECT(inQuery);

	mother = (char*)CHAR(STRING_ELT(inMother,0));
	child = (char*)CHAR(STRING_ELT(inChild,0));
	query = (char*)CHAR(STRING_ELT(inQuery,0));
	
	if (!split_subcorpus_spec(mother, &c, &sc)) {
		rcqp_error_code(cqi_errno);
	} else {
		char *cqp_query;
		int len = strlen(child) + strlen(query) + 10;
		
		cqp_query = (char *) cl_malloc(len);
		if (!check_subcorpus_name(child) || !cqi_activate_corpus(mother)) {
			rcqp_error_code(cqi_errno);
		} else {
			query_lock = floor(1e9 * cl_runif()) + 1; /* activate query lock mode with random key */
			
			if (rcqp_query_has_semicolon(query)) {
				sprintf(cqp_query, "%s = %s", child, query);
			} else {
				sprintf(cqp_query, "%s = %s;", child, query);
			}
			
			if (!cqp_parse_string(cqp_query)) {
				rcqp_error_code(CQI_CQP_ERROR_GENERAL); /* should be changed to detailed error messages */
			} else {
				char *			full_child;
				CorpusList *	childcl;
				
				full_child = combine_subcorpus_spec(c, child); /* c is the 'physical' part of the mother corpus */
				childcl = cqi_find_corpus(full_child);
				if ((childcl) == NULL) {
					rcqp_error_code(CQI_CQP_ERROR_GENERAL);
				} 
				free(full_child);
			}			
			query_lock = 0;           /* deactivate query lock mode */
		}
		free(cqp_query);
	}
	free(c);
	free(sc);
	
	UNPROTECT(3);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_list_subcorpora(SEXP inCorpus)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_list_subcorpora(SEXP inCorpus)
{
	SEXP			result = R_NilValue;
	char *			corpus;
	CorpusList		*cl, *mother;
	int				i = 0, n = 0;
	
	RCQ_CHECK_INITIALIZED

	PROTECT(inCorpus);

	corpus = (char*)CHAR(STRING_ELT(inCorpus,0));

	mother = cqi_find_corpus(corpus);
	if (!check_corpus_name(corpus) || mother == NULL) {
		UNPROTECT(1);
		rcqp_error_code(cqi_errno);
	} else {
		/* First count subcorpora */
		for (cl = FirstCorpusFromList(); cl != NULL; cl = NextCorpusFromList(cl)) {
			if (cl->type == SUB && cl->corpus == mother->corpus) n++;
		}
		
		result = PROTECT(allocVector(STRSXP, n));

		/* Then build list of names */
		for (cl = FirstCorpusFromList(); cl != NULL; cl = NextCorpusFromList(cl)) {
			if (cl->type == SUB && cl->corpus == mother->corpus) {
				SET_STRING_ELT(result, i, mkChar(cl->name));
				i++;
			}
		}
	}
	
	UNPROTECT(2);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_subcorpus_size(SEXP inSubcorpus)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_subcorpus_size(SEXP inSubcorpus)
{
	SEXP			result = R_NilValue;
	char *			subcorpus;
	CorpusList *	cl;
	
	RCQ_CHECK_INITIALIZED

	PROTECT(inSubcorpus);

	subcorpus = (char*)CHAR(STRING_ELT(inSubcorpus,0));
	cl = cqi_find_corpus(subcorpus);
	
	if (cl == NULL) {
		UNPROTECT(1);
		rcqp_error_code(cqi_errno);
	} else {
		result = PROTECT(allocVector(INTSXP, 1));
		INTEGER(result)[0] = cl->size;
	}

	UNPROTECT(2);

	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_dump_subcorpus(SEXP inSubcorpus, SEXP inField, SEXP inFirst, SEXP inLast)" --
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_dump_subcorpus(SEXP inSubcorpus, SEXP inFirst, SEXP inLast)
{
	SEXP			result = R_NilValue;
	char *			subcorpus;
	CorpusList *	cl;
	int				i, first, last, nrows;
	
	RCQ_CHECK_INITIALIZED

	if (!isString(inSubcorpus) || length(inSubcorpus) != 1) error("invalid subcorpus name");
	
	PROTECT(inSubcorpus);
	PROTECT(inFirst);
	PROTECT(inLast);
	
	first = asInteger(inFirst);
	if (first == NA_INTEGER) {
		UNPROTECT(3);
	    error("invalid 'first' value (too large or NA)");
	}
	last = asInteger(inLast);
	if (last == NA_INTEGER) {
		UNPROTECT(3);
	    error("invalid 'last' value (too large or NA)");
	}
	subcorpus = (char*)CHAR(STRING_ELT(inSubcorpus,0));
	
	cl = cqi_find_corpus(subcorpus);
	if (cl == NULL) {
		UNPROTECT(3);
		rcqp_error_code(cqi_errno);
	}
	
	if ((last < first) || (first < 0) || (last >= cl->size)) {
		error("indices out of range\n");
	}

	nrows = last - first + 1;
	result = PROTECT(allocMatrix(INTSXP, nrows, 4));
	
	for (i = 0; i< nrows; i++) {
		/* 'match' column */
		INTEGER(result)[i] = cl->range[i+first].start;
		
		/* 'matchend' column */
		INTEGER(result)[i+nrows] = cl->range[i+first].end;
		
		/* 'target' column */
		if (cl->targets == NULL) {
			INTEGER(result)[i+2*nrows] = -1;
		} else {
			INTEGER(result)[i+2*nrows] = cl->targets[i+first];
		} 
		
		/* 'keyword' column */
		if (cl->keywords == NULL) {
			INTEGER(result)[i+3*nrows] = -1;
		} else {
			INTEGER(result)[i+3*nrows] = cl->keywords[i+first];
		} 
	}
	
	UNPROTECT(4);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_drop_subcorpus(SEXP inSubcorpus)" --
 * 
 * 
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_drop_subcorpus(SEXP inSubcorpus)
{
	SEXP			result = R_NilValue;
	char *			subcorpus;
	char 			*c, *sc;
	CorpusList *	cl;
	
	RCQ_CHECK_INITIALIZED

	PROTECT(inSubcorpus);
	
	subcorpus = (char*)CHAR(STRING_ELT(inSubcorpus,0));
	
	/* Make sure it is a subcorpus, not a root corpus */
	if (!split_subcorpus_spec(subcorpus, &c, &sc)) {
		UNPROTECT(1);
		rcqp_error_code(cqi_errno);
	} else if (sc == NULL) {
		free(c);
		UNPROTECT(1);
		error("can't drop a root corpus.");
	} else {
		free(c); free(sc);
		cl = cqi_find_corpus(subcorpus);
		if (cl == NULL) {
			UNPROTECT(1);
			rcqp_error_code(cqi_errno);
		} else {
			dropcorpus(cl);
		}
	}
	
	UNPROTECT(1);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_fdist1(SEXP inSubcorpus, SEXP inField1, SEXP inKey1, SEXP inCutoff, SEXP inOffset)" --
 * 
 * NB:
 *     inField1 and inKey1 are the "target" parameters in compute_grouping()
 * -> group Go matchend pos;
 *             <  target  >
 * corresponds to
 * -> cqi_fdist1("DICKENS:Go","matchend","pos")
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_fdist1(SEXP inSubcorpus, SEXP inField1, SEXP inKey1, SEXP inCutoff, SEXP inOffset)
{
	SEXP			result = R_NilValue;
	char 			*subcorpus, *att;
	CorpusList *	cl;
	int				i, cutoff, offset, size;
	Group *			table;
	FieldType		fieldtype = NoField;
	
	RCQ_CHECK_INITIALIZED

	PROTECT(inSubcorpus);
	PROTECT(inField1);
	PROTECT(inKey1);
	PROTECT(inCutoff);
	PROTECT(inOffset);
	
	subcorpus = (char*)CHAR(STRING_ELT(inSubcorpus,0));
	cl = cqi_find_corpus(subcorpus);
	if (cl == NULL) {
		UNPROTECT(5);
		rcqp_error_code(cqi_errno);
	}
	
	cutoff = asInteger(inCutoff);
	if (cutoff == NA_INTEGER) {
		UNPROTECT(5);
	    error("invalid 'cutoff' value (too large or NA)");
	}
	
	offset = asInteger(inOffset);
	if (offset == NA_INTEGER) {
		UNPROTECT(5);
	    error("invalid 'offset' value (too large or NA)");
	}
	
	fieldtype = rcqp_get_field_type(inField1);
	att = (char*)CHAR(STRING_ELT(inKey1,0));
	
    /* compute_grouping() returns tokens with f > cutoff, */
    /* but CQi specifies f >= cutoff */
    cutoff = (cutoff > 0) ? cutoff - 1 : 0;
    table = compute_grouping(cl, NoField, 0, NULL, fieldtype, offset, att, cutoff);
    if (table == NULL) {
      rcqp_error_code(CQI_CQP_ERROR_GENERAL);
    } else {
      size = table->nr_cells;
	  result = PROTECT(allocMatrix(INTSXP, size, 2));

	  for (i=0; i < size; i++) {
		  INTEGER(result)[i] = table->count_cells[i].t;
		  INTEGER(result)[i+size] = table->count_cells[i].freq;
      }
      free_group(&table);
    }

	UNPROTECT(6);
	
	return result;
}

	

/* 
 * ------------------------------------------------------------------------
 * 
 * "rcqpCmd_fdist2(SEXP inSubcorpus, SEXP inField1, SEXP inKey1, SEXP inField2, SEXP inKey2, SEXP inCutoff)" --
 * 
 * NB:
 *     inField1 and inKey1 are the "source" parameters in compute_grouping()
 *     inField2 and inKey2 are the "target" parameters in compute_grouping()
 * -> group NP matchend word by target lemma;
 *             <   target  >    <  source  >
 * corresponds to
 * -> cqi_fdist2("DICKENS:NP","target", "lemma", "matchend","word")
 * 
 * ------------------------------------------------------------------------
 */
SEXP rcqpCmd_fdist2(SEXP inSubcorpus, SEXP inField1, SEXP inKey1, SEXP inField2, SEXP inKey2, SEXP inCutoff)
{
	SEXP			result = R_NilValue;
	char 			*subcorpus, *att1, *att2;
	CorpusList *	cl;
	int				i, cutoff, size;
	Group *			table;
	FieldType		fieldtype1 = NoField;
	FieldType		fieldtype2 = NoField;

	RCQ_CHECK_INITIALIZED

	PROTECT(inSubcorpus);
	PROTECT(inField1);
	PROTECT(inKey1);
	PROTECT(inField2);
	PROTECT(inKey2);
	PROTECT(inCutoff);
	
	subcorpus = (char*)CHAR(STRING_ELT(inSubcorpus,0));
	cl = cqi_find_corpus(subcorpus);
	if (cl == NULL) {
		UNPROTECT(6);
		rcqp_error_code(cqi_errno);
	}
	
	cutoff = asInteger(inCutoff);
	if (cutoff == NA_INTEGER) {
		UNPROTECT(6);
	    error("invalid 'cutoff' value (too large or NA)");
	}
	
	fieldtype1 = rcqp_get_field_type(inField1);
	fieldtype2 = rcqp_get_field_type(inField2);
	att1 = (char*)CHAR(STRING_ELT(inKey1,0));
	att2 = (char*)CHAR(STRING_ELT(inKey2,0));
	
    /* compute_grouping() returns tokens with f > cutoff, */
    /* but CQi specifies f >= cutoff */
    cutoff = (cutoff > 0) ? cutoff - 1 : 0;

	table = compute_grouping(cl, fieldtype1, 0, att1, fieldtype2, 0, att2, cutoff);
    if (table == NULL) {
      rcqp_error_code(CQI_CQP_ERROR_GENERAL);
    } else {
      size = table->nr_cells;
	  result = PROTECT(allocMatrix(INTSXP, size, 3));

	  for (i=0; i < size; i++) {
		  INTEGER(result)[i] = table->count_cells[i].s;
		  INTEGER(result)[i+size] = table->count_cells[i].t;
		  INTEGER(result)[i+(size*2)] = table->count_cells[i].freq;
      }

      free_group(&table);
    }

	UNPROTECT(7);
	
	return result;
}

