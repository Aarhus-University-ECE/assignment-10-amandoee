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


bool found = false;

int search_placement_in_tree(int x, struct tree_node *t_placering) {

  if (found == true) {
    return 1;
  }

  //Finds the supposed placement of the item in the tree. Checks if it is there, if not, it returns 0.
  if (x<=t_placering->item && t_placering->left != NULL) {
      search_placement_in_tree(x, t_placering->left);
    } else if (t_placering->right != NULL) {
      search_placement_in_tree(x, t_placering->right);
    }

    if (t_placering->item == x) {
      found = true;
      return 1;
    } else if (found == false) {
      return 0;
    }

    if (found == true) {
    return 1;
  }
}


struct tree_node *t_to_be_removed = NULL;

void give_placement_in_tree(int x, struct tree_node *t_placering) {

  //Finds the supposed placement of the item in the tree. Checks if it is there, if not, it returns 0.
  if (x<=t_placering->item && t_placering->left != NULL) {
      give_placement_in_tree(x, t_placering->left);
    } else if (t_placering->right != NULL) {
      give_placement_in_tree(x, t_placering->right);
    }

    if (t_placering->item == x) {
      
      while (t_placering->left != NULL && t_placering->left->item == x) {
        t_placering=t_placering->left;
      }

      t_to_be_removed = t_placering;

    }
}


struct tree_node * Insert (int x, struct tree_node *t)
{
  // Insert item x into the tree t

  //Tilfælde hvor der ikke er nogen børn.
  
  //DENNE BETINGELSE ITEM==NULL ER LIDT SCUFFED. VIRKER IKKE I TILFÆLDE HVOR DER TJEKKES LEAF-NODE MED VÆRDI 0.
  if (t->left == NULL && t->right == NULL && t->item==0) {
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

  //Resets global pointer so it works for give_placement
  t_to_be_removed = NULL;

  give_placement_in_tree(x, t);

  if (t_to_be_removed != NULL) {
    t_to_be_removed->item = NULL;
  }

  //On the off case that multiple same values are added, they will always be the left child of each other. Therefore it should go down as left as possible, when removing x-value. Otherwise it will technically remove multiple values.

  return t;
}


int Contains (int x, struct tree_node *t)
{

  // Return true if the tree t contains item x. Return false otherwise.
  //Uses logic to determine where value x is located in the tree. If it is not found, it returns false.
  int result = search_placement_in_tree(x, t);

  //Resets global variable for next use of "Contains"
  found = false;

  return result;
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

  //This is only here because the testcases are wierd. Why should we make an initialize function, if we don't allocate any memory in the initialization???
  //Therefore, i'm assuming that the only case where the item is zero, without any left/right nodes, must be at root. This is an assumption, but it's better than guessing what to do with the initialize funtion.
  if (t->item == 0 && t->left == NULL && t->right == NULL) {
    return 1;
  }

  return 0;
}

int Full (struct tree_node *t)
{
    // Test if full

    //WHAT DOES THIS EVEN MEAN

    return 0;
}
