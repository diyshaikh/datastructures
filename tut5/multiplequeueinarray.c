#include <stdio.h>
/*
struct quelist{
    int que[],front[],rear[];
}
void enqueue(int element){
    if(front==-1 && rear==-1){
        front=0;
        rear=0;
        queue[rear]=element;
    }
    else if((rear+1)==max){
        printf("Queue is overflow..");
    }
    else{
        rear=rear+1;
        queue[rear]=element;
    }
}

int dequeue(){
    if((front==-1) && (rear==-1)){
        printf("\nQueue is underflow..");
    }
 else if(front==rear){
    int r = queue[front];
    front=-1;
    rear=-1;
    return r;
}
else{
    int r = queue[front];
    front=front+1;
    return r;
}
return 0;
}

void display(){
    int i=front;
    if(front==-1 && rear==-1){
        printf("\n Queue is empty..");
    }
    else{
        printf("\nElements in a Queue are :");
        while(i<=rear){
            printf("%d,", queue[i]);
            i=(i+1)%max;
        }
    }
}
*/
int returnvaluepair(x,m){
    if (x == m & x%2 ==0){
        return x;
    }else if (x%2 ==0){
        return x+1;
    }else{
        return x-1;
    }
}
int main(){
    int choice=1,x,y,m,n;
    printf("Enter size - "); // n = size , m is number of arrays
    scanf("%d", &m);
    printf("Enter n - ");
    scanf("%d", &n);
    n-=1;
    m-=1;
    int queue[m],front[n],rear[n];
    printf("\n Press 1: Insert ");
    printf("\n Press 2: Delete ");
    printf("\n Press 3: Display");
    while(choice<4 && choice!=0){
        printf("Enter your choice - ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("enter the array in which element is to be inserted - ");
                scanf("%d", &x);
                printf("enter the element which is to be inserted - ");
                scanf("%d", &y);x--;
                enqueue(x,y,queue,front,rear,n,m);
                break;
            case 2:
                printf("enter the array from which element is to be removed - ");
                scanf("%d", &x);x--;
                printf("the element dequed is %d \n",dequeue(x,queue,front,rear,n,m));
                break;
            case 3:
            display(queue,front,rear,n,m);
        }
    }
    return 0;
}
