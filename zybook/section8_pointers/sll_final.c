
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_struct {
    char data[15];
    struct Node_struct* next;
} Node;

Node* start = NULL; // pointer to the beginning of the list

// Function prototypes
void menu(void);
void printList(void);
int isEmpty(void);
void setData(Node* node, char* value);
void insert(Node* newPtr);
char* deleteNode(char* value);
void printListReverse(Node* current);
void readData(void);
void writeData(void);
void emptyList(void);

// main function
int main(void) {
    Node* newPtr = NULL;
    char item[15];

    // Creating the starting node.
    start = (Node*)malloc(sizeof(Node));
    setData(start, "#");

    puts("An empty ordered Singly-Linked List created.");
    puts("********************************************");
    menu();
    printf("%s", "? ");
    unsigned int choice; // user's choice
    scanf("%u", &choice);
    fflush(stdin);

    while (choice != 8) {
        switch (choice) {
            case 1:
                printf("%s", "Enter a name (Maximum 14 characters): ");
                fgets(item, 15, stdin);
                if (item[strlen(item) - 1] == '\n')
                    item[strlen(item) - 1] = '\0';
                newPtr = (Node*)malloc(sizeof(Node)); // create node
                setData(newPtr, item);
                insert(newPtr); // insert item in list
                printList();
                break;
            case 2:
                if (!isEmpty()) {
                    printf("%s", "Enter character to be deleted: ");
                    fgets(item, 15, stdin);
                    if (item[strlen(item) - 1] == '\n')
                        item[strlen(item) - 1] = '\0';
                    char* found = deleteNode(item);
                    if (strcmp(found, "") != 0) {
                        printf("%s deleted.\n", item);
                        printList();
                    } else
                        printf("%s not found.\n\n", item);
                } else
                    puts("List is empty.\n");
                break;
            case 3:
                if (!isEmpty())
                    printList();
                else
                    puts("List is empty.\n");
                break;
            case 4:
                if (!isEmpty()) {
                    printf("The list in reverse order is:\nNULL <--> ");
                    printListReverse(start);
                    printf("NULL\n");
                } else {
                    puts("List is empty.\n");
                }
                break;
            case 5:
                readData();
                break;
            case 6:
                if (!isEmpty())
                    writeData();
                else
                    puts("List is empty.\n");
                break;
            case 7:
                if (!isEmpty())
                    emptyList();
                puts("List is empty.\n");
                break;
            default:
                puts("Invalid choice.\n");
                break;
        } // end switch
        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
        fflush(stdin);
    }

    puts("End of run.");
    return 0;
}

void menu(void) {
    puts("Enter your choice:\n"
         " 1 to insert an element into the list.\n"
         " 2 to delete an element from the list.\n"
         " 3 to print the list from the beginning.\n"
         " 4 to print the list from the end.\n"
         " 5 Read some words from input file and insert them to the list.\n"
         " 6 Write the list into the output file.\n"
         " 7 Empty the list.\n"
         " 8 to end.");
}

void printList(void) {
    Node* current = start;

    printf("The list is:\nNULL <--> ");
    while (current != NULL) {
        printf("%s <--> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

int isEmpty(void) {
    return start == NULL;
}

void setData(Node* node, char* value) {
    strncpy(node->data, value, 14);
    node->data[14] = '\0';
    node->next = NULL;
}

void insert(Node* newPtr) {
    Node* current = start;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->data, newPtr->data) < 0) {
        previous = current;
        current = current->next;
    }

    if (previous == NULL) {
        // Insert at the beginning
        newPtr->next = start;
        start = newPtr;
    } else {
        // Insert in the middle or at the end
        previous->next = newPtr;
        newPtr->next = current;
    }
}

char* deleteNode(char* value) {
    Node* current = start;
    Node* previous = NULL;

    while (current != NULL && strcmp(current->data, value) != 0) {
        previous = current;
        current = current->next;
    }

    if (current != NULL) {
        if (previous == NULL) {
            // Delete at the beginning
            start = current->next;
        } else {
            // Delete in the middle or at the end
            previous->next = current->next;
        }
        free(current);
        return current->data;
    } else {
        return "";
    }
}

void printListReverse(Node* current) {
    if (current == NULL) {
        return;
    }
    printListReverse(current->next);
    printf("%s <--> ", current->data);
}

void readData(void) {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        return;
    }

    char word[15];
    while (fscanf(inputFile, "%14s", word) == 1) {
        Node* newPtr = (Node*)malloc(sizeof(Node));
        setData(newPtr, word);
        insert(newPtr);
    }

    fclose(inputFile);
}

void writeData(void) {
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        return;
    }

    Node* current = start;
    while (current != NULL) {
        fprintf(outputFile, "%s\n", current->data);
        current = current->next;
    }

    fclose(outputFile);
}

void emptyList(void) {
    Node* current = start;
    Node* nextNode;

    while (current != NULL) {
        nextNode = current->next;
        free(current);
        current = nextNode;
    }

    start = NULL;
}