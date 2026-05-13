#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

double stack[MAX_STACK_SIZE];
int top = -1;

void push(double val) {
    if (top >= MAX_STACK_SIZE - 1) {
        printf("Error: Stack Overflow\n");
        return;
    }
    stack[++top] = val;
}

double pop() {
    if (top < 0) {
        printf("Error: Stack Underflow\n");
        return 0.0;
    }
    return stack[top--];
}

void printTop() {
    if (top < 0) {
        printf("Error: Stack is empty\n");
    } else {
        printf("Result: %.2lf\n", stack[top]);
    }
}

int main() {
    printf("Reverse Polish Calculator Started.\n");
    char instruction;
    double operand1, operand2, inputValue;
    printf("Instructions: '?' to input, '+', '-', '*', '/' for operations, '=' to print.\n");
    printf("Type 'q' to quit.\n\n");
    while (1) {
        scanf(" %c", &instruction);
        if (instruction == 'q' || instruction == 'Q') { break; }
        switch (instruction) {
            case '?':
                scanf("%lf", &inputValue);
                push(inputValue);
                break;
            case '+':
                operand2 = pop();
                operand1 = pop();
                push(operand1 + operand2);
                break;
            case '-':
                operand2 = pop();
                operand1 = pop();
                push(operand1 - operand2);
                break;
            case '*':
                operand2 = pop();
                operand1 = pop();
                push(operand1 * operand2);
                break;
            case '/':
                operand2 = pop();
                operand1 = pop();
                if (operand2 != 0) { push(operand1 / operand2); } 
                else { printf("Error: Division by zero\n"); push(operand1); push(operand2); }
                break;
            case '=':
                printTop();
                break;
            default:
                printf("Invalid instruction: %c\n", instruction);
        }
    }
    return 0;
}