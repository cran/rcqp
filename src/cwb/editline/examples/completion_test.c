
#include <stdio.h>
#include <stdlib.h>
#include <editline.h>

char **
completion_func(char *text, int start, int end) {
    int i;
   Rprintf("\nCOMPLETE '%s'\n", text);
    for (i=-10; i<start; i++)
Rprintf(" ");
   Rprintf("^");
    for (i=start+1; i<end; i++)
Rprintf(" ");
   Rprintf("^\n");
    return NULL;		/* means: no completions found, try default */
    /* otherwise: return allocated, NULL-terminated list of allocated strings */
}



int main()

{
  char *line;

  read_history("TEST_HISTORY");

  el_user_completion_function = completion_func;

  while ((line = readline("editline> ")) != NULL)
    {
     Rprintf("Input was '%s'\n", line);
      add_history(line);
      free(line);
    }

  write_history("TEST_HISTORY");

  Rprintf("%d", '\n');
  
  return 0;
}


