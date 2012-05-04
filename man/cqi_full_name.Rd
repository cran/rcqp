\name{cqi_full_name}
\alias{cqi_full_name}

\title{Full name of a corpus}

\description{
	Get the descriptive string of a given corpus.
}

\usage{
	cqi_full_name(corpus)
}

\arguments{
	\item{corpus}{(\emph{string}) the name of a corpus (in uppercase letters).}
}

\details{
	The descriptive string of a corpus is specified in the NAME parameter
	of the corpus declaration in the registry.
}

\value{
	A string.
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
\code{\link{cqi_list_corpora}}.
}

\examples{
\dontrun{
cqi_full_name("DICKENS")
}
}

\keyword{corpus}