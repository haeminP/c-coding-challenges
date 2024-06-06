#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_struct {
    char data[15];
    struct Node_struct* next;
    struct Node_struct* prev;
} Node;

Node* start = NULL; // pointer to the beginning of the list
Node* end = NULL;   // pointer to the last node of the list

// Function prototypes
void menu(void);
void printList(void);
int isEmpty(void);
void setData(Node* node, char* value);
void insert(Node* newPtr);
char* delete(char* value);
void printListReverse(void);
void readData(void);
void writeData(void);
void emptyList(void);

// main function
int main(void) {
    Node* newPtr = NULL;
    char item[15];

    // Creating the starting/ending node.
    start = (Node*)malloc(sizeof(Node));
    setData(start, "#");
    end = start;

    puts("An empty ordered Doubly-LinkedList created.");
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
                    char* found = delete(item);
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
                if (!isEmpty())
                    printListReverse();
                else
                    puts("List is empty.\n");
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
    node->prev = NULL;
}

void insert(Node* newPtr) {
    Node *current;

    /** 
     * If the two pointer variables (start and end) were left as null instead of the
     * '#' character being set in the main function, then this if statment would just 
     * be 'if(start == NULL)', but the instructions say 'Dont change any code', so oh well I guess
    */
    if( start == NULL || strcmp(start->data,"#") == 0){
        newPtr->prev = NULL;
        newPtr->next = NULL;
        start = newPtr;
        return;
    }

    current = start;

    while(current != NULL){
        int nodeStringCheck = strcasecmp(newPtr->data, current->data);
        
        if(nodeStringCheck <= 0){
            newPtr->next = current;
            newPtr->prev = current->prev;
            if(current->prev != NULL){
                current->prev->next = newPtr;  
            }
            current->prev = newPtr;
            start = (newPtr->prev == NULL ? newPtr : start);
            return;
        }
        
        else if(current->next == NULL){
            newPtr->prev = current;
            newPtr->next = NULL;
            current->next = newPtr;
            end = newPtr;
            return;
        }

        current = current->next;
    }
}

char* delete(char* value) {
    Node *current;
    current = start;

    while(current != NULL && strcmp(current->data, value) != 0){
        current = current->next;
    }

    if(current == NULL){
        return "\0";
    }

    if(current == start){
        start = current->next;
        if(start != NULL){
            start->prev = NULL;
        }
        free(current);
        return value;
    }

    if(current == end){
        end = current->prev;
        if(end != NULL){
            end->next = NULL;
        }
        free(current);
        return value;
    }

    current->prev->next = current->next;
    current->next->prev = current->prev;
    free(current);
    return value;
}


void printListReverse(void) {
    Node* current = end;

    printf("The list in reverse order is:\nNULL <--> ");
    while (current != NULL) {
        printf("%s <--> ", current->data);
        current = current->prev;
    }
    printf("NULL\n");
}

void readData(void) {
    FILE* inputFile = fopen("input.txt", "r");
    if (inputFile == NULL) {
        return;
    }

    char word[15];
    while (fscanf(inputFile, "%14s", word) != EOF) {
        Node* newPtr = (Node*)malloc(sizeof(Node));
        setData(newPtr, word);
        insert(newPtr);
    }

    fclose(inputFile);
}

void writeData(void) {
    FILE* outputFile = fopen("output.txt", "w");
    if (outputFile == NULL) {
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
    end = NULL;
}