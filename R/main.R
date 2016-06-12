# ===========================================================================
# File: "main.R"
#                        Created: 2011-11-24 12:53:46
#              Last modification: 2012-01-17 15:18:10
# Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
#          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
# (c) Copyright: 2011-2012
# All rights reserved.
# ===========================================================================


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_getRegistry()" --
 # 
 # Example:
 #		cqi_setRegistry()
 # 
 # ------------------------------------------------------------------------
 ##
cqi_getRegistry <- function() {
	ans <- .Call("rcqpCmd_getRegistry", PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_setRegistry(path)" --
 # 
 # Example:
 #		cqi_setRegistry("/opt/local/share/cwb/registry")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_setRegistry <- function(path) {
	.Call("rcqpCmd_setRegistry", path, PACKAGE="rcqp")
    return(invisible())
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_query(mother, child, query)" --
 # 
 # Example:
 #		cqi_query("DICKENS","Foo","\"interesting\"")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_query <- function(mother, child, query) {
	if (nchar(child) == 0) {
		child <- "Last"
	}
	if (! grepl("[A-Z][[:alnum:]_-]+", child)) {
		stop(paste(
			"The name of a subcorpus must start with an uppercase",
			"letter and can contain both uppercase and lowercase",
			"letters, underscores, dashes and digits."));
	}
	.Call("rcqpCmd_query", mother, child, query, PACKAGE="rcqp")
    return(invisible())
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_list_corpora()" --
 # 
 # Example:
 #		cqi_list_corpora()
 # 
 # ------------------------------------------------------------------------
 ##
cqi_list_corpora <- function() {
	ans <- .Call("rcqpCmd_list_corpora", PACKAGE="rcqp")
    return(ans)
} 


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_list_subcorpora(corpus)" --
 # 
 # Example:
 #		cqi_query("DICKENS","Foo","\"interesting\"")
 #		cqi_list_subcorpora("DICKENS")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_list_subcorpora <- function(corpus) {
	ans <- .Call("rcqpCmd_list_subcorpora", corpus, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_full_name(corpus)" --
 # 
 # Example:
 #		cqi_full_name("DICKENS")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_full_name <- function(corpus) {
	ans <- .Call("rcqpCmd_full_name", corpus, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_corpus_info(corpus)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_corpus_info <- function(corpus) {
	ans <- .Call("rcqpCmd_corpus_info", corpus, PACKAGE="rcqp")
    return(invisible())
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_subcorpus_size(subcorpus)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_subcorpus_size <- function(subcorpus) {
	ans <- .Call("rcqpCmd_subcorpus_size", subcorpus, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_dump_subcorpus(subcorpus, first, last)" --
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_dump_subcorpus <- function(subcorpus, first=0, last=cqi_subcorpus_size(subcorpus)-1) {
	ans <- .Call("rcqpCmd_dump_subcorpus", subcorpus, first, last, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_drop_subcorpus(subcorpus)" --
 # 
 # Example:
#     cqi_drop_subcorpus("DICKENS:Foo")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_drop_subcorpus <- function(subcorpus) {
	.Call("rcqpCmd_drop_subcorpus", subcorpus, PACKAGE="rcqp")
    return(invisible())
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_fdist(subcorpus, field, key, cutoff=0, offset=0)" --
 # 
 # Field argument can be one of : 'match', 'matchend', 'target', 'keyword'.
 # Key argument is a positional attribute ('word', 'pos', 'lemma', etc.).
 # 
 # Example:
 #     cqi_fdist("DICKENS:Go","matchend","pos")
 #     cqi_fdist("DICKENS:NP","target","lemma",300)
 #     cqi_fdist("DICKENS:NP","match","lemma", cutoff=2000, offset=-1)

 # 
 # ------------------------------------------------------------------------
 ##
cqi_fdist1 <- function(subcorpus, field1, key1, cutoff=0, offset=0) {
	ans <- .Call("rcqpCmd_fdist1", subcorpus, field1, key1, as.integer(cutoff), as.integer(offset), PACKAGE="rcqp")
    return(ans)
}

## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_fdist2(subcorpus, field1, key1, field2, key2 cutoff=0)" --
 # 
 # fied1 and field2 can be one of : 'match', 'matchend', 'target', 'keyword'.
 # key1 and key2 arguments are positional attribute ('word', 'pos', 'lemma', etc.).
 # 
 # Example:
 #     cqi_fdist2("DICKENS:Go","matchend","pos", "target", "lemma")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_fdist2 <- function(subcorpus, field1, key1, field2, key2, cutoff=0) {
	ans <- .Call("rcqpCmd_fdist2", subcorpus, field1, key1, field2, key2, as.integer(cutoff), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_attributes(corpus, type)" --
 # 
 # The 'type' argument can be 
 #               "p" => positional attributes 
 #               "s" => structural attributes 
 #               "a" => alignment attributes 
 # 
 # Examples:
 #		cqi_attributes("DICKENS", "p")
 #		cqi_attributes("DICKENS", "s")
 #		cqi_attributes("DICKENS", "a")
 #
 # ------------------------------------------------------------------------
 ##
cqi_attributes <- function(corpus, type) {
	ans <- .Call("rcqpCmd_attributes", corpus, type, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_attribute_size(attribute)" --
 # 
 # Examples:
 #		cqi_attribute_size("DICKENS.lemma")
 #		cqi_attribute_size("DICKENS.book")
 #		cqi_attribute_size("DICKENS.file")
 #		cqi_attribute_size("DICKENS.chapter")
 #		cqi_attribute_size("DICKENS.p")
 #		cqi_attribute_size("DICKENS.p_len")
 # 
 # ------------------------------------------------------------------------
 ##
cqi_attribute_size <- function(attribute) {
	ans <- .Call("rcqpCmd_attribute_size", attribute, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_structural_attribute_has_values(attribute)" --
 # 
 # Examples:
 #		cqi_structural_attribute_has_values("DICKENS.p")
 #		cqi_structural_attribute_has_values("DICKENS.p_len")
 #		cqi_structural_attribute_has_values("DICKENS.np")
 #		cqi_structural_attribute_has_values("DICKENS.np_len")
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_structural_attribute_has_values <- function(attribute) {
	ans <- .Call("rcqpCmd_structural_attribute_has_values", attribute, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_lexicon_size(attribute)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_lexicon_size <- function(attribute) {
	ans <- .Call("rcqpCmd_lexicon_size", attribute, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_str2id(attribute, strs)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_str2id <- function(attribute, strs) {
	ans <- .Call("rcqpCmd_str2id", attribute, strs, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_id2str(attribute, ids)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_id2str <- function(attribute, ids) {
	ans <- .Call("rcqpCmd_id2str", attribute, as.integer(ids), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_id2freq(attribute, ids)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_id2freq <- function(attribute, ids) {
	ans <- .Call("rcqpCmd_id2freq", attribute, as.integer(ids), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cpos2id(attribute, cpos)" --
 # 
 # Example:
 #		cqi_query("DICKENS","Foo","\"interesting\";")
 #		cpos <- cqi_dump_subcorpus("DICKENS:Foo",1,1)[1,1]
 #		cqi_cpos2id("DICKENS.pos", cpos)
 #		cqi_cpos2id("DICKENS.word", cpos)
 #		cqi_cpos2id("DICKENS.lemma", cpos)
 # 
 # ------------------------------------------------------------------------
 ##
cqi_cpos2id <- function(attribute, cpos) {
	ans <- .Call("rcqpCmd_cpos2id", attribute, as.integer(cpos), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cpos2str(attribute, cpos)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_cpos2str <- function(attribute, cpos) {
	ans <- .Call("rcqpCmd_cpos2str", attribute, as.integer(cpos), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cpos2struc(attribute, cpos)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_cpos2struc <- function(attribute, cpos) {
	ans <- .Call("rcqpCmd_cpos2struc", attribute, as.integer(cpos), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cpos2lbound(attribute, cpos)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_cpos2lbound <- function(attribute, cpos) {
	ans <- .Call("rcqpCmd_cpos2lbound", attribute, as.integer(cpos), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cpos2rbound(attribute, cpos)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_cpos2rbound <- function(attribute, cpos) {
	ans <- .Call("rcqpCmd_cpos2rbound", attribute, as.integer(cpos), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_alg2cpos(attribute, alg)" --
 # 
 # Alignment attributes: a set of zones of alignment between a source and
 # target corpus.
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_alg2cpos <- function(attribute, alg) {
	ans <- .Call("rcqpCmd_alg2cpos", attribute, as.integer(alg), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cpos2alg(attribute, cpos)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_cpos2alg <- function(attribute, cpos) {
	ans <- .Call("rcqpCmd_cpos2alg", attribute, as.integer(cpos), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_id2cpos(attribute, id)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_id2cpos <- function(attribute, id) {
	ans <- .Call("rcqpCmd_id2cpos", attribute, as.integer(id), PACKAGE="rcqp")
    return(ans)
}


# ## 
#  # ------------------------------------------------------------------------
#  # 
#  # "cqi_idlist2cpos(attribute, ids)" --
#  # 
#  # Example:
#  # 
#  # 
#  # ------------------------------------------------------------------------
#  ##
# cqi_idlist2cpos <- function(attribute, ids) {
# 	ans <- .Call("rcqpCmd_idlist2cpos", attribute, as.integer(ids), PACKAGE="rcqp")
#     return(ans)
# }


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_regex2id(attribute, regex)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_regex2id <- function(attribute, regex) {
	ans <- .Call("rcqpCmd_regex2id", attribute, regex, PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_struc2cpos(attribute, struc)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_struc2cpos <- function(attribute, struc) {
	ans <- .Call("rcqpCmd_struc2cpos", attribute, as.integer(struc), PACKAGE="rcqp")
    return(ans)
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_struc2str(attribute, ids)" --
 # 
 # Example:
 # 
 # 
 # ------------------------------------------------------------------------
 ##
cqi_struc2str <- function(attribute, ids) {
	ans <- .Call("rcqpCmd_struc2str", attribute, as.integer(ids), PACKAGE="rcqp")
    return(ans)
}



# ## 
#  # ------------------------------------------------------------------------
#  # 
#  # "concordance" --
#  # 
#  # ------------------------------------------------------------------------
#  ##
# concordance <- function(corpus, query, left.context=10, right.context=10)
# {
# 	ans <- .Call("rcqpCmd_concordance", corpus, query, left.context, right.context, PACKAGE="rcqp")
#     return(ans)
# }


## 
 # ------------------------------------------------------------------------
 # 
 # "cqi_cqp(mother, child, query)" --
 # 
 # Example:
 #      cqi_query("DICKENS", "Aa", '[(pos="JJ") & (lemma="modern")];')
 #		cqi_cqp('set Aa keyword nearest [pos="NN"] within right 5 words from match;')
 # 
 # ------------------------------------------------------------------------
 ##
# cqi_cqp <- function(query) {
# # 	if (nchar(child) == 0) {
# # 
# # 	} TODO check ;
# 	.Call("rcqpCmd_cqp", query, PACKAGE="rcqp")
#     return(invisible())
# }


# ## 
#  # ------------------------------------------------------------------------
#  # 
#  # "cqi_charset(corpus)" --
#  # 
#  # Currently always returns "latin1".
#  # 
#  # ------------------------------------------------------------------------
#  ##
# cqi_charset <- function(corpus) {
# 	ans <- .Call("rcqpCmd_charset", corpus, PACKAGE="rcqp")
#     return(ans)
# }


# ## 
#  # ------------------------------------------------------------------------
#  # 
#  # "cqi_properties(corpus)" --
#  # 
#  # Example:
#  # 
#  # 
#  # ------------------------------------------------------------------------
#  ##
# cqi_properties <- function(corpus) {
# 	ans <- .Call("rcqpCmd_properties", corpus, PACKAGE="rcqp")
#     return(ans)
# }




