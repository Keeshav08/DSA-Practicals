#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node {
    int data;
    struct Node* next;
};

// Stack structure
struct Stack {
    struct Node* top;
};

// Initialize stack
void initStack(struct Stack* stack) {
    stack->top = NULL;
}

// Check if stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == NULL;
}

// Push operation
void push(struct Stack* stack, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
    printf("%d pushed into stack\n", value);
}

// Pop operation
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack cannot pop\n");
        return -1;
    }
    struct Node* temp = stack->top;
    int value = temp->data;
    stack->top = stack->top->next;
    free(temp);
    printf("%d popped from stack\n", value);
    return value;
}

// Peek operation
int peek(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack cannot pop\n");
        return -1;
    }
    return stack->top->data;
}

// Main function with menu
int main() {
    struct Stack stack;
    initStack(&stack);

    int choice, value;

    while (1) {
        printf("\nStack operations menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value to push: ");
                scanf("%d", &value);
                push(&stack, value);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                value = peek(&stack);
                if (value != -1)
                    printf("Top element is: %d\n", value);
                break;
            default:
                printf("Invalid choice\n");
        }
    }

    return 0;
}
