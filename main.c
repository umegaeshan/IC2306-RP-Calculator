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