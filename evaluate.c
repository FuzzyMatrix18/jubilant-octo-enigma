#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define MAX_SIZE 100
struct Stack 
{
    int top;
    int array[MAX_SIZE];
};
void push(struct Stack* stack, int value) 
{
    if (stack->top == MAX_SIZE - 1) 
    {
        printf("Stack Overflow\n");
        exit(EXIT_FAILURE);
    }
    stack->array[++stack->top] = value;
}
int pop(struct Stack* stack) 
{
    if (stack->top == -1) 
    {
        printf("Stack Underflow\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top--];
}
int empty(struct Stack* stack) 
{
    return stack->top == -1;
}
int evaluateprefix(char expression[]) 
{
    struct Stack stack;
    stack.top = -1;

    int length = strlen(expression);

    for (int i = length - 1; i >= 0; i--)
     {
        char ch = expression[i];
        if (isdigit(ch)) 
        {
            push(&stack, ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            int operand1 = pop(&stack);
            int operand2 = pop(&stack);
            switch (ch) 
            {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}
int evaluatepostfix(char expression[]) 
{
    struct Stack stack;
    stack.top = -1;
    int length = strlen(expression);
    for (int i = 0; i < length; i++) 
    {
        char ch = expression[i];
        if (isdigit(ch)) 
        {
            push(&stack, ch - '0');
        } 
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') 
        {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            switch (ch) 
            {
                case '+':
                    push(&stack, operand1 + operand2);
                    break;
                case '-':
                    push(&stack, operand1 - operand2);
                    break;
                case '*':
                    push(&stack, operand1 * operand2);
                    break;
                case '/':
                    push(&stack, operand1 / operand2);
                    break;
            }
        }
    }
    return pop(&stack);
}
int main() 
{
    char expression[MAX_SIZE];
    printf("Enter a postfix expression: ");
    fgets(expression, sizeof(expression), stdin);
    printf("Result of postfix expression: %d\n", evaluatepostfix(expression));
    printf("Enter a prefix expression: ");
    fgets(expression, sizeof(expression), stdin);
    printf("Result of prefix expression: %d\n", evaluateprefix(expression));
    return 0;
}