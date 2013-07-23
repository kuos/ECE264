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


  int len = strlen(argv[1]);
  char last = argv[1][len-1];

  FILE * f_ch;
  FILE * f_bit;
  
  FILE * f_out;
  FILE * f_out2;

  HuffNode * tree;

  if(last == 'h')
    {
      
      f_ch = fopen(argv[1],"r");

      if(f_ch == NULL)
	{
	  printf("ERROR Opening File!");
	}

      tree = Create_CharTree(f_ch);
  
      f_out = fopen(argv[2],"w");
      Huff_postOrderPrint(f_out,tree);
      tree_destroy(tree);
      fclose(f_ch);
      fclose(f_out);
    } 
  else
    {
      f_bit = fopen(argv[1],"rb");

      if(f_bit == NULL)
	{
	  printf("ERROR Opening File!");
	}
      //      print_bits(char * Filename)

      tree = Create_BitTree(f_bit);

      f_out2 = fopen(argv[2],"wb");
      Huff_postOrderPrint(f_out2,tree);
      tree_destroy(tree);
      fclose(f_bit);
      fclose(f_out2);
    } 


return EXIT_SUCCESS;
}
