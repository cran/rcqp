\name{cqi_list_subcorpora}
\alias{cqi_list_subcorpora}

\title{List of currently defined subcorpora}

\description{
	Get a list of the currently defined subcorpora in a given corpus.
}

\usage{
	cqi_list_subcorpora(corpus)
}

\arguments{
	\item{corpus}{(\emph{string}) the name of the parent corpus (in uppercase letters).}
}

\details{
	This function returns a list of all the named subcorpora currently
	defined. A subcorpus is the result of a query and its name is typically
	declared in the second argument of the \link{cqi_query} function.
}

\value{
	\code{cqi_list_subcorpora} returns a list of the existing subcorpora in
	the specified corpus.
}

\author{
	Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
	Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\source{
	The IMS Open Corpus Workbench (CWB) at \url{http://cwb.sourceforge.net/}
}

\seealso{
\code{\link{cqi_list_corpora}}, 
\code{\link{cqi_query}}, 
\code{\link{cqi_subcorpus_size}}, 
\code{\link{cqi_attributes}}, 
\code{\link{cqi_fdist}}.\cr
\code{\link{subcorpus}}, 
\code{\link{corpus}}.
}

\examples{
\dontrun{
cqi_query("DICKENS","Foo","\"interesting\"")
# The returned string should contain at least "Last" and "Foo"
cqi_list_subcorpora("DICKENS")
}
}

\keyword{corpus, subcorpus}