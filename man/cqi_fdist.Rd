\name{cqi_fdist}
\alias{cqi_fdist}
\alias{cqi_fdist1}
\alias{cqi_fdist2}

\title{Frequency distributions}

\description{
	Calculate a frequency list or a cross-tabulated frequency table. 
}

\usage{
	cqi_fdist1(subcorpus, field1, key1, cutoff=0, offset=0)
	cqi_fdist2(subcorpus, field1, key1, field2, key2, cutoff=0)
}

\arguments{
	\item{subcorpus}{(\emph{string}) qualified name of a subcorpus.}
	\item{field1}{(\emph{string}) the name of the anchor. It can be one of : \emph{'match'}, \emph{'matchend'}, \emph{'target'}, \emph{'keyword'}.}
	\item{key1}{(\emph{string}) the name of a positional attribute.}
	\item{field2}{(\emph{string}) the name of a second anchor. It can be one of : \emph{'match'}, \emph{'matchend'}, \emph{'target'}, \emph{'keyword'}.}
	\item{key2}{(\emph{string}) the name of a positional attribute for the second anchor.}
	\item{cutoff}{(\emph{integer}) a floor value under which results are not displayed. Default value is 0.}
	\item{offset}{(\emph{integer}) an offset relative to the specified anchor.}
}

\details{

	\code{cqi_fdist1} builds a frequency list given individuals (occurrences)
        and modalities (a positional attribute).
	
	The occurrences are defined by providing one of the anchors of
        a query (\emph{'match'}, \emph{'matchend'}, \emph{'target'}, 
        \emph{'keyword'}).

	The results are sorted in decreasing order of frequency. The \code{cut}
	argument specifies a value under which the results will not be
	returned. For instance, if the value is set to 10, only items with a
	frequency greater than or equal to 10 are returned. The default value
	of this argument is 0 which means that all the frequencies are returned
	by default.
	
	The \code{offset} argument lets specify a position relative to the
	anchor specified by the \code{field} argument. For instance, if
	\code{field} is set to \emph{'match'} and offset is equal to -1, the
	frequency list is computed on all the tokens located before the match
	anchor. The default value of this argument is 0.

	\code{cqi_fdist2} builds a frequency table of the values found
        in one anchor (such as \emph{'match'}, \emph{'matchend'},
        \emph{'target'}, \emph{'keyword'}) cross-tabulated with the
        values found in another anchor. In other words, it gives
        the frequency of every different co-occurrences found according
        to the two given anchors.

}

\value{
	\code{cqi_fdist1} returns a matrix with two columns. The first column
	contains the IDs of the attributes and the second column the
	corresponding frequency (number of occurrences).

	\code{cqi_fdist2} returns a matrix with three columns. The first column
contains the IDs of an attribute of the occurrences found at the first anchor,
the second column contains the IDs of an attribute of the occurrences found in
the second anchor and the third column gives the frequency of the co-occurrences.

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
\code{\link{cqi_list_subcorpora}}, 
\code{\link{cqi_dump_subcorpus}}.
}

\examples{
\dontrun{
cqi_query("DICKENS","Go","[lemma=\"go\"] \"and\" [];")
m <- cqi_fdist1("DICKENS:Go","matchend","pos")
cqi_id2str("DICKENS.pos", m[,1])

cqi_query("DICKENS","NP","[pos=\"DT\"] @[pos=\"JJ\"]? [pos=\"NNS?\"];")
cqi_fdist1("DICKENS:NP","target","lemma",300)
cqi_fdist1("DICKENS:NP","match","lemma", cutoff=2000, offset=-1)

cqi_fdist2("DICKENS:Go","matchend", "pos", "matchend","lemma")
cqi_fdist2("DICKENS:NP","target", "lemma", "matchend","word", cutoff=300)
}
}

\keyword{frequency}
