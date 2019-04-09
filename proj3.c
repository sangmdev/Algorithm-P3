#include <stdio.h>
#include <stdlib.h>

   //Tree Structure//
   //Sets up structure of a node, with left struct node, right struct node and data block//
struct node {
   	struct node* left;
        struct node* right;
   	int data;
};
   //function that makes a new node with data and NULL pointers to left child and right child//
struct node * newNode(int data){
        struct node *node = (struct node *)malloc(sizeof(struct node));
	node->left = NULL;
	node->right = NULL;
	node->data = data;

	return(node);
}

   //Display Menu//
void displayMenu(){
   	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
   	printf("Please select an option by entering choice # and a value.\n");
   	printf("1.TREE-INSERT\n");
   	printf("2.TREE-SEARCH\n");
   	printf("3.TREE-DELETE\n");
        printf("4.TRAVERSALS\n");
  	printf("5.Exit\n");
   	printf("~~~~~~~~~~~~~~~~~~~~~~~\n");
}

   //Tree Functions//
struct node* treeInsert(struct node* node, int z){
   //If the tree is empty, make a new node using function//
   if(node == NULL){
      return newNode(z);
   }
   if(z < node->data){
      node->left = treeInsert(node->left, z);
   }
   else if(z > node->data){
      node->right = treeInsert(node->right, z);
   }
   return node;
}
struct node * minValue(struct node* node){
   struct node* current = node;
   while(current->left != NULL)
      current = current->left;

   return current;
}

struct node* treeDelete(struct node* root, int z){
  if(root == NULL)
     return root;
  if(root->data > z)
     root->left = treeDelete(root->left,z);
  
  else if(z > root->data)
     root->right = treeDelete(root->right, z);
  else{
     if(root->left == NULL){
        struct node *temp = root->left;
	free(root);
	return temp;
     }
     else if(root->right == NULL){
        struct node *temp = root->left;
	free(root);
	return temp;
     }
     struct node* temp = minValue(root->right);
     root->data = temp->data;
     root->right = treeDelete(root->right, temp->data);
     }
     return root;
}


struct node* treeSearch(struct node* root, int z){
   printf("Path:\n");
   printf("%d\n", root->data);
   while(root != NULL && z!= root->data){
       if (z < root->data){
          if(root->left == NULL){
	     printf("Node not found!\n");
	     return root;
	  }
          else{
             root = root->left;
             printf("%d\n",root->data);
	  }
       }
       else{
          if(root->right == NULL){
	     printf("Node not found!\n");
	     return root;
	  }
	  else{
             root = root->right;
             printf("%d\n", root->data);
	  }
       }
   }
   return root;
}
  //Diplay Traversals//
void inorder(struct node *root){         //Left, Root, Right
    if(root != NULL){
       inorder(root->left);
       printf("%d \n", root->data);
       inorder(root->right);
       }
}
void postorder(struct node *root){        //Root, Left, Right
    if(root != NULL){
       printf("%d \n", root->data);
       postorder(root->left);
       postorder(root->right);
    }
}
void preorder(struct node *root){         //Left, Right, Root
   if(root != NULL){
      preorder(root->left);
      preorder(root->right);
      printf("%d \n", root->data);
   }
}

int main(){
   //Create integer array//
   int arr[] = {30, 10, 45, 38, 20, 50, 25, 33, 8, 12};
   struct node *root = NULL;
   root = treeInsert(root, 30);
   int choice, insertValue, value, done = 0;
   displayMenu();
   int i = 0;
   while(done != 1){
        insertValue = arr[i];
        scanf("%d", &choice);
	switch(choice){
	       case 1 : treeInsert(root, insertValue);
	                printf("Insertion of %d into tree successful!\n", insertValue);
			i++;
	   	        break;
               case 2 : printf("Please enter the node to search for:\n");
	                scanf("%d", &value);
	       		treeSearch(root, value);
	                break;
               case 3 : printf("Please enter the node to delete:\n");
	       		scanf("%d", &value);
			printf("Deletion of %d succesful!\n", value);
			treeDelete(root, value);
	                break;
	       case 4 : printf("Traversals:\n");
	                printf("----------------\n");
	                printf("Inorder:\n");
			inorder(root);
			printf("\nPostorder:\n");
			postorder(root);
			printf("\nPreorder:\n");
			preorder(root);
			break;
               case 5 : done = 1;
	                break;
               default: printf("Invalid input, please try again.\n");
	                break;
        }
	   displayMenu();
   }
   return 0;
}
