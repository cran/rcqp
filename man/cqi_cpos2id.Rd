\name{cqi_cpos2id}
\alias{cqi_cpos2id}
\alias{cqi_cpos2lbound}
\alias{cqi_cpos2rbound}
\alias{cqi_cpos2str}
\alias{cqi_cpos2alg}
\alias{cqi_cpos2struc}
\alias{cqi_alg2cpos}

\title{Convert a corpus position}

\description{
	Associate a corpus position to other parameters.
}

\usage{
	cqi_cpos2id(attribute, cpos)
	cqi_cpos2lbound(attribute, cpos)
	cqi_cpos2rbound(attribute, cpos)
	cqi_cpos2str(attribute, cpos)
	cqi_cpos2alg(attribute, cpos)
	cqi_cpos2struc(attribute, cpos)
	cqi_alg2cpos(attribute, alg)

}

\arguments{
	\item{attribute}{(\emph{string}) the qualified name of an attribute.}
	\item{cpos}{(\emph{integer vector}) a list of corpus positions}
	\item{alg}{(\emph{integer}) an alignment ID}
}

\details{
	The \code{cqi_cpos2id} and \code{cqi_cpos2str} functions apply to
	positional attributes.

	The \code{cqi_cpos2lbound}, \code{cqi_cpos2rbound} and
	\code{cqi_cpos2struc} functions apply to structural attributes.

	The \code{cqi_alg2cpos} function applies to alignment attributes (in
	the case of aligned corpora).
}

\value{
	\code{cqi_cpos2str} returns a vector of strings.

	The \code{cqi_alg2cpos} function returns a 4-elements vector
	representing the start and end positions of an alignment in the source
	corpus and the start and end positions in the target corpus.
	
	The other functions return a vector of integers representing corpus
	positions.

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
\code{\link{cqi_id2cpos}}, 
\code{\link{cqi_id2freq}}, 
\code{\link{cqi_id2str}}, 
\code{\link{cqi_regex2id}}, 
\code{\link{cqi_str2id}}, 
\code{\link{cqi_struc2cpos}}, 
\code{\link{cqi_struc2str}}.
}

\examples{
\dontrun{
cqi_query("DICKENS","Foo","\"eas(y|ier|iest)\";")
cpos <- cqi_dump_subcorpus("DICKENS:Foo")[1:20,1]

cqi_cpos2id("DICKENS.pos", cpos)
cqi_cpos2str("DICKENS.pos", cpos)
cqi_cpos2id("DICKENS.word", cpos)
cqi_cpos2str("DICKENS.word", cpos)
cqi_cpos2id("DICKENS.lemma", cpos)
cqi_cpos2str("DICKENS.lemma", cpos)

cqi_query("DICKENS","Foo","\"interesting\";")
cpos <- cqi_dump_subcorpus("DICKENS:Foo",1,10)[,1]

# Expects structural attributes
cqi_cpos2lbound("DICKENS.chapter", cpos)
cqi_cpos2rbound("DICKENS.chapter", cpos)

cqi_cpos2struc("DICKENS.chapter", cpos)
}
}

\keyword{corpus positions}

