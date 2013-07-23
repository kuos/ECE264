#include "List.h"
#include <stdio.h>
#include <stdlib.h>

static Node * Node_constrcut(int val)
{
  Node * n;
  n == malloc(sizeof(Node));
  n -> data = val;
  n -> next = NULL;
  return n;
}


Node * List_insertSort(Node * front, int val)
{
  if(front == NULL)
    {
      return Node_construct(val);
    }
  if((front->data) > val)
    {
      Node * n = Node_constrcut(val);
      n-> next = front;
      return n;
    }

  //can use a while loop
  front->next = List_insertSort(front->next, val);
  //when reached, the return n in the 
  //if loop will make the link to the previous val
  return front;
}


Node * List_insert(Node * front, int val)
{
	Node * n = Node_construct(val);
	n -> next = front;
	return n;
}


Node * List_insert2(Node * front, int val)
{
  if(front == NULL)
    {
      return Node_construct(val);
    }

  front -> next = List_insert2(front->next, val);
  return front;
  // if front is null retun new node, or else it returns front.
  // front->next = front->next
}


Node * List_insert3(Node *front, int val)
{
  if(front == NULL)
    {
	return Node_construct(val);
    }
	
  Node * p = front;

  while ((p->next)!= NULL)
    {
      p = p->next;
    }

  p -> next = Node_construct(val);
  return front;
  
  //IF RETURN P 

}


void List_print(Node * front)
{
	if(front == NULL)
	{
		return;
	}
	printf("%d \n", front->data);
	List_print(front->next);

NOde * List_delete(Node * front, int val)
{
  if(front == NULL)
    {
      return NULL;
    }
  if((front->val) == val)
    {
      Node * p = front->next; //p may be NULL
      free(front);
      return p;
    }
  front->next = List_delete(front->next, val);
  return front;
}

void List_destroy

  /*
 List_insert4 (Node ** front, ....)
{
  *front = ...
  */


main
{
	front = List_insert(front, 5);
	front = List_insert(front, 8);
	front = List_insert(front, 9);
	front = List_insert(front, 11);

	front2 = List_insert2(front2, 5);
	front2 = List_insert2(front2, 8);
	front2 = List_insert2(front2, 9);
	front2 = List_insert2(front2, 11);
       
       return EXIT_SUCCESS;
}
