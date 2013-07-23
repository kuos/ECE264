#include "pa05.h"
#include <stdio.h>
#include <stdlib.h>


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
  Stack* top = malloc(sizeof(Stack));
  top -> next = NULL;
  top -> node = NULL;
  
  char c, data;

  HuffNode * rc_tree;
  HuffNode * lc;
  HuffNode * new;

  while(done == 0)
    {
      char c = fgetc(f);
      
      if(c == '1')
	{
	  data  = fgetc(f);
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


HuffNode * HuffNode_create(char value)
{
  HuffNode * node = malloc(sizeof(HuffNode));
  node -> value = value;
  node -> left = NULL;
  node -> right = NULL;
  return node;
}

HuffNode * getBit (FILE filename)
{
  unsigned char mask1 = 0x80;
  




}
