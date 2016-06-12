\name{cqp_ftable}
\alias{cqp_ftable}
\alias{cqp_ftable.cqp_corpus}
\alias{cqp_ftable.cqp_subcorpus}

\title{
Create a frequency table
}

\description{
Create a frequency table either with a corpus or with a subcorpus. With a corpus, a frequency table is a based on two attributes (structural or positional). With a subcorpus object, a frequency table is based on two anchors (\emph{match, matchend, target, keyword}) and a positional attribute for each anchor.
}

\usage{
cqp_ftable(x, ...)

 \method{cqp_ftable}{cqp_corpus}(x, attribute1, attribute2, attribute1.use.id = FALSE, 
        attribute2.use.id = FALSE, structural.attribute.unique.id = FALSE, 
		subcorpus = NULL, ...)
 
 \method{cqp_ftable}{cqp_subcorpus}(x, anchor1, attribute1, 
        anchor2, attribute2, cutoff = 0, ...)
}

\arguments{
  \item{x}{
An rcqp object, created with \code{\link{corpus}} or \code{\link{subcorpus}}.
}
  \item{attribute1}{
The attribute for the modalities of the first variable of the cross-tabulation. If \code{x} is a subcorpus, positional attribute only.
}
  \item{attribute2}{
The attribute for the modalities of the second variable of the cross-tabulation. If \code{x} is a subcorpus, positional attribute only.
}
  \item{attribute1.use.id}{
If \code{attribute1} is a structural attribute and has values (see \code{\link{cqi_structural_attribute_has_values}}), switch between region ids (struc) and values (default).
}
  \item{attribute2.use.id}{
If attribute2 is a structural attribute and has values (see \code{\link{cqi_structural_attribute_has_values}}), switch between region ids (struc) and values (default).
}
  \item{structural.attribute.unique.id}{
Count tokens or ids. See details for more info.
}
  \item{subcorpus}{
Not implemented yet.
}

  \item{anchor1}{
The anchor for individuals of the first variable, if \code{x} is a subcorpus (anchor may be : \emph{match, matchend, target, keyword}).
}
  \item{anchor2}{
The anchor for individuals of the second variable, if \code{x} is a subcorpus (anchor may be : \emph{match, matchend, target, keyword}).
}
  \item{cutoff}{
Filter the frequency table.
}
  \item{...}{
Ignored.
}

}
\details{
Some explanations for the \code{structural.attribute.unique.id} option (see the vignette \emph{RcqpIntroduction}).

Positional attributes (and structural attributes having values) are represented
with their string values rather than with ids. For positional
attributes, it is only a matter of presentation, since each id has its own
string; but for structural attributes having values, it may entail a different
counting, since these values are not unique: occurrences of phenomena belonging
to different structs are then counted together if two structs have the same
value. You can force the use of ids rather than string values with the
\code{attribute1.use.id} and \code{attribute2.use.id} options.

Counts are made on token basis, i.e. each token of the corpus is an
individual on which the two modalities (attributes) are considered. If you
use two structural attributes as arguments in \code{cqp_ftable},
and one of them does not have values, then the third column counts the number of
tokens. In the following example, each line gives
the length (in number of tokens, third column) of each sentence (second column)
in each novel represented by its title:

\preformatted{
c <- corpus("DICKENS");
f <- cqp_ftable(c, "novel_title", "s")
f[1:10,]
}

If both structural attributes have values, you may want to count the number of
times the modalities are cooccurring, rather than the total number of
tokens included in these cooccurrences. For that purpose, you can use the
\code{structural.attribute.unique.id=TRUE} option. In the following
example, we count the number of time each head appears in each novel :

\preformatted{
f <- cqp_ftable(c, "novel_title", "pp_h", structural.attribute.unique.id=TRUE)
f[1:10,]
}

Here on the contrary, we count the total number of tokens in each
prepositional phrase having a given head :

\preformatted{
f <- cqp_ftable(c, "novel_title", "pp_h")
f[1:10,]
}

}

\value{
A frequency table stored as a flat (3-column) dataframe : for each observed
combination of modalities, the first column gives the modality in the first
variable, the second column the modality in the second variable, and the third
column the observed frequency of the cooccurrence.
}

\references{                                                                    
  \url{http://cwb.sourceforge.net/documentation.php}                            
} 

\author{                                                                        
        Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
        Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\seealso{
\code{\link{cqp_flist}}, 
\code{\link{cqp_kwic}}, 
\code{\link{subcorpus}}.
}

