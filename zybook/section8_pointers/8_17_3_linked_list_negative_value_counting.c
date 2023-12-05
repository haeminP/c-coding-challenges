#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
    int dataVal;
    struct IntNode_struct* nextNodePtr;
} IntNode;

// Constructor
void IntNode_Create(IntNode* thisNode, int dataInit, IntNode* nextLoc)
{
    thisNode->dataVal = dataInit;
    thisNode->nextNodePtr = nextLoc;
}

// Insert newNode after node
void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode)
{
    IntNode* tempNext = NULL;

    tempNext = thisNode->nextNodePtr;
    thisNode->nextNodePtr = newNode;
    newNode->nextNodePtr = tempNext;
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode)
{
    return thisNode->nextNodePtr;
}

int IntNode_GetDataVal(IntNode* thisNode)
{
    return thisNode->dataVal;
}

int main(){

    IntNode* headObj = NULL;
    IntNode* currObj = NULL;
    IntNode* lastObj = NULL;
    int i;
    int negativeCntr;

    negativeCntr = 0;

    headObj = (IntNode*)malloc(sizeof(IntNode));    // Front of nodes list
    IntNode_Create(headObj, -1, NULL);
    lastObj = headObj;


    // Append 10 rand nums
    for (i = 0; i < 10; ++i){
        currObj = (IntNode*)malloc(sizeof(IntNode));
        IntNode_Create(currObj, (rand() % 21) - 10, NULL);
        IntNode_InsertAfter(lastObj, currObj);      // Append after current object
        lastObj = currObj;
    }

    currObj = headObj;  // Print the list
    while (currObj != NULL){
        printf("%d, ", IntNode_GetDataVal(currObj));
        currObj = IntNode_GetNext(currObj);
    }
    printf("\n");

    currObj = headObj;  // Count negative nums
    while (currObj != NULL){
        if(currObj->dataVal < 0)
            ++negativeCntr;
        currObj = IntNode_GetNext(currObj);
    }

    printf("Number of negatives: %d\n", negativeCntr);

    return 0;
}