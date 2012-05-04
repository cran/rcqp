\name{Extraction}
\alias{$.cqp_corpus}
\alias{[[.cqp_corpus}
\docType{data}
\title{
Extracting/addressing an attribute from a corpus.
}
\description{
Create a 'cqp_attr' S3 object, holding a cqp attribute (structural or positional).
}
\usage{
\method{[[}{cqp_corpus}(i, j, ...)
\method{$}{cqp_corpus}(x, name)
}

\arguments{
  \item{i}{ The name of an attribute }
  \item{j}{ Ignored }
  \item{x}{ an rcq_corpus object }
  \item{name}{ an attribute name }
  \item{...}{ Ignored }
}

\references{                                                                    
  \url{http://cwb.sourceforge.net/documentation.php}                            
} 
\author{                                                                        
        Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
        Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\keyword{cqp_attr}
