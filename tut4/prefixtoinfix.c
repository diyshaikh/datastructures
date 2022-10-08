#include <stdio.h>
#include <malloc.h>
#define MAX 100
 struct node
{
    char * data;
    struct node * next;
}* stack= NULL;
char* pop(){
    struct node *next = stack->next;
    char * c = stack->data;
    // printf("%c\n",stack->data);
    stack = next;
    return c;
}
void push(char * n){
    struct node *next = (struct node *) malloc(sizeof(struct node));
    next->data = n;
    next->next = stack;
    stack = next;
}
void display(){
    struct node *temp;
    temp = stack;
    if (temp != NULL){
        while(temp != NULL){
            printf("data is : %s\n",temp->data);
            temp = temp->next;
        }
    }
}
void prefixtoinfix(char Infix[], char Prefix[])
{
    struct stack s;
    int i, j;
    char* e, x;

    i = 0, j = 0;
    e = Infix[i];
    while (e != '\0')
    {
        if (e == '(')
            push(&s,e);
        else if (isdigit(e) || isalpha(e))
        {
            Postfix[j++] = e;
        }

        else if (e == ')')
        {
            x = pop(&s);
            while (x != '(')
            {
                Postfix[j++] = x;
                x = pop(&s);
            }
        }else{
            x = pop(&s);
            while (prec(x) >= prec(e))
            {
                Postfix[j++] = x;
                x = pop(&s);
            }
            push(&s,x);
            push(&s,e);
        }
        e = Infix[++i];
    }

}
int main() {
    char infix[MAX], Pre[MAX];
    printf("Postfix operation is");
    scanf("%s", &Pre);
    prefixtoinfix(infix, Pre);
    printf("Infix conversion is: %s", infix);
}
