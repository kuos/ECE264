#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pa05.h"



int main (int argc, char ** argv)
{
  if(argc < 3)
    {
      printf("EROOR!!");
      return EXIT_FAILURE;
    }

  FILE * f = fopen(argv[1],"r");
  if(f == NULL)
    {
      printf("ERROR Opening File!");
    }

  int len = strlen(argv[1]);
  char last = argv[1][len-1];
  HuffNode * tree;

  if(last == 'h')
    {
      tree = Create_CharTree(f);
    } 
  else
    {
      //tree = Create_BitTree(f);
    } 

  FILE * f_out = fopen(argv[2],"w");
  Huff_postOrderPrint(f_out,tree);
  tree_destroy(tree);
  fclose(f);
  fclose(f_out);

return EXIT_SUCCESS;
}
