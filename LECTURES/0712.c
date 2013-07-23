#include "0712.h"
TreeNode * TreeNode_constrcut(int v)
{
  Node * n;
  n = malloc(sizeof(Node));
  n-> data = v;
  n-> left = NULL;
  n-> right = NULL;
  return n;
}

TreeNode * Tree_insert(TreeNode * t, int v)
{
  if(t==NULL)
    {
      return TreeNode_constrcut(v);
    }
  if((t->data) == v)
    {
      return t;
    }
  if(v < (t->data))
    {
      t->left = Tree_insert(t->left, v);
      return t;
    }
  if(v > (t->data))
    {
      t->right = Tree_insert(t->right, v);
    }
  return t;
}
