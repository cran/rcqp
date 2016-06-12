\name{rcqp}
\alias{rcqp}
\alias{rcqp-package}

%- Also NEED an '\alias' for EACH other topic documented here.
\title{~ Corpus Query Protocol ~}
\description{
  \tabular{ll}{
    Package: \tab rcqp\cr
    Type: \tab Package\cr
    Version: \tab \Sexpr[stage=render]{library(utils);packageVersion("rcqp")}\cr
    Date: \tab \Sexpr[stage=build]{format(Sys.time(),"\%Y-\%m-\%d")}\cr
    License: \tab \Sexpr[stage=build]{library(utils);packageDescription("rcqp")$License} \cr
  }
}

\details{
	\code{rcqp} is an implementation in R of the Corpus Query Protocol.
  
	See the \code{\link{cqp_registry}} help page or type
	\code{?cqp_registry} from the R console to see how to set the
	"\emph{registry}" directory.
	
}

\section{Author}{
	Bernard Desgraupes - \email{bernard.desgraupes@u-paris10.fr} - University Paris-10.\cr
	Sylvain Loiseau - \email{sylvain.loiseau@univ-paris13.fr} - University Paris-13.\cr
}

\references{
\itemize{
	\item \emph{CQP Query Language Tutorial}: \url{http://cwb.sourceforge.net/files/CQP_Tutorial.pdf}

	\item \emph{Corpus Encoding Tutorial}: \url{http://cwb.sourceforge.net/files/CWB_Encoding_Tutorial.pdf}

}
}

\seealso{
List of available help pages:\cr
\code{\link{cqi_attribute_size}}\cr
\code{\link{cqi_attributes}}\cr
\code{\link{cqi_cpos2id}}\cr
\code{\link{cqi_dump_subcorpus}}\cr
\code{\link{cqi_fdist}}\cr
\code{\link{cqi_full_name}}\cr
\code{\link{cqi_id2cpos}}\cr
\code{\link{cqi_list_corpora}}\cr
\code{\link{cqi_list_subcorpora}}\cr
\code{\link{cqi_query}}\cr
\code{\link{cqi_regex2id}}\cr
\code{\link{cqi_struc2cpos}}\cr
\code{\link{cqp_registry}}\cr
\code{\link{cqi_corpus_info}}\cr

Object model:\cr
\code{\link{corpus}}\cr
\code{\link{subcorpus}}\cr
\code{\link{cqp_flist}}\cr
\code{\link{cqp_ftable}}\cr
\code{\link{cqp_kwic}}\cr

}

\keyword{package}
