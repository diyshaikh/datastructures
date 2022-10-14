#include <stdio.h>
# define max 24
void enqueue(int queue[],int rear,int front,int element){
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

int dequeue(int queue[],int rear,int front){
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

void display(int queue[],int rear,int front){
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
// enqueue(queue,front,rear,x);
// printf("the element dequed is %d \n",dequeue(queue,front,rear));
int main(){
    int choice=1,queue1[max],queue2[max],front1=-1,rear1=-1,front2=-1,rear2=-1,timeentery[24]= {0,0,0,3,3,3,6,6,6,9,9,9,12,12,12,15,15,15,18,18,18,21,21,21},timeexit[24], time=0,timechange=3,indexl[max], indext[max],a=0,b=0,tnext=0,t=0,n,i=0,x=0,y=0;
    char enteries[] = "lttllttlltltlttlltlllttt";
    while (i < 24){
        if (enteries[i]=="l"){
            indexl[x]=i;
            x++;
        }else{
            indext[y]=i;
            y++;
        }
        i++;
    }
    i=x=y=0;
    while (time<=24){
        while(timeentery[i]>=time){ //adding to queue
            if(enteries[i]=="l"){
                enqueue(queue1,front1,rear1,x);
                x++;i++;
            }else{
                enqueue(queue2,front2,rear2,y);
                y++;i++;
            }
        }
        if(tnext==time){
            while (t!=2){
                if(front1!=rear1){
                    n = dequeue(queue1,front1,rear1);
                    timeexit[indexl[n]]=time+timechange;
                    printf("the plane landing is L%d  arrived on\n",n,timeentery[indexl[n]]*5);
                    t+=1;
                }else{
                    n = dequeue(queue2,front2,rear2);
                    timeexit[indext[n]]=time+timechange;
                    printf("the plane taking off is T%d  arrived on\n",n,timeentery[indext[n]]*5);
                    t+=1;
                }
            }
            tnext+=timechange;
        }
        time+=1;
    }
    return 0;
}
