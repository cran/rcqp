\name{summary.cqp_flist}
\alias{summary.cqp_flist}
\alias{summary.cqp_corpus}
\alias{summary.cqp_subcorpus}
\alias{summary.cqp_attr}

\title{
Print summary for CWB objects.
}
\description{
Print a summary for a corpus, a subcorpus, or a frequency list.
}
\usage{

 \method{summary}{cqp_flist}(object, ...)

 \method{summary}{cqp_corpus}(object, ...)

 \method{summary}{cqp_subcorpus}(object, ...)

 \method{summary}{cqp_attr}(object, ...)
}

\arguments{
  \item{object}{
An \code{rcqp} object, created with \code{\link{cqp_flist}}, \code{\link{corpus}}, \code{\link{subcorpus}}, or \code{\link{$.cqp_corpus}}.
}
  \item{...}{
Ignored.
}

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
\code{\link{subcorpus}}, 
\code{\link{write.cqp_corpus}}, 
\code{\link{size.cqp_corpus}}, 
\code{\link{size.cqp_subcorpus}}, 
\code{\link{cqp_kwic}}.
}

\examples{
\dontrun{
c <- corpus("DICKENS");
c;

sc <- subcorpus(c, '"interesting"');
sc;

k <- cqp_kwic(sc);
k;

fl <- cqp_flist(c, "word");
fl;
}
}
