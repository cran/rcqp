\name{cqi_dump_subcorpus}
\alias{cqi_dump_subcorpus}
\alias{cqi_subcorpus_size}
\alias{cqi_drop_subcorpus}

\title{Handle subcorpora}

\description{
	Get size and corpus positions corresponding to the results of a query. 
}

\usage{
	cqi_dump_subcorpus(subcorpus, first=0, last=cqi_subcorpus_size(subcorpus)-1)
	cqi_subcorpus_size(subcorpus)
	cqi_drop_subcorpus(subcorpus)
}

\arguments{
	\item{subcorpus}{(\emph{string}) qualified name of a subcorpus.}
	\item{first}{(\emph{integer}) first index. Optional: default is 0.}
	\item{last}{(\emph{integer}) last index. Optional: default is \code{size-1}.}
}

\details{
	A subcorpus is typically the result of a previous query (see the
	\link{cqi_query} function). The qualified name of the subcorpus is of
	the form \code{name_of_corpus:name_of_subcorpus}, for instance
	\emph{"DICKENS:A"}. The name of the subcorpus is declared in the second
	argument of the \link{cqi_query} function.

	The \code{cqi_dump_subcorpus} function builds a two-dimension array (a
	matrix) of corpus positions corresponding to the results of a query.

	The \code{cqi_drop_subcorpus} function frees the memory allocated to a
	subcorpus.

}

\value{
	\code{cqi_subcorpus_size} returns an integer which is the number of
	matches in the specified subcorpus.

	\code{cqi_dump_subcorpus} returns a matrix with four columns corresponding to the
	\emph{match}, \emph{matchend}, \emph{target}, and \emph{keyword} fields
	respectively. Each row corresponds to a query match. The number of rows
	is \code{last-first+1}. This is the size of the subcorpus if the
	\code{first} and \code{last} arguments are not specified.
	
	\code{cqi_drop_subcorpus} does not return anything.
	
	}

\author{
	Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
	Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\references{
	\url{http://cwb.sourceforge.net/documentation.php}
}

\seealso{
\code{\link{cqi_query}}, 
\code{\link{cqi_list_corpora}}, 
\code{\link{cqi_list_subcorpora}}.
}

\examples{
\dontrun{
cqi_query("DICKENS","Foo","\"interesting\";")
cqi_subcorpus_size("DICKENS:Foo")
cqi_dump_subcorpus("DICKENS:Foo")
cqi_dump_subcorpus("DICKENS:Foo",4,10)
}
}

\keyword{subcorpus, indices}