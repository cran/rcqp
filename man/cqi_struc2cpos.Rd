\name{cqi_struc2cpos}
\alias{cqi_struc2cpos}
\alias{cqi_struc2str}

\title{Convert structural indices}

\description{
	Get the corpus positions or the string associated to a structural position.
}

\usage{
	cqi_struc2cpos(attribute, struc)
	cqi_struc2str(attribute, ids)
}

\arguments{
	\item{attribute}{(\emph{string}) the qualified name of an attribute.}
	\item{struc}{(\emph{integer}) }
	\item{ids}{(\emph{integer vector})}
}

\details{
	The structural attributes correspond to XML pairs of tags in the
	corpus. Matching pairs of XML start and end tags are encoded as token
	regions. The \emph{struc} parameter is the index of a particular pair
	of tags. The \code{cqi_struc2cpos} function associates the corpus
	positions of the specified pair. 
	
	}

\value{
	The \code{cqi_struc2cpos} function returns a pair of corpus positions:
	the corpus positions of the first token (immediately following the
	start tag) and of the last token (immediately preceding the end tag) of
	the token region.
	
	The \code{cqi_struc2str} function returns a string.
}

\author{
	Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
	Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\source{
	The IMS Open Corpus Workbench (CWB) at \url{http://cwb.sourceforge.net/}
}

\references{
	\url{http://cwb.sourceforge.net/documentation.php}
}

\seealso{
\code{\link{cqi_alg2cpos}}, 
\code{\link{cqi_cpos2alg}}, 
\code{\link{cqi_cpos2id}}, 
\code{\link{cqi_cpos2lbound}}, 
\code{\link{cqi_cpos2rbound}}, 
\code{\link{cqi_cpos2str}}, 
\code{\link{cqi_cpos2struc}}, 
\code{\link{cqi_id2cpos}}, 
\code{\link{cqi_id2freq}}, 
\code{\link{cqi_id2str}}, 
\code{\link{cqi_regex2id}}, 
\code{\link{cqi_str2id}}.
}

\examples{

\dontrun{
for (i in 0:10) {
	print(cqi_struc2cpos("DICKENS.novel", i))
}

cqi_struc2str("DICKENS.novel_title", 1:10)
cqi_struc2str("DICKENS.chapter_title", 1:10)
}
}

\keyword{corpus position}
