#include <stdio.h>
#include <stdlib.h>
 
struct stack 
{
    int size;
    int top;
    int *arr;
};
 
int isEmpty(struct stack *ptr)
{
    if (ptr->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
 
int isFull(struct stack *ptr)
{
    if (ptr->top == ptr->size - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void showelements(struct stack *s)
{
    printf("Stack-->\n");
    for(int i=s->top;i>=0;i--)
    {
        printf("%d\n",s->arr[i]);
    }
}

int push(struct stack *s,int data)
{
    if(isFull(s))
    {
        printf("Stack Overflow");
    }
    else
    {
        s->top++;
        s->arr[s->top]=data;
        return 1;
    }
}

int pop(struct stack *s)
{
    int val=0;
    if(isEmpty(s))
    {
        printf("Stack Underflow");
    }
    else
    {
        val=s->arr[s->top];
        s->top--;
    }
    printf("The popped value is %d\n",val);
    return val;
}

int peek(struct stack *s,int index)
{
    if(s->top-index+1<0)
    {
        printf("Invalid Position");
    }
    printf("The element %d is at position %d in Stack\n",s->arr[s->top-index+1],index);
}

int stackBottom(struct stack * s)
{
    int bottom= s->arr[0];
    return bottom;
}

int stackTop(struct stack * s)
{
   int stacktop=s->arr[s->top];
   return stacktop;
}

 
int main()
{
    struct stack *s = (struct stack *)malloc(sizeof(struct stack));
    s->size = 10;
    s->top = -1;
    s->arr = (int *)malloc(s->size * sizeof(int));
    push(s,99);
    push(s,98);
    push(s,97);
    push(s,96);
    push(s,95);
    push(s,94);
    push(s,93);
    
    stackBottom(s);
    printf("The stack bottom is %d\n",stackBottom(s));
    stackTop(s);
    printf("The stack top is %d\n",stackTop(s));

  //peek(s,2);
    
  /*pop(s);
    pop(s);
    pop(s);*/
    showelements(s);    
  
}
