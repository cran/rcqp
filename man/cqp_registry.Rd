\name{cqp_registry}
\alias{cqp_registry}
\alias{cqi_getRegistry}
\alias{cqi_setRegistry}

\title{The CQP registry}

\description{
Setting the CQP registry for rcqp.
}

\usage{
	cqi_getRegistry()
	cqi_setRegistry(path)
}

\arguments{
	\item{path}{(\emph{string}) the full path of the registry directory.}
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
\file{/usr/local/share/cwb/registry}; on Windows, it is
\file{C:\\CWB\\Registry}). If this default directory does not exist, \code{rcqp} 
cannot proceed further. At this point, you can use the
\code{cqi_setRegistry} function to specify the path of the registry
directory.

The path passed to the \code{cqi_setRegistry} function must exist. Note that,
once it is set, the path of the registry may not be changed.

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

\value{
	\code{cqi_getRegistry} returns a vector with the path of the registry
	directory if it has been set, otherwise the NULL string.
    \code{cqi_setRegistry} does not return anything.
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
\dontrun{
Sys.setenv(CORPUS_REGISTRY="/users/vhugo/cwb/registry")
cqi_setRegistry("/users/vhugo/cwb/registry")
}
}

\keyword{registry}
