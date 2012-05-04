globals.o: globals.c globals.h cl.h
macros.o: macros.c globals.h cl.h macros.h
list.o: list.c globals.h cl.h macros.h list.h
lexhash.o: lexhash.c globals.h cl.h macros.h lexhash.h
bitfields.o: bitfields.c globals.h cl.h macros.h bitfields.h
storage.o: storage.c globals.h cl.h cl_endian.h macros.h storage.h
fileutils.o: fileutils.c globals.h cl.h fileutils.h
special-chars.o: special-chars.c glib.h globals.h cl.h special-chars.h
regopt.o: regopt.c globals.h cl.h regopt.h pcre.h
corpus.o: corpus.c globals.h cl.h macros.h attributes.h storage.h \
  corpus.h registry.tab.h
attributes.o: attributes.c globals.h cl.h cl_endian.h corpus.h storage.h \
  macros.h fileutils.h cdaccess.h makecomps.h attributes.h list.h
makecomps.o: makecomps.c globals.h cl.h cl_endian.h macros.h storage.h \
  fileutils.h corpus.h attributes.h cdaccess.h makecomps.h
registry.tab.o: registry.tab.c globals.h cl.h corpus.h storage.h macros.h \
  attributes.h
lex.creg.o: lex.creg.c globals.h cl.h corpus.h storage.h registry.tab.h
cdaccess.o: cdaccess.c globals.h cl.h cl_endian.h macros.h attributes.h \
  storage.h corpus.h special-chars.h bitio.h compression.h regopt.h \
  pcre.h cdaccess.h
bitio.o: bitio.c globals.h cl.h cl_endian.h bitio.h
cl_endian.o: cl_endian.c globals.h cl.h cl_endian.h
compression.o: compression.c globals.h cl.h bitio.h compression.h
binsert.o: binsert.c globals.h cl.h macros.h binsert.h
class-mapping.o: class-mapping.c globals.h cl.h macros.h cdaccess.h \
  class-mapping.h corpus.h storage.h attributes.h
