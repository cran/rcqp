# ===========================================================================
# File: "zzz.R"
#                        Created: 2011-11-25 13:54:54
#              Last modification: 2011-11-25 13:54:54
# Authors: Bernard Desgraupes <bernard.desgraupes@u-paris10.fr>
#          Sylvain Loiseau <sylvain.loiseau@univ-paris13.fr>
# ===========================================================================

.onLoad <-function (lib, pkg) {
	library.dynam("rcqp", pkg, lib)
}
