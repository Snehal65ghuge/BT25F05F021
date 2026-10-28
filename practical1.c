#include <stdio.h>
#include <ctype.h>

#define MAX 100

int stack[MAX];
int top = -1;

// Push element into stack
void push(int value) {
    stack[++top] = value;
}

// Pop element from stack
int pop() {
    return stack[top--];
}

// Evaluate postfix expression
int evaluatePostfix(char exp[]) {

    int i;
    int a, b;

    for (i = 0; exp[i] != '\0'; i++) {

        // If operand, push it
        if (isdigit(exp[i])) {
            push(exp[i] - '0');
        }

        // If operator
        else {
            b = pop();
            a = pop();

            switch (exp[i]) {

                case '+':
                    push(a + b);
                    break;

                case '-':
                    push(a - b);
                    break;

                case '*':
                    push(a * b);
                    break;

                case '/':
                    push(a / b);
                    break;
            }
        }
    }

    return pop();
}

int main() {

    char exp[MAX];

    printf("Enter postfix expression: ");
    scanf("%s", exp);

    printf("Result = %d", evaluatePostfix(exp));

    return 0;
}