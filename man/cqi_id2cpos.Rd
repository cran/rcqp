\name{cqi_id2cpos}
\alias{cqi_id2cpos}
\alias{cqi_id2freq}
\alias{cqi_id2str}
\alias{cqi_str2id}

\title{Convert the ID of an item}

\description{
	Associate an item's ID to other parameters.
}

\usage{
	cqi_id2cpos(attribute, id)
	cqi_id2freq(attribute, ids)
	cqi_id2str(attribute, ids)
	cqi_str2id(attribute, strs)
}

\arguments{
	\item{attribute}{(\emph{string}) the qualified name of an attribute.}
	\item{id}{(\emph{integer}) a single value}
	\item{ids}{(\emph{integer vector}) }
	\item{strs}{(\emph{character vector}) }
}

\details{
	
	These functions take as argument the ID of a positional attribute item
	and associate corresponding parameters such as the corpus position, the
	frequency or the string it represents.
	
	The \code{cqi_str2id} function does the opposite: it associates the ID
	to a given positional parameter.
	
}

\value{
	The \code{cqi_id2cpos}, \code{cqi_id2freq}, \code{cqi_str2id} functions
	return an integer. The \code{cqi_id2str} function returns a string.
}

\author{
	Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
	Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\source{
	The IMS Open Corpus Workbench (CWB) at \url{http://cwb.sourceforge.net/}
}

\references{
	\url{http://cwb.sourceforge.net/documentation.php}
}

\seealso{
\code{\link{cqi_alg2cpos}}
\code{\link{cqi_cpos2alg}}, 
\code{\link{cqi_cpos2id}}, 
\code{\link{cqi_cpos2lbound}}, 
\code{\link{cqi_cpos2rbound}}, 
\code{\link{cqi_cpos2str}}, 
\code{\link{cqi_cpos2struc}}, 
\code{\link{cqi_regex2id}}, 
\code{\link{cqi_str2id}}, 
\code{\link{cqi_struc2cpos}}, 
\code{\link{cqi_struc2str}}.
}

\examples{
\dontrun{
cqi_query("DICKENS","Foo","\"eas(y|ier|iest)\";")
cpos <- cqi_dump_subcorpus("DICKENS:Foo")[1,1]

# # cqi_id2cpos
pids <- unique(cqi_cpos2id("DICKENS.pos", cpos))
ppos <- cqi_id2cpos("DICKENS.pos", pids[1])
ppos[1:50]

wids <- unique(cqi_cpos2id("DICKENS.word", cpos))
wpos <- cqi_id2cpos("DICKENS.word", wids[1])
wpos[1:50]

lids <- unique(cqi_cpos2id("DICKENS.lemma", cpos))
lpos <- cqi_id2cpos("DICKENS.lemma", lids[1])
lpos[1:50]

# # cqi_str2id and cqi_id2str
pid <- cqi_str2id("DICKENS.pos", "JJ")
cqi_id2str("DICKENS.pos", pid)

wid <- cqi_str2id("DICKENS.word", "easiest")
cqi_id2str("DICKENS.word", wid)

lid <- cqi_str2id("DICKENS.lemma", "easy")
cqi_id2str("DICKENS.lemma", lid)

# # cqi_id2freq
# Take the 20 first positions
cpos <- cqi_dump_subcorpus("DICKENS:Foo")[1:20,1]

pids <- unique(cqi_cpos2id("DICKENS.pos", cpos))
cqi_id2freq("DICKENS.pos", pids)

wids <- unique(cqi_cpos2id("DICKENS.word", cpos))
cqi_id2freq("DICKENS.word", wids)

lids <- unique(cqi_cpos2id("DICKENS.lemma", cpos))
cqi_id2freq("DICKENS.lemma", lids)
}
}

\keyword{corpus position}

