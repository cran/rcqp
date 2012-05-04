\name{write.cqp_corpus}
\alias{write.cqp_corpus}

\title{
Save a CWB corpus in a file in tabular representation
}

\description{
Save a CWB corpus in a file as a dataframe where each column represents an attribute (positional or structural).
}

\usage{
 \method{write}{cqp_corpus}(corpus, filename, from = 0, to = 1000, ...)
}

\arguments{
  \item{corpus}{
An object created with \code{\link{corpus}}.
}
  \item{filename}{
The file to be used.
}
  \item{from}{
First token to save (token \emph{cpos} of the first line of the dataframe).
}
  \item{to}{
Last token to save (token \emph{cpos} of the last line of the dataframe).
}
  \item{\dots}{
Not used.
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
\code{\link{print.cqp_corpus}}, 
\code{\link{summary.cqp_corpus}}.
}
