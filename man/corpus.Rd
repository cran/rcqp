\name{corpus}
\alias{corpus}

\title{
Create a corpus object
}
\description{
Create a corpus object wrapping a CWB corpus object.
}
\usage{
corpus(corpus.name)
}

\arguments{
  \item{corpus.name}{
The name of a corpus in the CWB registry (must be uppercase).
}
}

\value{
A corpus object.
}

\references{                                                                    
  \url{http://cwb.sourceforge.net/documentation.php}                            
} 
\author{                                                                        
        Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
        Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\seealso{
\code{\link{subcorpus}}, 
\code{\link{print.cqp_corpus}}, 
\code{\link{summary.cqp_corpus}}, 
\code{\link{write.cqp_corpus}}, 
\code{\link{cqp_kwic}}.
}

\examples{
\dontrun{
c <- corpus("DICKENS");
}
}
