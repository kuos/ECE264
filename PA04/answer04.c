#include "pa04.h"
#include <stdio.h>
#include <stdlib.h>


/* Create a single instance of a sparse array node with a specific
 * index and value. This is a constructor function that allocates
 * memory, copies the integer values, and sets the subtree pointers to
 * NULL.
 */

SparseNode *SparseNode_create(int index, int value)
{
  SparseNode * one_node = NULL;
  one_node = malloc(sizeof(SparseNode));

  one_node->left  = NULL;
  one_node->right = NULL;
  one_node->index = index;
  one_node->value = value;
  
  return one_node;
}

/* Build a sparse array from given indices and values with specific length.
 * This function takes an array of indices, an array of values, and 
 * the length as inputs.
 * It returns a sparse array. 
 * You need to insert tree nodes in order:
 * the first sparse array node contains indices[0] and values[0])
 */

SparseNode *SparseArray_build(int * indicies, int * values, int length)
{
  SparseNode * array = NULL;
  int i;

  for(i=0;i<length;i++)
    {
      array = SparseArray_add(array,indicies[i],value[i]);
    }

  return array;
}

/* Add a particular value into a sparse array on a particular index.
 * The sparse array uses the index as a key in a binary search tree.
 * It returns the new sparse array root
 * as its return value. If the index does not exist, create it. 
 * If the index exists, REPLACE the value to the new one. Use the index to
 * determine whether to go left or right in the tree (smaller index
 * values than the current one go left, larger ones go right).
 */

SparseNode * SparseArray_add ( SparseNode * array, int index, int value )
{
  //If array is NULL, create the node with the index
  if(array == NULL)
    {
      return SparseNode_create(index, value);
    }

  //If index already exist, replace value at that index
  if(index == (array->index))
    {
      array->value = value;
      return array;
    }
  
  //If index smaller go left, if larger go right
  if(index < (array->index)
    {
      array->left = SparseArray_add(array->left, value);
    }
    else
      {
	array->right = SparseArray_add(array->right,value);
      }
 
  return array ;
}

/* Destroy an entire sparse array. 
 * traversing the binary tree in postorder. Use the
 * SparseNode_destroy () function to destroy each node by itself.
 */
void SparseArray_destroy ( SparseNode * array )
{
  if(array == NULL)
    {
      return;
    }
  SparseArray_destroy(array->right);
  SparseArray_destroy(array->left);
  free(array); 
}
 
/* Retrieve the smallest index in the sparse array. 
 */
int SparseArray_getMin ( SparseNode * array )
{
  if(array == NULL)
    {
      return;
    }
  if(array->left != NULL)
    {
      SparseArray_getMin(array->left);
    }
  if(array->left == NULL)
    {
      return array->index;
    }
 
  return 0;
}

/* Retrieve the largest index in the sparse array. 
 */
int SparseArray_getMax ( SparseNode * array )
{
  if(array == NULL)
    {
      return;
    }
  if(array->right != NULL)
    {
      SparseArray_getMin(array->right);
    }
  if(array->right == NULL)
    {
      return array->index;
    }
 
  return 0;
}

/* Retrieve the node associated with a specific index in a sparse
 * array.  It returns the value
 * associated with the index. If the index does not exist in the
 * array, it returns 0. If the given index is smaller than the current
 * node, search left ; if it is larger, search right.
 */
SparseNode * SparseArray_getNode(SparseNode * array, int index )
{
  if(array == NULL)
    {
      return;
    }
  if(index < array->index)
    {
      SparseArray_getNode(array->left, index);
    }
  if(index > array->index)
    {
      SparseArray_getNode(array->right,index);
    }
  if(index == array-index)
    {
      return array;
    }
    
  return 0;
}

/* Remove a value associated with a particular index from the sparse
 * array. It returns the new
 * sparse array ( binary tree root ). HINT : You will need to isolate
 * several different cases here :
 * - If the array is empty ( NULL ), return NULL
 * - Go left or right if the current node index is different.

 * - If both subtrees are empty, you can just remove the node.

 * - If one subtree is empty, you can just remove the current and
 * replace it with the non - empty child.

 * - If both children exist, you must find the immediate successor of
 * the current node ( leftmost of right branch ), swap its values with
 * the current node ( BOTH index and value ), and then delete the
 * index in the right subtree.
*/
SparseNode * SparseArray_remove ( SparseNode * array, int index )
{
  if(array == NULL)
    {
      return NULL;
    }

  if(index < (array->index))
    {
      array->left = SparseArray_remove(array->left,index);
      return array;
    }

  if(index > (array->index))
    {
      array->right = SparseArray_remove(array->right,index);
      return array;
    }


  if(((array->left)==NULL)&&(array->right)==NULL) //NO CHILD LEFT BEHIND
    {
      free(array);
      return NULL;
    }

  if((array->left) == NULL)
    {
      SparseNode * connect = array->right;
      free(array);
      return connect;
    }

  if((array->right) == NULL)
    {
      SparseNode * connect2 = array->left;
      free(array);
      return connect2;
    }

  // PAGE 182 OF COURSE NOTES!!
/*TreeNode * su = tn -> right;  su must not be NULL 
while ((su -> left) != NULL)
{
su = su -> left;
}
tn -> value = su -> value;
su -> value = val;
tn -> right = Tree_delete(tn -> right, val);
return tn;
*/




  return array ;
}

/* The function makes a copy of the input sparse array 
 * and it returns a new copy. 
 */

SparseNode * SparseArray_copy(SparseNode * array)
{
  SparseNode * new_array;
  
  if(array == NULL)
    {
      return NULL;
    }
  
  SparseArray_add(new_array, array->index, array->value);
  
  if(array->left != NULL)
    
  
  return array;
}

/* Merge array_1 and array_2, and return the result array. 
 * This function WILL NOT CHANGE the contents in array_1 and array_2.
 * When merging two sparse array:
 * 1. The contents in array_1 and array_2 should not be changed. You should make
 *    a copy of array_1, and do merging in this copy.
 * 2. array_2 will be merged to array_1. This means you need to read nodes in 
 *    array_2 and insert them into array_1.
 * 3. You need to use POST-ORDER to traverse the array_2 tree. 
 * 4. Values of two nodes need to be added only when the indices are the same.
 * 5. A node with value of 0 should be removed.
 * 6. if array_2 has nodes with index different than any nodes in array_1, you
 *    should insert those nodes into array_1.
 * 
 */

SparseNode * SparseArray_merge(SparseNode * array_1, SparseNode * array_2)
{
  return NULL;
}

