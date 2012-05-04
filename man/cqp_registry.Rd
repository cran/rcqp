\name{cqp_registry}
\alias{cqp_registry}

\title{The CQP registry}

\description{
Setting the CQP registry for rcqp.
}

\details{

Corpora are declared in files located in a directory called
\emph{registry} (see CWB documentation for more details). One of the
mechanisms provided by CWB in order to set the path of the \emph{registry}
directory is to define the environment variable
\code{CORPUS_REGISTRY}.

In \code{rcqp}, the \code{CORPUS_REGISTRY} environment variable is first
read. If it is not set, rcqp tries to use the default registry directory,
which varies according to your system (on most Unixes, it is
\file{/usr/local/share/cwb/registry}; on Windows, it is \file{C:\\CWB\\Registry}). If this default
directory does not exist, \code{rcqp} cannot proceed further.

In order to set the \code{CORPUS_REGISTRY} variable, you can 
\itemize{
	\item either use the mechanisms provided by your system to
	set the environment variable before the R command is executed.

	\item or define the variable from the R console using the
	\code{\link{Sys.setenv}} function. This must be done before the package
	is loaded. 
	
	\item or define this variable in the configuration file
	\file{~/.Renviron} which is read by R at startup. In that case,
	the environment variable is defined only for \code{rcqp}, and will not be seen
	by any other CWB program.
	
	}
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
\code{\link{cqi_list_corpora}}, 
\code{\link{cqi_list_subcorpora}}, 
\code{\link{cqi_query}}.
}

\examples{
Sys.setenv(CORPUS_REGISTRY="/users/vhugo/cwb/registry")
}

\keyword{registry}
