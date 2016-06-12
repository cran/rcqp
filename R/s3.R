# ===========================================================================
# File: "s3.R"
#                        Created: 2012-01-23 07:50:09
#              Last modification: 2016-06-07 14:51:28
# Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
#          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
# Copyright (c) 2011-2016 
# All rights reserved.
# ===========================================================================

# TODO : tokens => as.vector.cqp_attr ?
# table.cqp_attr

# c[ 1, ] # le premier token
# c[ text_date == "1997", ] # les rŽgions "textes_date" avec la valeur 1997
# c[ text_date == "1997", word ] # pourrait tre une expression pratique pour avoir une liste de vecteurs (un par rŽgion sŽlectionnŽe) contenant les formes flŽchies.
# c[ query(' [lemma="interesting"] [] "in" ' ) , ] # pour utiliser la requte cqp

# Indexer les sous-corpus diffŽremment ; pouvoir s'interroger sur les rŽgions dans un sous-corpus...
# sc[ "pos" ] # => liste de vecteurs ?

# Ou bien distinguer l'indexation du corpus => liste de vecteur ; la fonction query => un objet cqp_subcorpus ?

# as.list, as.data.frame (avec les structural att comme facteur) sur n'importe quel objet (c ou sc).

###########################################################################
# S3 generic methods
###########################################################################

size <- function (x) UseMethod("size");
cqp_flist <- function(x, ...) UseMethod("cqp_flist");
cqp_ftable <- function(x, ...) UseMethod("cqp_ftable");
cqp_kwic <- function(x, ...) UseMethod("cqp_kwic");
.cqp_name <- function (x, ...) UseMethod(".cqp_name");
ntype <- function (attribute, ...) UseMethod("ntype");
ntoken <- function (attribute, ...) UseMethod("ntoken");
nregion <- function (attribute, ...) UseMethod("nregion");
types <- function (attribute, ...) UseMethod("types");
regions <- function (attribute, ...) UseMethod("regions");
tokens <- function (attribute, ...) UseMethod("tokens");
region_sizes <- function (attribute) UseMethod("tokens");

###########################################################################
# Matrix-like interface for accessing cqp object
###########################################################################



# crŽation d'un sous-corpus
`[.cqp_corpus` <- function(i, j, k, ...) {
#	.create_cqp_attr(i, j);
#	.cqp_corpus2matrix <- function(x, from, to, use_value=use_value) {	

}


###########################################################################
# S3 Object cqp_attr
###########################################################################

`[[.cqp_corpus` <- function(i, j, ...) {
	.create_cqp_attr(i, j);
}

`$.cqp_corpus` <- function(x, name) {
	.create_cqp_attr(x, name);
}

.create_cqp_attr <- function(corpus, attribute) {
	qualified.attribute.name <- .cqp_name(corpus, attribute);
	cqp_corpus.name <- .cqp_name(corpus);
	
	cqp_attr <- 0;
	class(cqp_attr) <- "cqp_attr";
	attr(cqp_attr, "parent.cqp_corpus") <- corpus;
	attr(cqp_attr, "parent.cqp_corpus.name") <- cqp_corpus.name;
	attr(cqp_attr, "name") <- attribute;
	attr(cqp_attr, "qualified.attribute.name") <- qualified.attribute.name;
		
	positional <- cqi_attributes(cqp_corpus.name, "p");
	structural <- cqi_attributes(cqp_corpus.name, "s");	
	if (attribute %in% positional) {
		attr(cqp_attr, "type") <- "positional";
	} else if (attribute %in% structural) {
		attr(cqp_attr, "type") <- "structural";
		if (cqi_structural_attribute_has_values(qualified.attribute.name)) {
			attr(cqp_attr, "has_value") <- TRUE;
		} else {
			attr(cqp_attr, "has_value") <- FALSE;
		}
	} else {
		stop("Unknown attribute");
	}		
	
	return(cqp_attr);
}


## 
 # ------------------------------------------------------------------------
 # 
 # "types(corpus, attribute)" --
 #
 # Get the number of types or the actual list of types for a positional attribute
 # or a structural attribute "with values".
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              types( c$pos );
 #
 # ------------------------------------------------------------------------
 ##


ntype.cqp_attr <- function(attribute, ...) {
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");

	if (.is.positional(attribute)) {
		n <- cqi_lexicon_size(qualified.attribute.name);
	} else if (.is.structural(attribute)) {
		if (.has_value(attribute)) {
			n <- length(types(attribute));
		} else {
			stop("no values on this structural attribute");
		}
	} else {
		stop("attribute type unknown");
	}

	return(n);
}

## == size(corpus)
ntoken.cqp_attr <- function(attribute, ...) {
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");

	if (!.is.positional(attribute)) {
		stop("cannot count token on non-positional attribute");
	}
	n <- cqi_attribute_size(qualified.attribute.name);
	return(n);
}

nregion.cqp_attr <- function(attribute, ...) {
	if (!.is.structural(attribute)) {
		stop("cannot count region on non-structural attribute");
	}
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");
	n <- cqi_attribute_size(qualified.attribute.name);
	return(n);
}

tokens.cqp_attr <- function(attribute, ...) {
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");

	if (.is.positional(attribute)) {
		max <- ntoken(attribute) - 1;
		x <- cqi_cpos2id(qualified.attribute.name, 0:max);
		str <- types(attribute);
		x <- str[x];
	} else if (.is.structural(attribute)) {
		s <- size(attr(attribute, "parent.cqp_corpus"));
		max <- s - 1;
		x <- cqi_cpos2struc(qualified.attribute.name, 0:max);
	} else {
		stop("unknown type");
	}

	return(x);
}

types.cqp_attr <- function(attribute, ...) {
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");
	if (!.is.positional(attribute)) {
		stop("attribute must be positional");
	}	
	max.id <- ntype(attribute) - 1;
	ids <- 0:max.id;
	str <- cqi_id2str(qualified.attribute.name, ids);
	return(str);
}

regions.cqp_attr <- function(attribute, ...) {
	if (! .is.structural(attribute)) {
		stop("cannot list region on non-structural attribute");
	}
	if (!.has_value(attribute)) {
		stop("cannot list region on structural without value");
	}
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");
	max <- nregion(attribute) - 1;
	x <- cqi_struc2str(qualified.attribute.name, 0:max);

	return(x);
}

.is.positional <- function (attribute) {
	if(class(attribute) != "cqp_attr") {
		stop("attr must be a cqp_attr object");
	}
	type <- attr(attribute, "type");
	if (type=="positional") {
		return(TRUE);
	} else if (type=="structural") {
		return(FALSE);
	} else {
		stop("type of attribute is unknown");
	}
}

.is.structural <- function (attribute) {
	if(class(attribute) != "cqp_attr") {
		stop("attr must be a cqp_attr object");
	}
	type <- attr(attribute, "type");
	if (type=="positional") {
		return(FALSE);
	} else if (type=="structural") {
		return(TRUE);
	} else {
		stop("type of attribute is unknown");
	}
}

.has_value <- function (attribute) {
	if (!.is.structural(attribute)) stop("Not a structural attribute");
	has_value <- attr(attribute, "has_value");
	if (has_value) {
		return(TRUE);
	} else {
		return(FALSE);
	}
}


## 
 # ------------------------------------------------------------------------
 # 
 # "region_sizes.cqp_attr(attribute)" --
 #
 # Create a vector containing the size (in number of tokens) of the regions of
 # the given structural attribute.
 # 
 # Example:
 #              c <- corpus("DICKENS");
 #              region_sizes.cqp_corpus(c$np)
 # 
 # ------------------------------------------------------------------------
 ##

## TODO il y aurait encore plus simple : table() sur tous les struc.
region_sizes.cqp_attr <- function(attribute) {
	if (!.is.structural(attribute)) {
		stop("cannot list region on non-structural attribute");
	}
	
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");

	att_size <- cqi_attribute_size(qualified.attribute.name);
	return(
		sapply(
			0:(att_size-1),
			function(x) {
				bound <- cqi_struc2cpos(qualified.attribute.name, x);
				return(bound[2] - bound[1] + 1);
			}
		)
	);
}


summary.cqp_attr <- function(object, ...) {
	attribute <- object;
	type <- attr(attribute, "type");
	qualified.attribute.name <- attr(attribute, "qualified.attribute.name");
	
	cat(paste(type, ": "));
	
	if (type == "positional") {
		number_of_types <- ntype(object);
		cat(paste(
				qualified.attribute.name, 
				" (",
				number_of_types, " types; ",
				ntoken(object), " tokens",
				")\n",
				sep=""));
		.print_sample_types(cqi_id2str, qualified.attribute.name, number_of_types);
	} else {
		has_value <- attr(attribute, "has_value");
		if (has_value) {
			re <- regions(object);
			t <- unique(re);
			number_of_types <- length(t);
			cat(paste(
				qualified.attribute.name, 
				" (",
				number_of_types, " types; ",
				nregion(object), " regions",
				")\n",
				sep=""));
			.print_sample_types(cqi_struc2str, qualified.attribute.name, number_of_types);
		} else {
			cat(paste(
				qualified.attribute.name, 
				" (",
				nregion(object), " regions",
				")\n",
				sep=""));
		}
	}
}


.print_sample_types <- function(type_function, attribute, number_of_types, default=10) {
	max <- min(default, number_of_types) - 1;
	examples <- type_function(attribute, 0:max);
	while (sum(nchar(examples)) >= 50 & length(examples) > 2) {
		examples <- examples[-length(examples)];
	}
	ponct <- ifelse(length(examples) == number_of_types, ".", ", ...");
	examples <- paste("\"", examples, "\"", sep="");
	examples <- paste(examples, collapse=", ");
	examples <- paste(examples, ponct, sep="");
	cat(paste("\t\t", examples, "\n"));
}

print.cqp_attr <- function(x, ...) {
	print(tokens(x));
}


###########################################################################
# S3 Object cqp_corpus
###########################################################################



## 
 # ------------------------------------------------------------------------
 # 
 # "corpus(corpus, query)" --
 #
 # Create an S3 object holding a corpus
 # 
 # Example:
 #              corpus("DICKENS")
 # 
 # ------------------------------------------------------------------------
 ##
corpus <- function(corpus.name) {
        if (! corpus.name %in% cqi_list_corpora()) {
	    stop("This corpus does not exist, see cqi_list_corpora()");
	}
	x <- 0;
	class(x) <- "cqp_corpus";
	attr(x, "cqp_corpus.name") <- corpus.name;
	return(x);
}



.is_cqp_corpus <- function(x) {
	if (class(x) == "cqp_corpus") {
		return(TRUE);
	} else {
		return(FALSE);
	}
}

## 
 # ------------------------------------------------------------------------
 # 
 # "summary(corpus)" --
 #
 # Applying generic method "summary" to corpus object: print information.
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              summary(c)
 #
 # ------------------------------------------------------------------------
 ##
summary.cqp_corpus <- function(object, ...) {
	cqp_corpus.name <- .cqp_name(object);
	cat(paste(cqp_corpus.name, "\n"));
		
	p_attributes <- sort(cqi_attributes(cqp_corpus.name, "p"));
	s_attributes <- sort(cqi_attributes(cqp_corpus.name, "s"));
	a_attributes <- sort(cqi_attributes(cqp_corpus.name, "a"));
	
	tokens <- size(object);
	cat(paste("Number or tokens in the corpus:", tokens, "\n"));

	cat(paste("Positional attributes (", length(p_attributes), ")\n", sep=""));
	for (p in p_attributes) {
		#FIXME BUG
		summary(object[[ p ]]);
	}

	cat(paste("Structural attributes (", length(s_attributes), ")\n", sep=""));
	for (s in s_attributes) {
		if (tolower(s) != s) next;
		summary(object[[ s ]]);
	}

	cat(paste("Alignement attributes (", length(a_attributes), ")\n", sep=""));
	for (a in a_attributes) {
		summary(object[[ a ]]);
	}
		
}


## 
 # ------------------------------------------------------------------------
 # 
 # "print(corpus)" --
 #
 # Applying generic method "print" to corpus object: print all available information
 # for the given span of tokens of the corpus.
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              print(c)
 #
 # ------------------------------------------------------------------------
 ##
print.cqp_corpus <- function(x, from=0, to=20, use_value=TRUE, ...) {
	max <- size(x);
	if (any(c(from, to) >= max)) {
		stop("Token ids cannot be greater than corpus size");
	}
	if (from >= to) {
		stop("'from' must be lesser than 'to'");
	}
	if (any(c(from, to) < 0)) {
		stop("Token ids cannot be < 0");
	}

	printed <- .cqp_corpus2matrix(x, from, to, use_value=use_value);

	print(printed);
}


## 
 # ------------------------------------------------------------------------
 # 
 # "write.cqp_corpus(corpus, filename)" --
 #
 # Save a cqp corpus as a matrix.
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              write.cqp_corpus(c, "dickens.tab")
 #
 # ------------------------------------------------------------------------
 ##
write.cqp_corpus <- function(corpus, filename, from=0, to=1000, ...) {
	size <- size(corpus);
	mat <- .cqp_corpus2matrix(corpus, 0, size);
	write.table(mat, file=filename, ...);
}


.cqp_corpus2matrix <- function(x, from, to, use_value=use_value) {	
	
	cqp_corpus.name <- .cqp_name(x);
	max <- size(x) - 1;

	token_id=from:to;
	nbr_token <- length(token_id);

	positional <- cqi_attributes(cqp_corpus.name, "p");
	nbr_positional <- length(positional);

	structural <- cqi_attributes(cqp_corpus.name, "s");
	# FIXME : upper case name produces "Syntax error" with cqi_cpos2struc ?
	structural <- structural[grep("[a-z]+", structural)]
	nbr_structural <- length(structural);

	printed <- data.frame(matrix("", nrow=nbr_token, ncol=nbr_positional+nbr_structural));
	rownames(printed) <- token_id;
	colnames(printed) <- c(structural, positional);

	for (i in 1:nbr_structural) {
		qualified_structural_attribute <- .cqp_name(x, structural[i]);
		ids <- cqi_cpos2struc(qualified_structural_attribute, token_id);
		printed[,i] <- ids
	}
	
	for (i in 1:nbr_positional) {
		qualified_positional_attribute <- .cqp_name(x, positional[i]);
		ids <- cqi_cpos2str(qualified_positional_attribute, token_id);
		printed[,i+nbr_structural] <- ids
	}

	return(printed);
}


.cqp_name.cqp_corpus <- function(x, attribute=NULL) {
	corpus_name <- attr(x, "cqp_corpus.name");
	if (is.null(attribute)) {
		return(corpus_name);
	} else {
		return(paste(corpus_name, attribute, sep="."));
	}
}

size.cqp_corpus <- function(x) {	
	word.attribute <- .cqp_name(x, "word");
	return(cqi_attribute_size(word.attribute));
}

###########################################################################
# S3 Object cqp_subcorpus
###########################################################################


## 
 # ------------------------------------------------------------------------
 # 
 # "subcorpus(corpus, query)" --
 #
 # Create an S3 object holding a subcorpus
 # 
 # Example:
 #              subcorpus("DICKENS", '"interesting"')
 # 
 # ------------------------------------------------------------------------
 ##
subcorpus <- function(corpus, query) {
	if (!.is_cqp_corpus(corpus)) {
		stop("corpus: not a corpus object");
	}
	parent.cqp_corpus.name <- .cqp_name(corpus);
	
    cqp_subcorpus.name <- .generate.cqp_subcorpus.name(parent.cqp_corpus.name);
    cqi_query(parent.cqp_corpus.name, cqp_subcorpus.name, query);
	
	x <- 0;
    class(x) <- "cqp_subcorpus";

    attr(x, "cqp_subcorpus.name") <- cqp_subcorpus.name;
    attr(x, "parent.cqp_corpus.name") <- parent.cqp_corpus.name;
    attr(x, "query") <- query;
	return(x);
}



## 
 # ------------------------------------------------------------------------
 # 
 # "summary(subcorpus)" --
 #
 # Applying generic method "summary" to subcorpus object: print basic information.
 # 
 # Example:
 #              sc <- subcorpus("DICKENS", '"interesting"')
 #              summary(sc)
 #
 # ------------------------------------------------------------------------
 ##
summary.cqp_subcorpus <- function(object, ...) {
	parent_corpus.name <- attr(object, "parent.cqp_corpus.name");
	cat(paste("Parent corpus name:", parent_corpus.name, "\n"));

	size <- size(object);
	cat(paste("Number of matches:", size, "\n"));

	query <- attr(object, "query");
	cat(paste("Query:", query, "\n"));
}



## 
 # ------------------------------------------------------------------------
 # 
 # "print(subcorpus)" --
 #
 # Applying generic method "print" to corpus object: print first kwic lines of the corpus
 # 
 # Example:
 #              sc <- subcorpus("DICKENS", '"interesting"')
 #              print(sc)
 #
 # ------------------------------------------------------------------------
 ##
print.cqp_subcorpus <- function(x, positional.attribute="word", from=0, to=10, ...) {
	size <- size(x);
	max.line <- size - 1;
	if (to > max.line) {
		stop(paste("Max line:", max.line, "; max lines requested:", to));
	}
	
	k <- cqp_kwic(x);
	print(k, from=from, to=to);
}



.generate.cqp_subcorpus.name <- function(corpus) {
  subcorpora.name <- cqi_list_subcorpora(corpus);
  name <- .generate.name();
  if (length(subcorpora.name) == 0) {
	  return(name);
  }
  while (name %in% subcorpora.name) {
    name <- .generate.name();
  }
  return(name);
}



.generate.name <- function() {
  initial <- LETTERS[sample(1:26, 1)];
  other <- letters[sample(1:26, 9)];
  other <- paste(other, collapse="");
  return(paste(initial, other, sep=""));
}



.cqp_name.cqp_subcorpus <- function(x, qualified=TRUE) {
	parent.corpus <- attr(x, "parent.cqp_corpus.name");
	cqp_subcorpus.name <- attr(x, "cqp_subcorpus.name");
	if (qualified) {
		return(paste(parent.corpus, cqp_subcorpus.name, sep=":"));
	} else {
		return(cqp_subcorpus.name);
	}
}



size.cqp_subcorpus <- function(x) {
	qualified.name <- .cqp_name(x);
	return(cqi_subcorpus_size(qualified.name));
}



.is_cqp_subcorpus <- function(x) {
	if (class(x) == "cqp_subcorpus") {
		return(TRUE);
	} else {
		return(FALSE);
	}
}


###########################################################################
# S3 object cqp_flist
###########################################################################


## 
 # ------------------------------------------------------------------------
 # 
 # "cqp_flist(cqp_attribute, cutoff)" --
 #
 # Create an S3 object holding a frequency list
 #
 # A cqp_flist is a named numeric vector.
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              cqp_flist(sc, "lemma")
 #
 # ------------------------------------------------------------------------
 ##
cqp_flist.cqp_attr <- function(x, cutoff=0, ...) {
	c <- attr(x, "parent.cqp_corpus");
	attribute <- attr(x, "name");
	cqp_flist(c, attribute, cutoff);
}


## 
 # ------------------------------------------------------------------------
 # 
 # "cqp_flist(corpus, attribute, cutoff)" --
 #
 # Create an S3 object holding a frequency list
 #
 # A cqp_flist is a named numeric vector.
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              cqp_flist(c, "lemma")
 #
 # ------------------------------------------------------------------------
 ##
cqp_flist.cqp_corpus <- function(x, attribute, cutoff=0, ...) {

	cqp_corpus.name <- .cqp_name(x);
	
	positional <- cqi_attributes(cqp_corpus.name, "p");
	structural <- cqi_attributes(cqp_corpus.name, "s");
	
	qualified.attribute.name <- .cqp_name(x, attribute);

	if (attribute %in% positional) {
		max.id <- cqi_lexicon_size(qualified.attribute.name) - 1;
		ids <- 0:max.id;
		flist <- cqi_id2freq(qualified.attribute.name, ids);
		str <- cqi_id2str(qualified.attribute.name, ids);
		names(flist) <- str;
	} else if (attribute %in% structural) {
		if (cqi_structural_attribute_has_values(qualified.attribute.name)) {
			ids <- 0:(cqi_attribute_size(qualified.attribute.name)-1);
			values <- cqi_struc2str(qualified.attribute.name, ids);
			t <- table(values);
			flist <- as.numeric(t);
			names(flist) <- names(t);
		} else {
			stop("no values on this structural attribute");
		}
	} else {
		stop("Unknown attribute");
	}

	if (cutoff > 0) {
		if (cutoff < 1) {
			ordered <- order(flist, decreasing=TRUE);
			index <- ordered[1:(length(ordered)*cutoff)];
			flist <- flist[index];
		} else {
			flist <- flist[flist > cutoff];
		}
	}

   class(flist) <- "cqp_flist";

   attr(flist, "cqp_corpus.name") <- cqp_corpus.name;
   attr(flist, "attribute") <- attribute;
   return(flist);	
}



## 
 # ------------------------------------------------------------------------
 # 
 # "cqp_flist(subcorpus, anchor, attribute, left.context, right.context)" --
 #
 # Create an S3 object holding a frequency list
 #
 # A cqp_flist is a named numeric vector.
 # 
 # Example:
 #              c <- corpus("DICKENS")
 #              sc <- subcorpus(c, '"interesting"')
 #              cqp_flist(sc, "match", "lemma", 4, 4)
 #
 # "left.context" and "right.context" extend the span of the counted tokens around the anchor.
 #
 # if "target" is a character vector of length 2, such as c("match", "matchend"), the frequency list is computed
 # with all the tokens contained between match and matchend.
 # ------------------------------------------------------------------------
 ##
cqp_flist.cqp_subcorpus <- function(x, anchor, attribute, left.context=0, right.context=0, cutoff=0, offset=0, ...) {
	
	if (length(anchor) > 2 || length(anchor) < 1) {
		stop("anchor must be a vector of lenth 1 or 2");
	}
	
	parent.cqp_corpus.name <- attr(x, "parent.cqp_corpus.name");
	qualified.subcorpus.name <- .cqp_name(x);
	qualified.attribute <- paste(parent.cqp_corpus.name, attribute, sep=".");

	flist <- 0;
	
	if (length(anchor) == 1 & left.context == 0 & right.context == 0) {
		fdist <- cqi_fdist1(qualified.subcorpus.name, anchor, attribute, cutoff=cutoff, offset=offset);
		id <- fdist[,1];
		flist <- fdist[,2];
		names(flist) <- cqi_id2str(
			paste(parent.cqp_corpus.name, attribute, sep="."),
			id
		);
	} else {
		dump <- cqi_dump_subcorpus(qualified.subcorpus.name);
		
		colnames(dump) <- c("match", "matchend", "target", "keyword");
		left.cpos <- dump[,anchor[1]];
		left.cpos <- left.cpos + offset;
		if (left.context > 0) {
			left.cpos <- left.cpos - left.context;
		}
		right.anchor <- ifelse(length(anchor) > 1, anchor[2], anchor[1])
		right.cpos <- dump[,right.anchor] + right.context;
		
		#nbr_tokens <- sum(right.cpos-left.cpos);
		tokens <- sapply(
			1:length(left.cpos),
			function(x) {
				cqi_cpos2id(qualified.attribute, left.cpos[x]:right.cpos[x]);
			}
		);
		tokens <- as.numeric(tokens);
		
		flist <- table(tokens);
		ids <- as.numeric(names(flist));
		names(flist) <- cqi_id2str(qualified.attribute, ids);
	}		
	
   class(flist) <- "cqp_flist";

   attr(flist, "cqp_subcorpus.name") <- attr(x, "cqp_subcorpus.name");  
   attr(flist, "parent.cqp_corpus.name") <- parent.cqp_corpus.name;
   attr(flist, "anchor") <- anchor;
   attr(flist, "left.context") <- left.context;
   attr(flist, "right.context") <- right.context;
   attr(flist, "attribute") <- attribute;
   attr(flist, "offset") <- offset;

   return(flist);
}



## 
 # ------------------------------------------------------------------------
 # 
 # "summary(cqp_flist)" --
 #
 # Applying generic method "summary" to cqp_flist object: print basic information.
 # 
 # ------------------------------------------------------------------------
 ##
summary.cqp_flist <- function(object, ...) {

	cat("A frequency list\n");
	cat(paste("  Number of tokens:", sum(object), "\n"));
	cat(paste("  Number of types:", length(object), "\n"));

	cqp_corpus.name <- attr(object, "cqp_corpus.name");

	if (!is.null(cqp_corpus.name)) {
		attribute <- attr(object, "attribute");
		cat(paste("  Corpus:", cqp_corpus.name, "\n"));
		cat(paste("  Attribute:", attribute, "\n"));
	} else {
		cat(paste("  Subcorpus:", attr(object, "cqp_subcorpus.name"), "\n"));
		cat(paste("  Parent corpus:", attr(object, "parent.cqp_corpus.name"), "\n"));
		cat(paste("  anchor:", attr(object, "anchor"), "\n"));
		cat(paste("  left.context:", attr(object, "left.context"), "\n"));
		cat(paste("  right.context:", attr(object, "right.context"), "\n"));
		cat(paste("  attribute:", attr(object, "attribute"), "\n"));
		cat(paste("  offset:", attr(object, "offset"), "\n"));
	}
}



## 
 # ------------------------------------------------------------------------
 # 
 #
 # ------------------------------------------------------------------------
 ##
print.cqp_flist <- function(x, ...) {
	df <- data.frame(names(x), as.numeric(x));
	colnames(df) <- c("type", "frequency");
	print(df, row.names=FALSE);
}



###########################################################################
# S3 Object cqp_ftable
###########################################################################

## 
 # ------------------------------------------------------------------------
 #
 # Create an S3 object holding a frequency table accordint to various parameters
 # 
 # ------------------------------------------------------------------------
 ##
cqp_ftable.cqp_corpus <- function(x, attribute1, attribute2, 
	attribute1.use.id=FALSE, attribute2.use.id=FALSE,
	structural.attribute.unique.id=FALSE, subcorpus=NULL,
	...
) {
	cqp_corpus.name <- .cqp_name(x);
	qualified.attribute1 <- .cqp_name(x, attribute1);
	qualified.attribute2 <- .cqp_name(x, attribute2);
	
	corpus_size <- size(x);
	max_id <- corpus_size - 1;
	
	s_atts <- cqi_attributes(cqp_corpus.name, "s");
	p_atts <- cqi_attributes(cqp_corpus.name, "p");

	##
	## extract id.
	##
	
	att1 <- 0;
	if (attribute1 %in% s_atts) {
		att1 <- cqi_cpos2struc(qualified.attribute1, 0:max_id);
	} else if (attribute1 %in% p_atts) {
		# TODO array base
		att1 <- cqi_cpos2id(qualified.attribute1, 0:max_id);
	} else {
		stop(paste("Unknown attribute:", attribute1));
	}

	att2 <- 0;
	if (attribute2 %in% s_atts) {
		# TODO array base
		att2 <- cqi_cpos2struc(qualified.attribute2, 0:max_id);
	} else if (attribute2 %in% p_atts) {
		# TODO array base
		att2 <- cqi_cpos2id(qualified.attribute2, 0:max_id);
	} else {
		stop(paste("Unknown attribute:", attribute2));
	}

	##
	## Create the id matrix
	##

	ids <- matrix(c(att1, att2), ncol=2);

	if (structural.attribute.unique.id) {
		if (! (attribute1 %in% s_atts)
			||
			! (attribute2 %in% s_atts)
		) {
			stop("Both attribute must be structural attributes in order to reduce id");
		}
		ids <- unique(ids);
	}

	##
	## replace id with string if requested.
	##

	res <- data.frame(attribute1=ids[,1], attribute2=ids[,2]);
	if (attribute1 %in% s_atts) {
		if ((!attribute1.use.id) & cqi_structural_attribute_has_values(qualified.attribute1)) {
			res[,1] <- cqi_struc2str(qualified.attribute1, ids[,1]);
		}
	} else {
		if (!attribute1.use.id) {
			res[,1] <- cqi_id2str(qualified.attribute1, ids[,1]);
		}
	}

	if (attribute2 %in% s_atts) {
		if ((!attribute2.use.id) & cqi_structural_attribute_has_values(qualified.attribute2)) {
			res[,2] <- cqi_struc2str(qualified.attribute2, ids[,2]);
		}
	} else {
		if (!attribute2.use.id) {
			res[,2] <- cqi_id2str(qualified.attribute2, ids[,2]);
		}
	}
	
	##
	## Count unique combinaison.
	##
	t <- count(res);

	colnames(t) <- c(
		attribute1,
		attribute2,
		"freq"
	);

	return(t);
}



cqp_ftable.cqp_subcorpus <- function(x, anchor1, attribute1, anchor2, attribute2, cutoff=0, ...) {
	parent.corpus <- attr(x, "parent.cqp_corpus.name");
	qualified.sub_corpus.name <- .cqp_name(x);
	
	m <- cqi_fdist2(qualified.sub_corpus.name, anchor1, attribute1, anchor2, attribute2, cutoff=cutoff);

	attribute1.str <- cqi_id2str(paste(parent.corpus, attribute1, sep="."), m[,1]);
  	attribute2.str <- cqi_id2str(paste(parent.corpus, attribute2, sep="."), m[,2]);
 
	df <- data.frame(attribute1.str, attribute2.str, m[,3]);
	colnames(df) <- c(
		paste(anchor1, attribute1, sep="."),
		paste(anchor2, attribute2, sep="."),
		"freq");
	return(df);
}



###########################################################################
# S3 Object cqp_kwic
###########################################################################


cqp_kwic.cqp_subcorpus <- function(x,
	right.context=20,
	left.context=20,
	...
) {
	size <- size(x);
	if (size == 0) {
		stop("empty subcorpus");
	}
	
	s <- .get.kwic.matrix(x, right.context, left.context);	

	attr(s, "parent.cqp_corpus.name") <- attr(x, "parent.cqp_corpus.name");
	attr(s, "cqp_subcorpus.name") <- attr(x, "cqp_subcorpus.name");
	attr(s, "right.context") <- right.context;
	attr(s, "left.context") <- left.context;
	class(s) <- "cqp_kwic";
	return(s);
}



sort.cqp_kwic <- function(x, decreasing=FALSE, sort.anchor="match", sort.attribute="word", sort.offset=0, ...) {
	if (!class(x) == "cqp_kwic") {
		stop("x must be a cqp_kwic object");
	}
	
	if (! sort.anchor %in%  c("match", "matchend", "target", "keyword")) {
		stop('sort.anchor must be in c("match", "matchend", "target", "keyword")');
	}

	parent.cqp_corpus.name <- attr(x, "parent.cqp_corpus.name");
	if (! sort.attribute %in%  cqi_attributes(parent.cqp_corpus.name, "p")) {
		stop('sort.attribute must be an existing positional attribute');
	}	
	qualified_attribute <- paste(parent.cqp_corpus.name, sort.attribute, sep=".");

	cpos <- x[, sort.anchor];
	if (sort.offset != 0) {
		cpos <- cpos + sort.offset;

		unreachable.small <- cpos < 0;
		cpos[unreachable.small] <- 0;
		
		size <- cqi_attribute_size(qualified_attribute);
		max.id <- size - 1;
		unreachable.big <- cpos > max.id;
		cpos[unreachable.big] <- max.id;		
	} else {
		unreachable.small <- logical(length(cpos));
		unreachable.big <- logical(length(cpos));
	}
	
	str <- cqi_cpos2str(qualified_attribute, cpos);
	str[unreachable.small] <- "";
	str[unreachable.big] <- "";
	i <- order(str, decreasing=decreasing);

	sorted <- x[i,];
	attributes(sorted) <- attributes(x);
	return(sorted);
}

.get.kwic.matrix <- function(x, right.context, left.context) {
	qualified_subcorpus_name <- .cqp_name(x);

	dump <- cqi_dump_subcorpus(qualified_subcorpus_name);
	left.boundary <- pmax(dump[,1] - left.context, 0);
	dim(left.boundary) <- c(nrow(dump), 1);

	parent.cqp_corpus.name <- attr(x, "parent.cqp_corpus.name");
	corpus_size <- cqi_attribute_size(paste(parent.cqp_corpus.name, "word", sep="."));
	
	max_id <- corpus_size - 1;
	right.boundary <- pmin(dump[,2] + right.context, max_id);
	dim(right.boundary) <- c(nrow(dump), 1);

	dump <- cbind(dump, left.boundary, right.boundary);
	colnames(dump) <- c("match", "matchend", "target", "keyword", "left", "right");
	return(dump);
}

print.cqp_kwic <- function(x,
	from=0,
	to=min(20, nrow(x)-1),
	print_tokens=function(x, cpos) cqi_cpos2str(paste(attr(x, "parent.cqp_corpus.name"), "word", sep="."), cpos),
	left.separator=" <<",
	right.separator=">> ",
	...
)
{
	if (from < 0) {
		stop("'from' must be greater than 0");
	}
	if (from > to) {
		stop("'to' must be greater than from");
	}
	if (to >= nrow(x)) {
		stop("'to' must be lesser than the size of the subcorpus");
	}

	requested.left.char= attr(x, "left.context")
	requested.right.char= attr(x, "right.context")

	nbr.lines <- to-from+1;
	matrix.lines <- matrix("", nrow=nbr.lines, ncol=3);
	for (i in 1:nbr.lines) {
		l <- x[from + i,];
		matrix.lines[i, 1] <- paste(
			print_tokens(x, l["left"]:(l["match"]-1)),
			collapse=" "
		);

		c1 <- print_tokens(x, l["match"]:l["matchend"]);
		c2 <- c(left.separator, c1, right.separator);
		matrix.lines[i, 2] <- paste(c2, collapse=" ");
		
		matrix.lines[i, 3] <- paste(
			print_tokens(x, (l["matchend"]+1):l["right"]),
			collapse=" "
		);
	}

	left.nchar <- nchar(matrix.lines[,1]);
	center.nchar <- nchar(matrix.lines[,2]);
	right.nchar <- nchar(matrix.lines[,3]);
	
	left <- substr(matrix.lines[,1], left.nchar - requested.left.char, left.nchar);
	requested.center.char <- max(center.nchar);
	right <- substr(matrix.lines[,3], 1, right.nchar - (right.nchar - requested.right.char));

	format <- paste("%10d %", requested.left.char, "s%", requested.center.char, "s%-", requested.right.char, "s", sep="");
	r_from_to <- (from:to) + 1;
	lines <- sprintf(format, x[r_from_to, "match"], left, matrix.lines[,2], right);
	
	for(i in lines) {
		cat(paste(i, "\n", sep=""));
	}
}
