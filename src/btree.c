#include "btree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include<stdbool.h>

void find_placement_in_tree(int x, struct tree_node *t_placering) {
  //Switch case til at finde ud af om den skal gå til venstre eller højre.

  if (x<=t_placering->item) {

    if (t_placering->left == NULL) {
      t_placering->left = malloc(sizeof(struct tree_node));
      t_placering->left->item=x;

      t_placering->left->left=NULL;
      t_placering->left->right=NULL;


    } else {
      find_placement_in_tree(x, t_placering->left);
    }


  } else {
    if (t_placering->right == NULL) {
      t_placering->right = malloc(sizeof(struct tree_node));
      t_placering->right->item=x;

      t_placering->right->left=NULL;
      t_placering->right->right=NULL;
    } else {
      find_placement_in_tree(x, t_placering->right);
    }
  }
}

struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t

  //Tilfælde hvor der ikke er nogen børn.
  
  //DENNE BETINGELSE ITEM==NULL ER LIDT SCUFFED. VIRKER IKKE I TILFÆLDE HVOR DER TJEKKES LEAF-NODE MED VÆRDI 0.
  if (t->left == NULL && t->right == NULL && t->item==NULL) {
    t->item=x;
    return t;
  }

  find_placement_in_tree(x, t);

  //Ellers skal den gå til venstre/højre så langt som muligt

  return t;
}

struct tree_node * Remove (int x, struct tree_node *t)
{
 // Remove one item from the tree t

  return NULL;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.

  return NULL;
}


struct tree_node * Initialize (struct tree_node *t)
{
  // Create an empty tree
  t = malloc(sizeof(struct tree_node));
  t->left = NULL;
  t->right = NULL;
  return t;
}

int Empty (struct tree_node *t)
{
  if (t==NULL) {
    return 1;
  }
  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full
    return 0;
}
