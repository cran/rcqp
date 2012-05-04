\name{cqi_regex2id}
\alias{cqi_regex2id}

\title{Find IDs by regular expression}

\description{
    Build a list of IDs of positional attributes whose names match a regular expression.
}

\usage{
	cqi_regex2id(attribute, regex)
}

\arguments{
	\item{attribute}{(\emph{\emph{string}}) the name of a positional attribute.}
	\item{regex}{(\emph{\emph{string}}) a regular expression.}
}

\details{
	This function looks in the index files corresponding to the specified
	positional attribute, finds the strings described by the regular
	expression and returns the associated indices.
}

\value{
	\code{cqi_regex2id} returns a list of integers.
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
\code{\link{cqi_str2id}}, 
\code{\link{cqi_struc2cpos}}, 
\code{\link{cqi_struc2str}}.
}

\examples{

\dontrun{
rgx <- "eas(y|ier|iest)"
wids <- cqi_regex2id("DICKENS.word", rgx)
cqi_id2str("DICKENS.word", wids)

rgx <- "V.*"
pids <- cqi_regex2id("DICKENS.pos", rgx)
cqi_id2str("DICKENS.pos", pids)

rgx <- "V[aeiou].+e"
lids <- cqi_regex2id("DICKENS.lemma", rgx)
cqi_id2str("DICKENS.lemma", lids)
}
}

\keyword{corpus position}