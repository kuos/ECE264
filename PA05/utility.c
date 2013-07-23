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


HuffNode * Create_CharTree(FILE * f)
{

  int done = 0;
  char c, data;
  Stack * top = NULL;
  HuffNode * rc_tree;
  HuffNode * lc;
  HuffNode * new;

  while(done == 0)
    {
      c = fgetc(f);
      
      if(c == '1')
	{
	  data  = fgetc(f);
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
unsigned char * getBit (FILE * fptr, int * whichbit, last)
{
  unsigned char mask[] = {0x80,0x40,0x20,0x10;0x08;0x04,0x02,0x01}; 

  if(*whichbit == 0)
    {
      unsigned char t = fgetc(fptr);
      *last = t;
      unsigned char s = t>>>7;
      (*whichbit) ++;
      return s;
    }
  else
    {
      unsigned t = (*last) & mask[*whichbit];
      t>>=7-(*whichbit);
      (*whichbit)++;
      return t;
    }
}
*/

HuffNode * Create_BitTree(FILE * f)
{
  return NULL;
}

/*int done = 0;
  Stack* top = NULL
  
  char c, data;

  HuffNode * rc_tree;
  HuffNode * lc;
  HuffNode * new;

  unsigned char mask[] = {0x80;0x40,0x20,0x10;0x08,0x04,0x02,0x01};
  unsigned char cmd;
  char data;
  char data_next;
  int whichbit = 0;

  cmd = fgetc(f); //get the first byte

  while(done == 0)
    {     
      if((cmd & mask[whichbit]) != 0)
	{
	  //First bit is 1
	  data = cmd;
	  data <<=whichbit;       //Shift byte#1 by however much we need
	  data_next = fgetc(fptr);
	  data = data |(data_next>>(7-whichbit)); //Shift byte#2 by however much we don't need
	  whichbit ++;

	  top = push(top, HuffNode_create(data));
	}
      else
	{
	  rc_tree = HuffNode_create(0);  //The right child, or the tree top
	  rc_tree = top->node;
	  top =  pop(top);
	  
	  if(top == NULL)
	    {
	      done = 1;
	    }
	  else
	    {
	      lc = HuffNode_create(0);
	      lc = top->node;
	      new = HuffNode_create(0);
	      new -> right = rc;
	      new -> left = lc;
	      top = pop(top);
	      top = push(top, new);
	    }
	}    	   
    }  

  return rc_tree;
}


*/
