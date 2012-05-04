pkgname <- "rcqp"
source(file.path(R.home("share"), "R", "examples-header.R"))
options(warn = 1)
library('rcqp')

assign(".oldSearch", search(), pos = 'CheckExEnv')
cleanEx()
nameEx("corpus")
### * corpus

flush(stderr()); flush(stdout())

### Name: corpus
### Title: Create a corpus object
### Aliases: corpus

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
## End(Not run)



cleanEx()
nameEx("cqi_attribute_size")
### * cqi_attribute_size

flush(stderr()); flush(stdout())

### Name: cqi_attribute_size
### Title: Get the size of an attribute
### Aliases: cqi_attribute_size cqi_structural_attribute_has_values
###   cqi_lexicon_size
### Keywords: attribute

### ** Examples

## Not run: 
##D cqi_structural_attribute_has_values("DICKENS.file")
##D cqi_structural_attribute_has_values("DICKENS.file_name")
##D cqi_structural_attribute_has_values("DICKENS.chapter")
##D cqi_structural_attribute_has_values("DICKENS.chapter_title")
##D 
##D cqi_lexicon_size("DICKENS.lemma")
##D cqi_lexicon_size("DICKENS.pos")
##D cqi_lexicon_size("DICKENS.word")
##D 
##D # Positional attribute
##D cqi_attribute_size("DICKENS.lemma")
##D cqi_attribute_size("DICKENS.pos")
##D cqi_attribute_size("DICKENS.word")
##D 
##D # Structural attributes
##D cqi_attribute_size("DICKENS.book")
##D cqi_attribute_size("DICKENS.file")
##D cqi_attribute_size("DICKENS.chapter")
## End(Not run)



cleanEx()
nameEx("cqi_attributes")
### * cqi_attributes

flush(stderr()); flush(stdout())

### Name: cqi_attributes
### Title: List the available attributes
### Aliases: cqi_attributes
### Keywords: corpus, attributes

### ** Examples

## Not run: 
##D cqi_attributes("DICKENS", "p")
##D cqi_attributes("DICKENS", "s")
##D cqi_attributes("DICKENS", "a")
## End(Not run)



cleanEx()
nameEx("cqi_corpus_info")
### * cqi_corpus_info

flush(stderr()); flush(stdout())

### Name: cqi_corpus_info
### Title: Info about a corpus
### Aliases: cqi_corpus_info

### ** Examples

## Not run: 
##D cqi_corpus_info("DICKENS")
## End(Not run)



cleanEx()
nameEx("cqi_cpos2id")
### * cqi_cpos2id

flush(stderr()); flush(stdout())

### Name: cqi_cpos2id
### Title: Convert a corpus position
### Aliases: cqi_cpos2id cqi_cpos2lbound cqi_cpos2rbound cqi_cpos2str
###   cqi_cpos2alg cqi_cpos2struc cqi_alg2cpos
### Keywords: corpus positions

### ** Examples

## Not run: 
##D cqi_query("DICKENS","Foo","\"eas(y|ier|iest)\";")
##D cpos <- cqi_dump_subcorpus("DICKENS:Foo")[1:20,1]
##D 
##D cqi_cpos2id("DICKENS.pos", cpos)
##D cqi_cpos2str("DICKENS.pos", cpos)
##D cqi_cpos2id("DICKENS.word", cpos)
##D cqi_cpos2str("DICKENS.word", cpos)
##D cqi_cpos2id("DICKENS.lemma", cpos)
##D cqi_cpos2str("DICKENS.lemma", cpos)
##D 
##D cqi_query("DICKENS","Foo","\"interesting\";")
##D cpos <- cqi_dump_subcorpus("DICKENS:Foo",1,10)[,1]
##D 
##D # Expects structural attributes
##D cqi_cpos2lbound("DICKENS.chapter", cpos)
##D cqi_cpos2rbound("DICKENS.chapter", cpos)
##D 
##D cqi_cpos2struc("DICKENS.chapter", cpos)
## End(Not run)



cleanEx()
nameEx("cqi_dump_subcorpus")
### * cqi_dump_subcorpus

flush(stderr()); flush(stdout())

### Name: cqi_dump_subcorpus
### Title: Handle subcorpora
### Aliases: cqi_dump_subcorpus cqi_subcorpus_size cqi_drop_subcorpus
### Keywords: subcorpus, indices

### ** Examples

## Not run: 
##D cqi_query("DICKENS","Foo","\"interesting\";")
##D cqi_subcorpus_size("DICKENS:Foo")
##D cqi_dump_subcorpus("DICKENS:Foo")
##D cqi_dump_subcorpus("DICKENS:Foo",4,10)
## End(Not run)



cleanEx()
nameEx("cqi_fdist")
### * cqi_fdist

flush(stderr()); flush(stdout())

### Name: cqi_fdist
### Title: Frequency distributions
### Aliases: cqi_fdist cqi_fdist1 cqi_fdist2
### Keywords: frequency

### ** Examples

## Not run: 
##D cqi_query("DICKENS","Go","[lemma=\"go\"] \"and\" [];")
##D m <- cqi_fdist1("DICKENS:Go","matchend","pos")
##D cqi_id2str("DICKENS.pos", m[,1])
##D 
##D cqi_query("DICKENS","NP","[pos=\"DT\"] @[pos=\"JJ\"]? [pos=\"NNS?\"];")
##D cqi_fdist1("DICKENS:NP","target","lemma",300)
##D cqi_fdist1("DICKENS:NP","match","lemma", cutoff=2000, offset=-1)
##D 
##D cqi_fdist2("DICKENS:Go","matchend", "pos", "matchend","lemma")
##D cqi_fdist2("DICKENS:NP","target", "lemma", "matchend","word", cutoff=300)
## End(Not run)



cleanEx()
nameEx("cqi_full_name")
### * cqi_full_name

flush(stderr()); flush(stdout())

### Name: cqi_full_name
### Title: Full name of a corpus
### Aliases: cqi_full_name
### Keywords: corpus

### ** Examples

## Not run: 
##D cqi_full_name("DICKENS")
## End(Not run)



cleanEx()
nameEx("cqi_id2cpos")
### * cqi_id2cpos

flush(stderr()); flush(stdout())

### Name: cqi_id2cpos
### Title: Convert the ID of an item
### Aliases: cqi_id2cpos cqi_id2freq cqi_id2str cqi_str2id
### Keywords: corpus position

### ** Examples

## Not run: 
##D cqi_query("DICKENS","Foo","\"eas(y|ier|iest)\";")
##D cpos <- cqi_dump_subcorpus("DICKENS:Foo")[1,1]
##D 
##D # # cqi_id2cpos
##D pids <- unique(cqi_cpos2id("DICKENS.pos", cpos))
##D ppos <- cqi_id2cpos("DICKENS.pos", pids[1])
##D ppos[1:50]
##D 
##D wids <- unique(cqi_cpos2id("DICKENS.word", cpos))
##D wpos <- cqi_id2cpos("DICKENS.word", wids[1])
##D wpos[1:50]
##D 
##D lids <- unique(cqi_cpos2id("DICKENS.lemma", cpos))
##D lpos <- cqi_id2cpos("DICKENS.lemma", lids[1])
##D lpos[1:50]
##D 
##D # # cqi_str2id and cqi_id2str
##D pid <- cqi_str2id("DICKENS.pos", "JJ")
##D cqi_id2str("DICKENS.pos", pid)
##D 
##D wid <- cqi_str2id("DICKENS.word", "easiest")
##D cqi_id2str("DICKENS.word", wid)
##D 
##D lid <- cqi_str2id("DICKENS.lemma", "easy")
##D cqi_id2str("DICKENS.lemma", lid)
##D 
##D # # cqi_id2freq
##D # Take the 20 first positions
##D cpos <- cqi_dump_subcorpus("DICKENS:Foo")[1:20,1]
##D 
##D pids <- unique(cqi_cpos2id("DICKENS.pos", cpos))
##D cqi_id2freq("DICKENS.pos", pids)
##D 
##D wids <- unique(cqi_cpos2id("DICKENS.word", cpos))
##D cqi_id2freq("DICKENS.word", wids)
##D 
##D lids <- unique(cqi_cpos2id("DICKENS.lemma", cpos))
##D cqi_id2freq("DICKENS.lemma", lids)
## End(Not run)



cleanEx()
nameEx("cqi_list_corpora")
### * cqi_list_corpora

flush(stderr()); flush(stdout())

### Name: cqi_list_corpora
### Title: List of available corpora
### Aliases: cqi_list_corpora
### Keywords: corpus, registry

### ** Examples

## Not run: 
##D cqi_list_corpora()
## End(Not run)



cleanEx()
nameEx("cqi_list_subcorpora")
### * cqi_list_subcorpora

flush(stderr()); flush(stdout())

### Name: cqi_list_subcorpora
### Title: List of currently defined subcorpora
### Aliases: cqi_list_subcorpora
### Keywords: corpus, subcorpus

### ** Examples

## Not run: 
##D cqi_query("DICKENS","Foo","\"interesting\"")
##D # The returned string should contain at least "Last" and "Foo"
##D cqi_list_subcorpora("DICKENS")
## End(Not run)



cleanEx()
nameEx("cqi_query")
### * cqi_query

flush(stderr()); flush(stdout())

### Name: cqi_query
### Title: Query an indexed corpus
### Aliases: cqi_query
### Keywords: corpus, query

### ** Examples


## Not run: 
##D cqi_query("DICKENS","Foo","\"eas(y|ier|iest)\";")
##D cqi_dump_subcorpus("DICKENS:Foo",0,10)
##D cqi_drop_subcorpus("DICKENS:Foo")
##D 
##D cqi_query("DICKENS","Go","[lemma=\"go\"] \"and\" [];")
##D cqi_dump_subcorpus("DICKENS:Go",0,10)
##D cqi_drop_subcorpus("DICKENS:Go")
##D 
##D cqi_query("DICKENS","NP","[pos=\"DT\"] @[pos=\"JJ\"]? [pos=\"NNS?\"];")
##D cqi_dump_subcorpus("DICKENS:NP",0,10)
##D cqi_drop_subcorpus("DICKENS:NP")
## End(Not run)



cleanEx()
nameEx("cqi_regex2id")
### * cqi_regex2id

flush(stderr()); flush(stdout())

### Name: cqi_regex2id
### Title: Find IDs by regular expression
### Aliases: cqi_regex2id
### Keywords: corpus position

### ** Examples


## Not run: 
##D rgx <- "eas(y|ier|iest)"
##D wids <- cqi_regex2id("DICKENS.word", rgx)
##D cqi_id2str("DICKENS.word", wids)
##D 
##D rgx <- "V.*"
##D pids <- cqi_regex2id("DICKENS.pos", rgx)
##D cqi_id2str("DICKENS.pos", pids)
##D 
##D rgx <- "V[aeiou].+e"
##D lids <- cqi_regex2id("DICKENS.lemma", rgx)
##D cqi_id2str("DICKENS.lemma", lids)
## End(Not run)



cleanEx()
nameEx("cqi_struc2cpos")
### * cqi_struc2cpos

flush(stderr()); flush(stdout())

### Name: cqi_struc2cpos
### Title: Convert structural indices
### Aliases: cqi_struc2cpos cqi_struc2str
### Keywords: corpus position

### ** Examples


## Not run: 
##D for (i in 0:10) {
##D 	print(cqi_struc2cpos("DICKENS.novel", i))
##D }
##D 
##D cqi_struc2str("DICKENS.novel_title", 1:10)
##D cqi_struc2str("DICKENS.chapter_title", 1:10)
## End(Not run)



cleanEx()
nameEx("cqp_flist")
### * cqp_flist

flush(stderr()); flush(stdout())

### Name: cqp_flist
### Title: Create a frequency list
### Aliases: cqp_flist cqp_flist.cqp_attr cqp_flist.cqp_corpus
###   cqp_flist.cqp_subcorpus

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D fl <- cqp_flist(c, "word");
##D 
##D sc <- subcorpus(c, '"interesting" "to" @ []');
##D fl <- cqp_flist(sc, "target", "word");
##D 
##D sc <- subcorpus(c, '"interesting"');
##D fl <- cqp_flist(sc, "target", "lemma", left.context = 10, right.context = 10, cutoff = 5)
## End(Not run)



cleanEx()
nameEx("cqp_registry")
### * cqp_registry

flush(stderr()); flush(stdout())

### Name: cqp_registry
### Title: The CQP registry
### Aliases: cqp_registry
### Keywords: registry

### ** Examples

Sys.setenv(CORPUS_REGISTRY="/users/vhugo/cwb/registry")



cleanEx()
nameEx("print")
### * print

flush(stderr()); flush(stdout())

### Name: print.cqp_flist
### Title: Print a CWB object
### Aliases: print.cqp_flist print.cqp_subcorpus print.cqp_corpus
###   print.cqp_kwic print.cqp_attr

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D c;
##D 
##D sc <- subcorpus(c, '"interesting"');
##D sc;
##D 
##D k <- cqp_kwic(sc);
##D k;
##D 
##D fl <- cqp_flist(c, "word");
##D fl;
##D 
## End(Not run)



cleanEx()
nameEx("region_sizes")
### * region_sizes

flush(stderr()); flush(stdout())

### Name: region_sizes
### Title: Size of regions of a structural attribute.
### Aliases: region_sizes region_sizes.cqp_attr

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D s <- region_sizes(c$pos);
## End(Not run)



cleanEx()
nameEx("size")
### * size

flush(stderr()); flush(stdout())

### Name: size
### Title: Size of a corpus or subcorpus
### Aliases: size size.cqp_corpus size.cqp_subcorpus

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D size(c);
##D 
##D sc <- subcorpus(c, '"interesting"');
##D size(sc);
## End(Not run)



cleanEx()
nameEx("sort.cqp_kwic")
### * sort.cqp_kwic

flush(stderr()); flush(stdout())

### Name: sort.cqp_kwic
### Title: Sort a kwic list
### Aliases: sort.cqp_kwic

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D sc <- subcorpus("DICKENS", "interesting");
##D kwic <- cqp_kwic <- (sc);
##D kwic <- sort(kwic)
##D print(kwic);
## End(Not run)



cleanEx()
nameEx("subcorpus")
### * subcorpus

flush(stderr()); flush(stdout())

### Name: subcorpus
### Title: Create a subcorpus.
### Aliases: subcorpus

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D sc <- subcorpus("DICKENS", "interesting");
## End(Not run)



cleanEx()
nameEx("summary")
### * summary

flush(stderr()); flush(stdout())

### Name: summary.cqp_flist
### Title: Print summary for CWB objects.
### Aliases: summary.cqp_flist summary.cqp_corpus summary.cqp_subcorpus
###   summary.cqp_attr

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D c;
##D 
##D sc <- subcorpus(c, '"interesting"');
##D sc;
##D 
##D k <- cqp_kwic(sc);
##D k;
##D 
##D fl <- cqp_flist(c, "word");
##D fl;
## End(Not run)



cleanEx()
nameEx("tokens")
### * tokens

flush(stderr()); flush(stdout())

### Name: Type and token
### Title: Print values of cqp attribute
### Aliases: ntype types nregion regions ntoken tokens ntype.cqp_attr
###   types.cqp_attr nregion.cqp_attr regions.cqp_attr ntoken.cqp_attr
###   tokens.cqp_attr

### ** Examples

## Not run: 
##D c <- corpus("DICKENS");
##D pos <- c$pos
##D types(pos);
##D ntokens(types(pos));
## End(Not run)



### * <FOOTER>
###
cat("Time elapsed: ", proc.time() - get("ptime", pos = 'CheckExEnv'),"\n")
grDevices::dev.off()
###
### Local variables: ***
### mode: outline-minor ***
### outline-regexp: "\\(> \\)?### [*]+" ***
### End: ***
quit('no')
