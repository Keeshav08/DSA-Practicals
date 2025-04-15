#include <stdio.h>
#include <conio.h>
#include <alloc.h>

typedef struct node {
    int info;
    struct node *next;
} node;

typedef struct {
    node *first;
} list;

list *createList() {
    list *l = (list *) malloc(sizeof(list));
    l->first = NULL;
    return l;
}

void insertAtBeginning(list *l, int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->info = value;
    newNode->next = l->first;
    l->first = newNode;
}

void insertAtEnd(list *l, int value) {
    node *newNode = (node *) malloc(sizeof(node));
    newNode->info = value;
    newNode->next = NULL;

    if (l->first == NULL) {
        l->first = newNode;
        return;
    }

    node *temp = l->first;
    while (temp->next != NULL) {
        temp = temp->next;
    }

    temp->next = newNode;
}

void insertAfter(list *l, int prevValue, int value) {
    node *temp = l->first;
    while (temp != NULL && temp->info != prevValue) {
        temp = temp->next;
    }

    if (temp != NULL) {
        node *newNode = (node *) malloc(sizeof(node));
        newNode->info = value;
        newNode->next = temp->next;
        temp->next = newNode;
    } else {
        printf("\nValue %d not found in list", prevValue);
    }
}

void deleteNode(list *l, int value) {
    node *temp = l->first, *prev = NULL;

    if (temp != NULL && temp->info == value) {
        l->first = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->info != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("\nValue %d not found", value);
        return;
    }

    prev->next = temp->next;
    free(temp);
}

void displayList(list *l) {
    node *temp = l->first;
    printf("\nLinked list: ");
    while (temp != NULL) {
        printf("%d -> ", temp->info);
        temp = temp->next;
    }
    printf("NULL\n");
}

void main() {
    clrscr();

    list *myList = createList();
    int value, prev, choice;

    do {
        printf("\n1. Insert at start");
        printf("\n2. Insert at end");
        printf("\n3. Insert in mid");
        printf("\n4. Delete node");
        printf("\n5. Display list");
        printf("\n6. Exit");

        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtBeginning(myList, value);
                break;

            case 2:
                printf("Enter value: ");
                scanf("%d", &value);
                insertAtEnd(myList, value);
                break;

            case 3:
                printf("Enter value: ");
                scanf("%d", &value);
                printf("Enter previous value: ");
                scanf("%d", &prev);
                insertAfter(myList, prev, value);
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                deleteNode(myList, value);
                break;

            case 5:
                displayList(myList);
                break;

            case 6:
                printf("Exiting");
                break;
        }
    } while (choice != 6);

    getch();
}
