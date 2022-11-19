#include<stdlib.h>
#include<stdio.h>
struct node {
    int key;
    struct node *left, *right;
};

// A utility function to create a new BST node
struct node *newNode(int item) {
    struct node *temp = (struct node *) malloc(sizeof(struct node));
    temp->key = item;
    temp->left = temp->right = NULL;
    return temp;
}


/* A utility function to insert a new node with given key in BST */
struct node* insert(struct node* node, int key) {
    /* If the tree is empty, return a new node */
    if (node == NULL)
        return newNode(key);

    /* Otherwise, recur down the tree */
    if (key < node->key)
        node->left = insert(node->left, key);
    else if (key > node->key)
        node->right = insert(node->right, key);

    /* return the (unchanged) node pointer */
    return node;
}
/* Given a binary search tree and a key, this function deletes the key
 and returns the new root */
struct node* deleteNode(struct node* root, int key) {
    // base case
    if (root == NULL)
        return root;

    // If the key to be deleted is smaller than the root's key,
    // then it lies in left subtree
    if (key < root->key)
        root->left = deleteNode(root->left, key);

    // If the key to be deleted is greater than the root's key,
    // then it lies in right subtree
    else if (key > root->key)
        root->right = deleteNode(root->right, key);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node with only one child or no child
        if (root->left == NULL) {
            struct node *temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            struct node *temp = root->left;
            free(root);
            return temp;
        }

        // node with two children: Get the inorder successor (smallest
        // in the right subtree)
        struct node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->key = temp->key;

        // Delete the inorder successor
        root->right = deleteNode(root->right, temp->key);
    }
    return root;
}
int hightoftree(struct node *root)
{
    int max;
    if (root!=NULL)
    {
        /* Finding the height of left subtree. */
        int leftsubtree = heightoftree(root->left);
        /* Finding the height of right subtree. */
        int rightsubtree = heightoftree(root->right);
        if (leftsubtree > rightsubtree)
        {
            max = leftsubtree + 1;
            return max;
        }
        else
        {
            max = rightsubtree + 1;
            return max;
        }
    }
}
/*
 * Function to print all the nodes left to right of the current level
 */
void currentlevel(struct node *root, int level)
{
    if (root != NULL)
    {
        if (level == 1)
        {
            printf("%d ", root->info);
        }
        else if (level > 1)
        {
            currentlevel(root->left, level-1);
            currentlevel(root->right, level-1);
        }
    }
}
void mirrorimage(struct node* root)
{
  if (root != NULL)
    {
        struct node* temp;
        /*first traversing the left subtree */
        mirrorimage(root->left);
        /* Traversing the right subtree. */
        mirrorimage(root->right);

        /* swap the left and right child of all the nodes to create
         * a mirror image of a tree
         */

        temp = root->left;
        root->left  = root->right;
        root->right = temp;

    }
}
// Driver Program to test above functions
int main() {
    struct  node * Root;
    Root= NULL;
    int ch = 1,node,data;
    printf("Enter your choice\n1.Insert\n2.Delete\n3.Level wise Display.\n4.Mirror Image\n5.Height of the Tree\n6.Exit \n");

   	while(ch!=6){
	printf("Enter your choice");
    scanf("%d",&ch);
    switch(ch)
    {
        case 1:
            printf("Insert node \n");
            scanf("%d",&data);
            Root = insertNode(Root,data);
            printf("\n");
            break;

        case 2:
            printf("\n Delete data: \n");
            Root = deleteNode(root ,data);
            printf("\n");
            break;

        case 3:
            printf("\nLevel wise Display: \n");
            // leve
            printf("\n");
            break;

        case 4:
            printf("\nMirror Image: \n");
            mirrorimage(Root);
            printf("\n");
            break;

        case 5:
            printf("\nHight of the tree: \n");
            data = hightoftree(root);
            printf("Hight of the tree is %d\n",data);
            break;

        case 6:
            printf("\nExit!!");
            break;

        default:
            printf("\nInvalid Choice!!");
            break;

    }
    }
}
