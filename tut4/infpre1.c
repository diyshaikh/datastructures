#include <stdio.h>
#include <ctype.h>
int max = 100;
struct stack{
    char data [max];
    int top;
};
int isempty(struct stack * s){
    if (s->top == -1)
        return (1);
    return (0);
}
int isfull(struct stack * s){
    if (s->top == max-1)
        return (1);
    return (0);
}
char pop(struct stack * s){
    if (!isempty(s)){
        char c=s->data[s->top];
        s->top--;
        return(c);
    }
}
void push(struct stack * s,int n){
    if(isempty(s))
        s->top =-1;
    if(!isfull(s)){
        s->top++;
        s->data[s->top] = n;
    }
}

void display(struct stack * s){
    int n= s->top;
    while(n > 0){
        printf("data is : %d\n",s->data[n]);
        n--;
    }
}
int prec(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if( x=='%')
        return(3);
    if( x=='^')
        return(4);
    return 0;
}
char top(struct stack * s){
    return (s->data[s->top]);
}
void InfixtoPostfix(char * Infix, char * Post)
{
    printf("Postfix is: ");
    struct stack s;
    char x, temp;
    int i=0, j=0;
    for (i=0, Infix[i]!="\0"; i++;)
    {
        temp = Infix[i];
        if(isalnum(temp))
        {
            Post[j++]=temp;
        }
        else if (temp == '(')
                push(&s, temp);
        else if (temp == ')')
        {
            while((x=pop(&s))!=')')
                Post[j++] = x;
        }
        else while(prec(temp)<=prec(top(&s))){
            Post[j++]=pop(&s);
            push(&s,temp);}
//         printf("Postfix is: %c",temp);
    }
    while(!isempty(&s))
    {
         Post[j++]=pop(&s);
         Post[j]='\0';
    }
    printf("Postfix conversion is: %s",Post);
}
int main()
{
    char infix[max], post[max];
    printf("Infix operation is");
    scanf("%s", infix);
    InfixtoPostfix(&infix, &post);
    printf("Postfix conversion is: %s",post);

}
