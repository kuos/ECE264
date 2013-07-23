#ifndef PA05_H
#define PA05_H

typedef struct _huffnode {
  char value;
  struct _huffnode *left;
  struct _huffnode *right;
} HuffNode;

typedef struct _stack {
  struct _stack * next;
  HuffNode * node;
} Stack;


//Pop and Push onto stack, Create Node for Coding Tree/Link List:
Stack * pop (Stack * top);
Stack * push (Stack * top, HuffNode * node);
HuffNode * HuffNode_create(char value);

//Creating the Char Tree, Bit Tree:
HuffNode * Create_CharTree(FILE * f_ch);
HuffNode * Create_BitTree(FILE * f_bit);
char getBit(FILE * f_bit, int size, int * counter, unsigned char * first);

//Print and Destroy:
void tree_destroy(HuffNode * tree);
void Huff_postOrderPrint(FILE * f_out, HuffNode *tree);

//DEBUG:
void print_bits(char * filename);
#endif



