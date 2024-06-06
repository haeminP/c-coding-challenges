#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node_struct {
    char stringVal[16];
    struct Node_struct* next;
    struct Node_struct* previous;
} Node;

Node* start = NULL;
Node* end = NULL;

void menu(void);
void printList();
int isEmpty();
void setData(Node* node, int value);
void insert(Node* newPtr);
int* delete(int* value);
void printListReverse();
void emptyList();

int main(){
    Node* newPtr = NULL;
    char item[15];

    // Creating the starting/ending node
    start = (Node*)malloc(sizeof(Node));
    setData(start, "#");
    end = start;

    puts("An empty ordered doubly-linked list created.");
    puts("*************************");

    menu();
    printf("%s", "? ");
    unsigned int choice;
    scanf("%u", &choice);

    while(choice != 6){
        switch (choice){
            case 1:
                printf("%s", "Enter a name (Maximum 14 characters): ");
                fgets(item, 15, stdin);
                if (item[strlen(item) - 1] == '\n')
                    item[strlen(item) -1] == '\0';

                newPtr = (Node*)malloc(sizeof(Node));
                setData(newPtr, item);
                insert(newPtr);
                printList();
                printf("\n");
                break;
            case 3:
                printList();
        }

        menu();
        printf("%s", "? ");
        scanf("%u", &choice);
    }

    return 0;
}

// Display the menu options.
void menu(void){
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

void printList(){
    Node* currNode;
    currNode = (Node*)malloc(sizeof(Node));
    if(start == NULL)
        printf("Double linked list is empty.\n");

    else{
        currNode = start;
        while (currNode != NULL){
            printf("%d<=>", currNode->dataVal);
            currNode = currNode->next;
        }
    }


    
}

int isEmpty();

void setData(Node* node, int value){
    node->dataVal = value;
    node->previous = NULL;
    node->next = NULL;
}

void insert(Node* newPtr){
    newPtr->next = start->next;
    if (start->next != NULL)
        start->next->previous = newPtr;
    newPtr->previous = start;
    start->next = newPtr;

    Node* i;
    Node* j;
    int tempVal;
    for (i = start; i->next != NULL; i=i->next){
        for (j=i->next; j!= NULL; j=j->next){
            if(i->dataVal > j->dataVal){
                tempVal = j->dataVal;
                j->dataVal = i->dataVal;
                i->dataVal = tempVal;
            }
        }
    }
}

int* delete(int* value);
void printListReverse();
void emptyList();
