\name{sort.cqp_kwic}
\alias{sort.cqp_kwic}

\title{
Sort a kwic list
}
\description{
Sort a kwic list with respect to an anchor and a positional attribute.
}
\usage{
 \method{sort}{cqp_kwic}(x, decreasing = FALSE, sort.anchor = "match", 
        sort.attribute = "word", sort.offset = 0, ...)
}

\arguments{
  \item{x}{
A \code{cqp_kwic} object.
}
  \item{decreasing}{
Reverse order.
}
  \item{sort.anchor}{
The anchor (\emph{match, matchend, target, keyword}) to be used as sorting key.
}
  \item{sort.attribute}{
The attribute (such as \emph{word}, \emph{lemma}\dots according to the available attributes in a given corpus) for sorting the lines of the concordance.
}
  \item{sort.offset}{
Sort on the selected anchor, or \emph{n} tokens before or after it.
}
  \item{\dots}{
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
\code{\link{cqp_kwic}}, 
\code{\link{print.cqp_kwic}}.
}

\examples{
\dontrun{
c <- corpus("DICKENS");
sc <- subcorpus("DICKENS", "interesting");
kwic <- cqp_kwic <- (sc);
kwic <- sort(kwic)
print(kwic);
}
}
