#include "linked_list.h"
/*
 * Linked list
 */

#include <stdio.h>		/* printf */
#include <stdlib.h>		/* malloc, free */
#include <assert.h>		/* assert */

/* functions to create lists */
node *make_node (int v, node * q)
{
  node *p = malloc (sizeof (node));
  p->value = v;

  if (q == &SENTINEL_node)
    p->next = &SENTINEL_node;
  else
    p->next = q;
  return p;
}

/* free all nodes in the list p */
void free_list (node * p)
{
  node *q;
  while (p != NULL) {
    q = p->next;
    free(p);
    p = q;
  }
}

void free_list2 (node * p)
{
  p->next = NULL;
  free(p);
  p->value=0;
}


/* print list to console */
//prints if it finds defined value, and calls function to next element in linked list, if there is one.
void print_list (node * p)
{

  if (p == NULL) {
      printf("List is empty");
    } else {


      node *temp = p;
      if (p != NULL) {
          temp= p->next;
          printf("%d, ", p->value);
          print_list(temp);
      }
    }

    // Add your code for exercise 1
    // There is NO testcode for this
}


//Der er ingen input til en integer sum-værdi..... Så man skal lave ber
int sum_squares (node * p)
{
    // Add your code for excercise 2
    // You can find the tests in tests.cpp

    int sum = 0;
    node *temp = p;


    //If current node is NULL, return a value that doesnt effect sum (0). Else add value to sum.
    if (p == NULL) {
        return 0;
    } else {
      sum+=square(temp->value);
    }

    //If the current node isn't the last node, we wish to go one further along, and add the given value. Works because there is only one step taken at a time, and recursion continues until the last element is found.
    if (temp->next != NULL) {
        temp= temp->next;
        sum+=sum_squares(temp);
    }

    return sum;
}

node *map (node * p, int (*f) (int))
{
    // Add your code for excercise 3

    node *temp = p;
    temp->value=f(temp->value);

    while (temp->next!=NULL){
        temp=temp->next;
        temp->value = f(temp->value);
    }
    return p;
}


int square (int x)
{
  return x * x;
}
