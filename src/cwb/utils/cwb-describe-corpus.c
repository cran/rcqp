/* 
 *  IMS Open Corpus Workbench (CWB)
 *  Copyright (C) 1993-2006 by IMS, University of Stuttgart
 *  Copyright (C) 2007-     by the respective contributers (see file AUTHORS)
 * 
 *  This program is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU General Public License as published by the
 *  Free Software Foundation; either version 2, or (at your option) any later
 *  version.
 * 
 *  This program is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General
 *  Public License for more details (in the file "COPYING", or available via
 *  WWW at http://www.gnu.org/copyleft/gpl.html).
 */


#include "../cl/globals.h"
#include "../cl/corpus.h"
#include "../cl/attributes.h"
#include "../cl/macros.h"

/** String set to the name of this program. */
char *progname = NULL;

/**
 * Prints a message describing how to use the program to STDERR and then exits.
 */
void
describecorpus_usage(void)
{
 Rprintf( "\n");
 Rprintf( "Usage:  %s [flags] <corpus> [<corpus> ...] \n", progname);
 Rprintf( "Options:\n");
 Rprintf( "  -r <dir>  use registry directory <dir>\n");
 Rprintf( "  -s        show statistics (attribute & lexicon size)\n");
 Rprintf( "  -d        show details (about component files)\n");
 Rprintf( "  -h        this help page\n");
 Rprintf( "Part of the IMS Open Corpus Workbench v" VERSION "\n\n");
  rcqp_receive_error(2);
}

/**
 * Prints the names of attributes in a corpus to STDOUT.
 *
 * Only one type of attribute is analysed.
 *
 * @param corpus  The corpus to analyse.
 * @param type    The type of attribute to show. This should be
 *                one of the constants in cl.h (ATT_POS etc.)
 */
void
describecorpus_show_attribute_names (Corpus *corpus, int type)
{
  Attribute *a;

  start_indented_list(64, 16, 6); /* indent by 6 chars */
  for (a = corpus->attributes; a; a = a->any.next) {
    if (a->any.type == type) {
      print_indented_list_item(a->any.name);
    }
  }
  /* don't end_indented_list() because that might print "\r" */
 Rprintf("\n\n");
}

/**
 * Prints basic information about a corpus to STDOUT.
 *
 * @param corpus                The corpus to report on.
 * @param with_attribute_names  Boolean: iff true, the counts of each type of attribute
 *                              are followed by a list of attribute names.
 *
 */
void
describecorpus_show_basic_info (Corpus *corpus, int with_attribute_names)
{
  Attribute *word, *a;
  int p_atts = 0, s_atts = 0, a_atts = 0;
  int size;
  char *colon = (with_attribute_names) ? ":" : "";

 Rprintf("description:    %s\n", corpus->name);
 Rprintf("registry file:  %s/%s\n", corpus->registry_dir, corpus->registry_name);
 Rprintf("home directory: %s/\n", corpus->path);
 Rprintf("info file:      %s\n", (corpus->info_file) ? corpus->info_file : "(none)");
  if ((word = cl_new_attribute(corpus, "word", ATT_POS)) == NULL) {
   Rprintf( "ERROR: 'word' attribute is missing. Aborted.\n");
    rcqp_receive_error(1);
  }
  size = cl_max_cpos(word);
 Rprintf("size (tokens):  ");
  if (size >= 0) 
   Rprintf("%d\n", size);
  else
   Rprintf("ERROR\n");
 Rprintf("\n");
  
  for (a = corpus->attributes; a; a = a->any.next) {
    switch(a->any.type) {
    case ATT_POS:   p_atts++; break;
    case ATT_STRUC: s_atts++; break;
    case ATT_ALIGN: a_atts++; break;
    default: break;
    }
  }
 Rprintf("%3d positional attributes%s\n", p_atts, colon);
  if (with_attribute_names)
    describecorpus_show_attribute_names(corpus, ATT_POS);
 Rprintf("%3d structural attributes%s\n", s_atts, colon);
  if (with_attribute_names)
    describecorpus_show_attribute_names(corpus, ATT_STRUC);
 Rprintf("%3d alignment  attributes%s\n", a_atts, colon);
  if (with_attribute_names)
    describecorpus_show_attribute_names(corpus, ATT_ALIGN);
 Rprintf("\n");
}

/**
 * Prints statistical information about a corpus to STDOUT.
 *
 * Each corpus attribute gets info printed about it:
 * tokens and types for a P-attribute, number of instances
 * of regions for an S-attribute, number of alignment
 * blocks for an A-attribute.
 *
 * @param corpus  The corpus to analyse.
 */
void 
describecorpus_show_statistics (Corpus *corpus)
{
  Attribute *a;
  int tokens, types, regions, blocks;

  for (a = corpus->attributes; a; a = a->any.next) {
    switch(a->any.type) {
    case ATT_POS:
     Rprintf("p-ATT %-16s ", a->any.name);
      tokens = cl_max_cpos(a);
      types = cl_max_id(a);
      if ((tokens > 0) && (types > 0))
       Rprintf("%10d tokens, %8d types", tokens, types);
      else 
       Rprintf("           NO DATA");
      break;
    case ATT_STRUC:
     Rprintf("s-ATT %-16s ", a->any.name); 
      regions = cl_max_struc(a);
      if (regions >= 0) {
       Rprintf("%10d regions", regions);
        if (cl_struc_values(a))
         Rprintf(" (with annotations)");
      }
      else 
       Rprintf("           NO DATA");
      break;
    case ATT_ALIGN:
     Rprintf("a-ATT %-16s ", a->any.name); 
      blocks = cl_max_alg(a);
      if (blocks >= 0) {
       Rprintf("%10d alignment blocks", blocks);
        if (cl_has_extended_alignment(a))
         Rprintf(" (extended)");
      }
      else
       Rprintf("           NO DATA");
      break;
    default:
     Rprintf("???   %-16s (unknown attribute type)", a->any.name); 
      break;
    }
   Rprintf("\n");
  }

 Rprintf("\n");
}

/* *************** *\
 *      MAIN()     *
\* *************** */

/**
 * Main function for cwb-describe-corpus.
 *
 * Prints information about an indexed corpus to STDOUT.
 *
 * @param argc   Number of command-line arguments.
 * @param argv   Command-line arguments.
 */
int
main(int argc, char **argv)
{
  int i;
  Corpus *corpus;

  int c;
  extern char *optarg;
  extern int optind;

  int show_stats = 0;
  int show_details = 0;

  char *registry = NULL;

  progname = argv[0];
  while ((c = getopt(argc, argv, "+r:sdh")) != EOF) {
    switch(c) {
      
      /* -r <dir>: change registry directory */
    case 'r':
      if (registry == NULL)
        registry = optarg;
      else {
       Rprintf( "%s: -r option used twice\n", progname);
        rcqp_receive_error(2);
      }
      break;
      
      /* -s: show statistics */
    case 's':
      show_stats++;
      break;

      /* -d: show details */
    case 'd':
      show_details++;
      break;

      /* -h: help page */
    case 'h':
    default:
      describecorpus_usage();
      break;
    }

  }

  if (optind >= argc) {
   Rprintf( "Missing argument, try \"%s -h\" for more information.\n", progname);
    rcqp_receive_error(1);
  }

  for (i = optind; i < argc; i++) {
    if ((corpus = cl_new_corpus(registry, argv[i])) == NULL) {
     Rprintf( "ERROR. Can't access corpus %s !\n", argv[i]);
      rcqp_receive_error(1);
    }

   Rprintf("\n============================================================\n");
   Rprintf("Corpus: %s\n", argv[i]);
   Rprintf("============================================================\n\n");

    describecorpus_show_basic_info(corpus, !(show_stats || show_details));
    /* show attribute names only if no other options are selected */

    if (show_stats) {
      describecorpus_show_statistics(corpus);
    }

    if (show_details) {
      describe_corpus(corpus);
    }
  
    cl_delete_corpus(corpus);
  }

  return 0;
}
