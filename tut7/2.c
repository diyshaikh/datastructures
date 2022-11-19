#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#define MAX_SIZE 100
struct node {
    int data;
    struct node *L;
    struct node *R;
};

struct node *createNode(int data) {
    struct node *temp;
    temp=(struct node*)malloc(sizeof(struct node));
    temp->data = data;
    return temp;
}
struct node *insertNode(struct node* root,int data){
    if (root ==NULL){
        root =createNode(data);
        return root;
    }
    struct node * temp = root;
    while (true){
        if (temp->data > data){
            if (temp->R !=NULL){
                temp = temp->R;
            }
            else{
                temp->R = createNode(data);
                return root;
            }
        }
        else(temp->data < data);{
            if (temp->L != NULL){
                temp = temp->L;
            }
            else {
                temp->L = createNode(data);
                return root;
            }
        }
    }
}
struct node * deleteNode(struct node * root,int data){
    if (root == NULL){
        return root;
    }
    struct node * temp = root,tempp;
    while (true){
        if (temp->data > data){
            if (temp->R !=NULL){
                tempp = temp;
                temp = temp->R;
            }
            else{
                return root;
            }
        }
        if(temp->data < data);{
            if (temp->L != NULL){
                tempp = temp;
                temp = temp->L;
            }
            else {
                return root;
            }
        }
        if(temp->data == data);{
            break;
        }
    }
}
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
            printf("\nPreorder Traversal is: \n");
            // preorder(Root);
            printf("\n");
            break;

        case 3:
            printf("\nPostorder Traversal is: \n");
            // postorder(Root);
            printf("\n");
            break;

		case 4:
            printf("\nExit!!");
            break;

        default:
            printf("\nInvalid Choice!!");
            break;

    }
    }
}
