#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define SIZE 100
char stack[SIZE];
int top = -1;
char input[SIZE];
int i = 0;
char precedence(char a, char b) {
    if (a == '$' && b == '$') return 'A'; // accept
    if (a == '(' && b == ')') return '=';
    if (a == '(' || a == '+' || a == '*' || a == '$') {
        if (b == '+' || b == ')') return '>';
        if (b == '*' || b == 'i' || b == '(') return '<';
    }
    if (a == '*') {
        if (b == '+' || b == '*' || b == ')' || b == '$') return '>';
        if (b == 'i' || b == '(') return '<';
    }
    if (a == '+') {
        if (b == '+' || b == ')' || b == '$') return '>';
        if (b == 'i' || b == '*' || b == '(') return '<';
    }
    if (a == 'i') {
        if (b == '+' || b == '*' || b == ')' || b == '$') return '>';
    }
    if (a == ')') return '>';
    return '?';  // invalid case
}

// Push to stack
void push(char c) {
    stack[++top] = c;
}

// Pop from stack
void pop() {
    if (top >= 0) top--;
}

// Get top terminal from stack (skip non-terminals)
char top_terminal() {
    for (int j = top; j >= 0; j--) {
        if (stack[j] != 'E') return stack[j];
    }
    return '$';  // default
}

int main() {
    printf("Enter the expression (use 'i' for id): ");
    scanf("%s", input);
    strcat(input, "$");

    push('$');

    char a, b;

    a = input[i];

    while (1) {
        b = top_terminal();

        char relation = precedence(b, a);

        if (relation == '<' || relation == '=') {
            push(a);
            i++;
            a = input[i];
        } else if (relation == '>') {
            // Reduce: Replace id, E+E, E*E, (E) with E
            if (stack[top] == 'i') {
                pop();
                push('E');
            } else if (stack[top] == 'E' && stack[top - 1] == '+' && stack[top - 2] == 'E') {
                pop(); pop(); pop();
                push('E');
            } else if (stack[top] == 'E' && stack[top - 1] == '*' && stack[top - 2] == 'E') {
                pop(); pop(); pop();
                push('E');
            } else if (stack[top] == ')' && stack[top - 1] == 'E' && stack[top - 2] == '(') {
                pop(); pop(); pop();
                push('E');
            } else {
                printf("? Invalid syntax during reduction\n");
                exit(1);
            }
        } else if (relation == 'A') {
            if (stack[top] == 'E' && stack[top - 1] == '$' && a == '$') {
                printf("? Expression is valid (Accepted).\n");
                break;
            } else {
                printf("? Syntax error at accept check.\n");
                break;
            }
        } else {
            printf("? Invalid operator precedence between '%c' and '%c'\n", b, a);
            break;
        }
    }

    return 0;
}
