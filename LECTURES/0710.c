//Link List vs. Binary Tree
//Significant speed difference
// 2^(1 billion)


#ifndef TREE_H
#define TREE_H
typedef struct treenode
{
  int data;
  struct treenode * left;
  struct treenode * right;
} Node;

/* if a data is less than the value of a
 * node this value is on the left side
 * other wise on the right side. The data
 * stored in the tree are distinct
 */
