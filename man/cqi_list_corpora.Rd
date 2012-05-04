\name{cqi_list_corpora}
\alias{cqi_list_corpora}

\title{List of available corpora}

\description{
	Obtain the names of the installed corpora.
}

\usage{
	cqi_list_corpora()
}

\details{
	The available corpora are referenced in the registry (which is a
	directory located by default in \file{/usr/local/share/cwb} on
	Unix-like systems). See \code{\link{cqp_registry}} to learn how
	to set the \emph{registry} directory. 
	
	The name of a corpus is always written in uppercase letters (with
	possibly underscores, dashes and digits).
}

\value{
	\code{cqi_list_corpora} returns a list of the available corpora as
	specified in the registry.
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
\code{\link{cqp_registry}}, 
\code{\link{cqi_full_name}}, 
\code{\link{cqi_list_subcorpora}}, 
\code{\link{cqi_query}}, 
\code{\link{cqi_attributes}}.\cr
\code{\link{subcorpus}}, 
\code{\link{corpus}}.
}

\examples{
\dontrun{
cqi_list_corpora()
}
}

\keyword{corpus, registry}
