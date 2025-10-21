#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define MAX 100

char stack[MAX];
int top = -1;


void push(char c) {
    stack[++top] = c;
}
char pop() {
    return stack[top--];
}
char peek() {
    return stack[top];
}
int isEmpty() {
    return top == -1;
}


int precedence(char op) {
    if(op == '^') return 3;
    if(op == '*' || op == '/') return 2;
    if(op == '+' || op == '-') return 1;
    return 0;
}


void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char c;
    while(infix[i]) {
        c = infix[i];
        if(isalnum(c)) {
            postfix[j++] = c;
        } else if(c == '(') {
            push(c);
        } else if(c == ')') {
            while(!isEmpty() && peek() != '(') {
                postfix[j++] = pop();
            }
            pop(); 
        } else {
            while(!isEmpty() && precedence(peek()) >= precedence(c)) {
                postfix[j++] = pop();
            }
            push(c);
        }
        i++;
    }
    while(!isEmpty()) {
        postfix[j++] = pop();
    }
    postfix[j] = '\0';
}


int evalPostfix(char* postfix) {
    int evalStack[MAX], evalTop = -1;
    int i, op1, op2;
    for(i = 0; postfix[i]; i++) {
        if(isdigit(postfix[i])) {
            evalStack[++evalTop] = postfix[i] - '0';
        } else {
            op2 = evalStack[evalTop--];
            op1 = evalStack[evalTop--];
            switch(postfix[i]) {
                case '+': evalStack[++evalTop] = op1 + op2; break;
                case '-': evalStack[++evalTop] = op1 - op2; break;
                case '*': evalStack[++evalTop] = op1 * op2; break;
                case '/': evalStack[++evalTop] = op1 / op2; break;
            }
        }
    }
    return evalStack[evalTop];
}


int main() {
    int choice;
    char infix[MAX], postfix[MAX];
    while(1) {
        printf("1. Infix to Postfix conversion \n");
        printf("2. Evaluation of postfix expression\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice) {
            case 1:
                printf("Enter infix expression: ");
                scanf("%s", infix);
                infixToPostfix(infix, postfix);
                printf("Postfix: %s\n", postfix);
                break;
            case 2:
                printf("Enter postfix expression: ");
                scanf("%s", postfix);
                printf("final result is : %d\n", evalPostfix(postfix));
                break;
            case 3:
                printf("Exiting\n");
                return 0;
            default:
                printf("invalid choice \n");
        }
    }
}



