#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pa05.h"

Stack * pop (Stack * top)
{
  Stack * temp = top->next;
  free(top);
  return temp;
}

Stack * push (Stack * top, HuffNode * node)
{
  Stack * new_top = malloc(sizeof(Stack));
  new_top -> next = top;
  new_top -> node = node;
  return new_top;
}


HuffNode * HuffNode_create(char value)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  node -> value = value;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}


HuffNode * Create_CharTree(FILE * f_ch)
{

  int done = 0;
  char c, data;
  Stack * top = NULL;
  HuffNode * rc_tree;
  HuffNode * lc;
  HuffNode * new;

  while(done == 0)
    {
      c = fgetc(f_ch); //Get the byte
      
      if(c == '1')    //If its 1 make data into node, and push
	{
	  data  = fgetc(f_ch);
	  top = push(top, HuffNode_create(data));
	}
      else
	{
	  //The right child, or the tree top
	  rc_tree = top->node;
	  top =  pop(top);
	  
	  if(top == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      lc = top->node;
	      new = HuffNode_create(0);
	      new -> right = rc_tree;
	      new -> left = lc;
	      top = pop(top);
	      top = push(top, new);
	    }
	}    	   
    }  
  return rc_tree;
}

//Same function as PA04 SparseArray_Destroy

void tree_destroy(HuffNode * tree)
{
  if(tree == NULL)
    {
      return;
    }
  tree_destroy(tree->right);
  tree_destroy(tree->left);
  free(tree); 
}
 

void Huff_postOrderPrint(FILE * f_out, HuffNode *tree)
{
    // Base case: empty subtree
    if (tree == NULL) {
		return;
    }
    // Recursive case: post-order traversal
    // Visit left
    fprintf(f_out,"Left\n");
    Huff_postOrderPrint(f_out, tree->left);
    fprintf(f_out,"Back\n");
    // Visit right
    fprintf(f_out,"Right\n");
    Huff_postOrderPrint(f_out, tree->right);
    fprintf(f_out,"Back\n");
    // Visit node itself (only if leaf)
    if (tree->left == NULL && tree->right == NULL) 
      {
	fprintf(f_out,"Leaf: %c\n", tree->value);
      }  
}

// BIT 
/*
// Return 0, 1, or -1 on an error
int getBit(FILE*)
{

}

// Return -1 if there is an error
int getByte(FILE * fp)
{
  unsigned char byte = 0;
  int i;
  for(i = 0; i < 8; ++i) {
    int bit = getBit(fp);
    if(bit < 0)
      return -1; // An error
    // i == 0, left-shift 7
    // i == 1, left-shift 6
    // i == 2, left-shift 5
    // i == 3, left-shift 4
    // ...
    // i == 7, left-shift 0
  }
  return byte;
}
*/

/*
HuffNode * Create_BitTree(FILE * f_bit)
{
  int done = 0;
  Stack* top = NULL;
  
  HuffNode * rc_tree;
  HuffNode * lc;
  HuffNode * new;

  unsigned int mask[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};
  int whichbit = 1;
  unsigned char first = fgetc(f_bit); //get the first byte
  unsigned char second;
  unsigned char data;

  while(done != 1)
    {
      if((first & mask[whichbit-1]) != 0)
	{
	  if(whichbit == 8)
	    {
	      whichbit = 1;
	      data = fgetc(f_bit);
	      first = fgetc(f_bit); //Get new byte, since used up      
	    }
	  else
	    {
	      first = first << whichbit;
	      second = fgetc(f_bit);
	      data = first |(second >> (9-whichbit));
	      first = second;
	    }

	  whichbit ++;
	  top = push(top, HuffNode_create(data));
	}
      else
	{
	  if(whichbit == 8)
	    {
	      whichbit = 1;
	      first = fgetc(f_bit); //Get new byte, since used up    
	    }

	  rc_tree = top->node;
	  top =  pop(top);
	  
	  if(top == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      lc = top->node;
	      new = HuffNode_create(0);
	      new -> right = rc_tree;
	      new -> left = lc;
	      top = pop(top);
	      top = push(top, new);
	    }
	}
    }  
	 
  return rc_tree;
}

*/

//Modifies the Character tree create function
//Reads bits for command, and byte for data instead

HuffNode * Create_BitTree(FILE * f_bit)
{

  int done = 0;
  char c, data;
  Stack * top = NULL;
  HuffNode * rc_tree;
  HuffNode * lc;
  HuffNode * new;
  
  int count = 0;      //Counter for index
  unsigned char past; //Keep track of old data bits

  int byte = 8;
  int bit = 1;


  while(done == 0)
    {
      c = getBit(f_bit, bit, &count, &past);
      
      if(c == 1)
	{
	  data  = getBit(f_bit, byte, &count, &past);
	  top = push(top, HuffNode_create(data));
	}
      else
	{
	  //The right child, or the tree top
	  rc_tree = top->node;
	  top =  pop(top);
	  
	  if(top == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      lc = top->node;
	      new = HuffNode_create(0);
	      new -> right = rc_tree;
	      new -> left = lc;
	      top = pop(top);
	      top = push(top, new);
	    }
	}    	   
    }  
  return rc_tree;
}

// FOR DEBUGG USE:
// Prints out bit by bit
void print_bits(char * filename)
{
  unsigned char masks[] = {0x80,0x40,0x20,0x10,0x08,0x04,0x02,0x01};

  FILE * fptr = fopen(filename,"r");
  while(!feof(fptr))
    {
      unsigned char t = fgetc(fptr);
      int i;
      for(i = 0; i<8; i++)
	{
	  printf("%d",((t&masks[i])!=0));
	}
      printf("\n");
    }
}


char getBit(FILE * f_bit, int size, int * counter, unsigned char * past)
{
  //If counter is 0, read a byte (First case scenario)
  if(*counter == 0)
    {
      fread(past, 1, 1, f_bit);
      (*counter) = 8;
    }

  unsigned char bit;
  int mask = 1;
  bit = (*past);   //Initialize the past data, to the array to be added to

  if(*counter < size) //If counter smaller than size, shift the byte and another byte, "or" them togher.
    {
      bit = (*past);
      bit = (bit << (8 - (*counter)));
      fread(past, 1, 1, f_bit);
      bit = (bit|((*past) >> (*counter)));
      return bit;
    }

  if(size == 1) //Only get 1 bit (Command)
    {
      bit = mask & (bit >> ((*counter) - size));
      (*counter) = ((*counter)-1);
    }
  else
    {
      bit = (bit >> ((*counter)-size)); //Taking full byte as data
      (*counter) = 0;
    }
  return bit;   
}
