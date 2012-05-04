\name{cqi_attribute_size}
\alias{cqi_attribute_size}
\alias{cqi_structural_attribute_has_values}
\alias{cqi_lexicon_size}

\title{Get the size of an attribute}

\description{

	Find the number of items (type/category or token/individual) of an
attribute.

}

\usage{
	cqi_attribute_size(attribute)
	cqi_structural_attribute_has_values(attribute)
	cqi_lexicon_size(attribute)
}	

\arguments{
	\item{attribute}{(\emph{string}) the qualified name of an attribute.}
}

\details{

	The \code{cqi_attribute_size} indicates the number of actual elements
        (number of occurrences) of an attributes:
\itemize{
	\item on a positionnal attribute, it gives the number of tokens.
	\item on a structural attribute, it gives the number of regions.
	\item on an alignment attribute, it gives the number of aligned pairs.
}

	The \code{cqi_lexicon_size} function indicates the number of different
values of a positional attribute (number of types, or categories). It applies only to positional attributes. 

	The \code{cqi_structural_attribute_has_values} indicates if the
specified attribute does have values. This concerns only the structural
attributes. Positional attributes always have values.  In order to get the
value of a positionnal attribute with value, consider using
\link{cqi_struc2str}.

	The \code{attribute} argument is the qualified name of an attribute.
	This concerns any kind of attribute. The syntax is of the form
	\code{name_of_corpus.name_of_attribute}. For instance
	\emph{"DICKENS.lemma"} (positional attribute) or
	\emph{"DICKENS.chapter"} (structural attribute).
	
}

\value{
	\code{cqi_attribute_size} returns an integer which is the number of
	different items in the corpus marked with the specified attribute.

	\code{cqi_structural_attribute_has_values} returns a logical value
	telling whether the specified attribute has values (\code{TRUE}) or not
	(\code{FALSE}).

	\code{cqi_lexicon_size} returns an integer value.
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
\link{cqi_attributes}, \link{cqi_struc2str}.
}

\examples{
\dontrun{
cqi_structural_attribute_has_values("DICKENS.file")
cqi_structural_attribute_has_values("DICKENS.file_name")
cqi_structural_attribute_has_values("DICKENS.chapter")
cqi_structural_attribute_has_values("DICKENS.chapter_title")

cqi_lexicon_size("DICKENS.lemma")
cqi_lexicon_size("DICKENS.pos")
cqi_lexicon_size("DICKENS.word")

# Positional attribute
cqi_attribute_size("DICKENS.lemma")
cqi_attribute_size("DICKENS.pos")
cqi_attribute_size("DICKENS.word")

# Structural attributes
cqi_attribute_size("DICKENS.book")
cqi_attribute_size("DICKENS.file")
cqi_attribute_size("DICKENS.chapter")
}
}

\keyword{attribute}
