/* ===========================================================================
 * File: "rcqpCommands.h"
 *                        Created: 2012-01-13 18:49:02
 *              Last modification: 2016-06-09 14:03:28
 * Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
 *          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
 * ===========================================================================
 */


#ifndef	RCQP_COMMANDS_H
#define RCQP_COMMANDS_H
#pragma once



/* Prototypes
 * ----------
 */

void rcqp_start_cwb();

SEXP rcqpCmd_setRegistry(SEXP inPath);
SEXP rcqpCmd_attribute_size(SEXP inAttribute);
SEXP rcqpCmd_attributes(SEXP inCorpus, SEXP inType);
SEXP rcqpCmd_charset(SEXP inCorpus);
SEXP rcqpCmd_corpus_info(SEXP inCorpus);
SEXP rcqpCmd_cpos2alg(SEXP inAttribute, SEXP inCpos);
SEXP rcqpCmd_cpos2id(SEXP inAttribute, SEXP inCpos);
SEXP rcqpCmd_cpos2lbound(SEXP inAttribute, SEXP inIds);
SEXP rcqpCmd_cpos2rbound(SEXP inAttribute, SEXP inCpos);
SEXP rcqpCmd_cpos2str(SEXP inAttribute, SEXP inCpos);
SEXP rcqpCmd_cpos2struc(SEXP inAttribute, SEXP inIds);
SEXP rcqpCmd_drop_subcorpus(SEXP inSubcorpus);
SEXP rcqpCmd_dump_subcorpus(SEXP inSubcorpus, SEXP inFirst, SEXP inLast);
SEXP rcqpCmd_fdist1(SEXP inSubcorpus, SEXP inField, SEXP inKey, SEXP inCutoff, SEXP inOffset);
SEXP rcqpCmd_fdist2(SEXP inSubcorpus, SEXP inField1, SEXP inKey1, SEXP inField2, SEXP inKey2, SEXP inCutoff);
SEXP rcqpCmd_full_name(SEXP inCorpus);
SEXP rcqpCmd_id2cpos(SEXP inAttribute, SEXP inId);
SEXP rcqpCmd_id2freq(SEXP inAttribute, SEXP inIds);
SEXP rcqpCmd_id2str(SEXP inAttribute, SEXP inIds);
SEXP rcqpCmd_idlist2cpos(SEXP inAttribute, SEXP inIds);
SEXP rcqpCmd_lexicon_size(SEXP inAttribute);
SEXP rcqpCmd_list_corpora();
SEXP rcqpCmd_list_subcorpora(SEXP inCorpus);
SEXP rcqpCmd_properties(SEXP inCorpus);
/*SEXP rcqpCmd_cqp(SEXP inQuery); */
SEXP rcqpCmd_query(SEXP inMother, SEXP inChild, SEXP inQuery);
SEXP rcqpCmd_regex2id(SEXP inAttribute, SEXP inRegex);
SEXP rcqpCmd_str2id(SEXP inAttribute, SEXP inStrs);
SEXP rcqpCmd_struc2cpos(SEXP inAttribute, SEXP inStruc);
SEXP rcqpCmd_struc2str(SEXP inAttribute, SEXP inIds);
SEXP rcqpCmd_structural_attribute_has_values(SEXP inAttribute);
SEXP rcqpCmd_subcorpus_size(SEXP inSubcorpus);



#endif  /* RCQP_COMMANDS_H */

