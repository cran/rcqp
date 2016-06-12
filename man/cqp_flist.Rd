\name{cqp_flist}
\alias{cqp_flist}
\alias{cqp_flist.cqp_attr}
\alias{cqp_flist.cqp_corpus}
\alias{cqp_flist.cqp_subcorpus}

\title{
 Create a frequency list
}

\description{
 Create a frequency list on any phenomenon available in a CWB corpus: frequency of forms of a positional attribute, frequency of a value of a structural attribute, or frequency of forms found in an anchor (\emph{match, matchend, target, keyword}) of a subcorpus.
}

\usage{
cqp_flist(x, ...)

 \method{cqp_flist}{cqp_attr}(x, cutoff = 0, ...)
 
 \method{cqp_flist}{cqp_corpus}(x, attribute, cutoff = 0, ...)
 
 \method{cqp_flist}{cqp_subcorpus}(x, anchor, attribute, left.context = 0, 
        right.context = 0, cutoff = 0, offset = 0, ...)
}
%- maybe also 'usage' for other objects documented here.
\arguments{
  \item{x}{
An attribute, a corpus or a subcorpus object, created with the function \code{\link{corpus}} or \code{\link{subcorpus}}.
}
  \item{attribute}{
The attribute giving the modality to be counted. May be a structural attribute if \code{x} is a corpus.
}
  \item{anchor}{
Where to count the modality : on the \emph{match}, \emph{matchend}, \emph{target} or \emph{keyword} anchor of a subcorpus.
}
  \item{left.context}{
Consider also \emph{n} tokens on the left of the selected anchor for counting frequencies.
}
  \item{right.context}{
Consider also \emph{n} tokens on the right of the selected anchor for counting frequencies.
}
  \item{offset}{
Switch the anchor at \emph{n} tokens from the left (if negative) or to the right of the anchor given above.
}
  \item{cutoff}{
Keep only frequencies above this cutoff. If \code{cutoff} is 0, keep all forms. If \code{cutoff} is between 0 and 1 (exclusive), the \code{(cutoff * 100) }\% more frequent forms are kept.
}
  \item{...}{
Ignored.
}
}

\value{
Returns a named numeric vector.
}

\references{
  \url{http://cwb.sourceforge.net/documentation.php}
}

\author{
	Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
	Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\seealso{
\code{\link{cqp_ftable}}, 
\code{\link{cqp_kwic}}, 
\code{\link{subcorpus}}, 
\code{\link{corpus}}.
}

\examples{
\dontrun{
c <- corpus("DICKENS");
fl <- cqp_flist(c, "word");

sc <- subcorpus(c, '"interesting" "to" @ []');
fl <- cqp_flist(sc, "target", "word");

sc <- subcorpus(c, '"interesting"');
fl <- cqp_flist(sc, "target", "lemma", left.context = 10, right.context = 10, cutoff = 5)
}
}
