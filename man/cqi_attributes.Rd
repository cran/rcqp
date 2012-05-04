\name{cqi_attributes}
\alias{cqi_attributes}

\title{List the available attributes}

\description{
	Get the list of the currently defined attributes in a given corpus.
}

\usage{
	cqi_attributes(corpus, type)
}

\arguments{
	\item{corpus}{(\emph{string}) the name of the corpus (in uppercase letters).}
	\item{type}{(\emph{character}) a character designating a type of attributes. Possible values are "a" for alignment attributes, "p" for positional attributes and "s" for structural attributes.}
}

\details{
	For a specified corpus, this function lists the names of the different
	kinds of attributes used for the indexation. There are three kinds of
	attributes: positional, structural and alignment attributes (for
	aligned corpora).
}

\value{
	\code{cqi_attributes} returns a list of strings which are the names of
	the requested attributes.
    
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
\code{\link{cqi_attribute_size}}, 
\code{\link{cqi_structural_attribute_has_values}}.
}

\examples{
\dontrun{
cqi_attributes("DICKENS", "p")
cqi_attributes("DICKENS", "s")
cqi_attributes("DICKENS", "a")
}
}

\keyword{corpus, attributes}