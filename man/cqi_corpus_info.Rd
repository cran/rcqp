\name{cqi_corpus_info}
\alias{cqi_corpus_info}
\title{Info about a corpus}
\description{
Print info about all cwb files for a corpus
}
\usage{
cqi_corpus_info(corpus)
}
\arguments{
  \item{corpus}{
The name of a corpus (in uppercase letters).
}
}
\value{NULL}
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

\examples{
\dontrun{
cqi_corpus_info("DICKENS")
}
}