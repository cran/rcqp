\name{subcorpus}
\alias{subcorpus}

\title{
Create a subcorpus.
}

\description{
Create a subcorpus held in the CWB library.
}

\usage{
subcorpus(corpus, query)
}
%- maybe also 'usage' for other objects documented here.

\arguments{
  \item{corpus}{
An \code{rcqp} object created with \code{\link{corpus}}.
}
  \item{query}{
A CQP query.
}
}

\details{
The \emph{subcorpus} function creates internally a subcorpus name for the CWB library.
}

\value{
A subcorpus object.
}

\references{                                                                    
  \url{http://cwb.sourceforge.net/documentation.php}                            
} 

\author{                                                                        
        Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
        Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\seealso{
\code{\link{corpus}}, 
\code{\link{cqp_flist}}, 
\code{\link{print.cqp_subcorpus}}, 
\code{\link{summary.cqp_subcorpus}}, 
\code{\link{cqp_ftable}}, 
\code{\link{cqp_kwic}}.
}

\examples{
\dontrun{
c <- corpus("DICKENS");
sc <- subcorpus("DICKENS", "interesting");
}
}
