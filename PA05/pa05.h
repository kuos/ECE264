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


Stack * pop (Stack * top);
Stack * push (Stack * top, HuffNode * node);
HuffNode * HuffNode_create(char value);
HuffNode * Create_CharTree(FILE * f);
void tree_destroy(HuffNode * tree);
void Huff_postOrderPrint(FILE * f_out, HuffNode *tree);

#endif



