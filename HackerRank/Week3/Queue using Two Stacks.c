#include <stdio.h>
#include <stdlib.h>

#define MAX 100000

typedef struct {
    int data[MAX];
    int top;
} Stack;

void init(Stack* s) {
    s->top = -1;
}

int isEmpty(Stack* s) {
    return s->top == -1;
}

void push(Stack* s, int value) {
    s->data[++s->top] = value;
}

int pop(Stack* s) {
    return s->data[s->top--];
}

int peek(Stack* s) {
    return s->data[s->top];
}

int main() {
    Stack stack1, stack2;
    init(&stack1);
    init(&stack2);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 1) {
            int x;
            scanf("%d", &x);
            push(&stack1, x); 
        } 
        else if (type == 2) {
           
            if (isEmpty(&stack2)) {
                while (!isEmpty(&stack1)) {
                    push(&stack2, pop(&stack1));
                }
            }
            pop(&stack2); 
        } 
        else if (type == 3) {
            if (isEmpty(&stack2)) {
                while (!isEmpty(&stack1)) {
                    push(&stack2, pop(&stack1));
                }
            }
            printf("%d\n", peek(&stack2)); 
        }
    }

    return 0;
}
