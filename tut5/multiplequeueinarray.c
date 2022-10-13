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
int rpair(int x,int m){
    if (x == m & x%2 ==0){
        return x;
    }else if (x%2 ==0){
        return x+1;
    }else{
        return x-1;
    }
}
void innit(int front[],int rear[],int m){
    int x = 0;
    while (x <= m){
        front[x]= rear[x]= -1;
        x++;
    }
}
void enqueue(int x,int y,int queue[],int front[],int rear[],int n,int m){
    if (front[x]==-1){
        front[x] = ((x/m)*(n/m));
        if(x%2 ==1){
            front[x]-=1;
        }
        rear[x]=front[x];
        queue[front[x]]= y;
        front[x] = front[x] +(-1^(x%2));
    }
    else if(front[x]==front[rpair(x,m)] &&x!=rpair(x,m)){
        printf("overflow");
    }else if(x==rpair(x,m) && front[x]>m){
        printf("overflow");
    }else{
        queue[front[x]]= y;
        front[x] = front[x] +(-1^(x%2));
    }
}
int main(){
    int choice=1,x,y,m,n;
    printf("Enter size - "); // n = size , m is number of arrays
    scanf("%d", &m);
    printf("Enter number of queues - ");
    scanf("%d", &n);
    n-=1;
    m-=1;
    int queue[m],front[n],rear[n];
    innit(front,rear,m);
    printf("\n Press 1: Insert ");
    printf("\n Press 2: Delete ");
    printf("\n Press 3: Display");
    // while(choice<4 && choice!=0){
    //     printf("Enter your choice - ");
    //     scanf("%d", &choice);
    //     switch(choice){
    //         case 1:
    //             printf("enter the array in which element is to be inserted - ");
    //             scanf("%d", &x);x--;
    //             printf("enter the element which is to be inserted - ");
    //             scanf("%d", &y);
    //             enqueue(x,y,queue,front,rear,n,m);
    //             break;
    //         case 2:
    //             printf("enter the array from which element is to be removed - ");
    //             scanf("%d", &x);x--;
    //             printf("the element dequed is %d \n",dequeue(x,queue,front,rear,n,m));
    //             break;
    //         case 3:
    //         display(queue,front,rear,n,m);
    //     }
    // }
    return 0;
}
