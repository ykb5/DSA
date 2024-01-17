/*Q5. Write a C Program to Convert Infix to Postfix Expression using Stack.*/
#include<stdio.h>
#include<ctype.h>



void push(char stack[],int *top,char x)
{
    *top=*top+1;
    stack[*top] = x;
}

char pop(char stack[],int *top)
{
    if(*top == -1)
        return -1;
    else
    {
        char temp= stack[*top];
        *top=*top-1;
        return temp;
    }
}

int priority(char x)
{
    if(x == '(')
        return 0;
    if(x == '+' || x == '-')
        return 1;
    if(x == '*' || x == '/')
        return 2;
    if(x == '^')
    	return 3;
    return 0;
}

int main()
{
    printf("Himanshu Chauhan F 20011493\n");
    char stack[100];
    int top = -1;
    char exp[100];
    char *e, x;
    printf("Enter the expression : ");
    scanf("%s",exp);
    printf("\n");
    e = exp;
    
    while(*e !='\0')
    {
        if(isalnum(*e))
            printf("%c ",*e);
        else if(*e == '(')
            push(stack,&top,*e);
        else if(*e == ')')
        {
            while((x = pop(stack,&top)) != '(')
                printf("%c ", x);
        }
        else
        {
            while(priority(stack[top]) >= priority(*e))
            
                printf("%c ",pop(stack,&top));
            push(stack,&top,*e);
        }
        e++;
    }
    
    while(top != -1)
    {
        printf("%c ",pop(stack,&top));
    }return 0;
}//Errors reporting is most welcomed...
