\name{Type and token}
\alias{ntype}
\alias{types}
\alias{nregion}
\alias{regions}
\alias{ntoken}
\alias{tokens}
\alias{ntype.cqp_attr}
\alias{types.cqp_attr}
\alias{nregion.cqp_attr}
\alias{regions.cqp_attr}
\alias{ntoken.cqp_attr}
\alias{tokens.cqp_attr}

\title{
Print values of cqp attribute
}
\description{
Get vectors of tokens or types for a cqp attribute.
}
\usage{

ntype(attribute, ...)

types(attribute, ...)

nregion(attribute, ...)

regions(attribute, ...)

ntoken(attribute, ...)

tokens(attribute, ...)

 \method{ntype}{cqp_attr}(attribute, ...)
 \method{types}{cqp_attr}(attribute, ...)
 \method{nregion}{cqp_attr}(attribute, ...)
 \method{regions}{cqp_attr}(attribute, ...)
 \method{ntoken}{cqp_attr}(attribute, ...)
 \method{tokens}{cqp_attr}(attribute, ...)

}

\arguments{
  \item{attribute}{
    A \code{cqp_attr} object, created with \code{\link{$.cqp_corpus}}.
  }
  \item{...}{
    Ignored.
  }
}

\value{                                                                    
  For positional attributes :
  \itemize{
    \item ntoken is the number of tokens (== size(corpus))
    \item tokens is a character vector with the actual list of tokens
    \item ntype is the number of different values
    \item types is a character vector with the actual different values
  }
  For structural attributes :
  \itemize{
    \item nregion is the actual number of regions (a numeric vector of length 1)
    \item tokens the region id ("struc") of each token (a numeric vector)
	\item regions (only if the structural attribute "has values") : the values found on each region (a character vector)
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
\code{\link{$.cqp_corpus}}.
}

\examples{
\dontrun{
c <- corpus("DICKENS");
pos <- c$pos
types(pos);
ntokens(types(pos));
}
}
