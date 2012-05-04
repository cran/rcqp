\name{cqp_kwic}
\alias{cqp_kwic}
\alias{cqp_kwic.cqp_subcorpus}
%- Also NEED an '\alias' for EACH other topic documented here.
\title{
Create a "keyword in context" list with a subcorpus.
}
\description{
Create a "keyword in context" (aka \emph{kwic}) list with a subcorpus, with parameters for
arranging and filtering items. The list can then be printed chunk by chunk.
}
\usage{
cqp_kwic(x, ...)

 \method{cqp_kwic}{cqp_subcorpus}(x, right.context = 20, left.context = 20, ...)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
An object created with \code{\link{subcorpus}}.
}
  \item{right.context}{
The number of characters on the right.
}
  \item{left.context}{
The number of characters on the left.
}
  \item{...}{
Ignored.
}

}

\value{
Create a \code{cqp_kwic} object ready to be printed (with more options for the display) with \code{print} (see \code{\link{print.cqp_kwic}}).
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
\code{\link{print.cqp_kwic}}
\code{\link{write.cqp_corpus}}.
}
