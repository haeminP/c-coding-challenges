#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
    int dataVal;
    struct IntNode_struct* previousNodePtr;
    struct IntNode_struct* nextNodePtr;
} IntNode;


// Make head and last object as global

IntNode* headObj = NULL;        // Create intNode objects
IntNode* lastObj = NULL;


// Constructor
void IntNode_Create(IntNode* thisNode, int dataInit, IntNode* prevLoc, IntNode* nextLoc){
    thisNode->dataVal = dataInit;
    thisNode->previousNodePtr = prevLoc;
    thisNode->nextNodePtr = nextLoc;
}

/*
Insert newNode after node,
Before: thisNode -- next
After: thisNode -- newNode -- next
*/

void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode){
    newNode->nextNodePtr = thisNode->nextNodePtr;

    if (thisNode->next != NULL)
    {
        thisNode->nextNodePtr->previousNodePtr = newNode;
        // Check if the new node is added to the end of the linked list
    }
    newNode->previousNodePtr = thisNode;
    thisNode->nextNodePtr = newNode;

    // If the new node is added to the end of the linked list,
    // update the node lastObj
    if (thisNode->nextNodePtr == NULL)
        lastObj = newNode;
}


void IntNode_InsertBefore(IntNode* thisNode, IntNode* newNode){
    // Practice for the next session;
    // you might need to update the headobj instead of the lastobj
}


void IntNode_Delete(IntNode* thisNode){
    thisNode->previousNodePtr->nextNodePtr = thisNode->nextNodePtr;
    thisNode->nextNodePtr->previousNodePtr = thisNode->previousNodePtr;
    free(thisNode);
}


// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode)

// Grab location pointed by nextNodePtr

// Grab location pointed by previousNodePtr


int main(){


    IntNode* currObj = NULL;

    int i;

    // Create the very first node with the name headObj and lastObj
    headObj = (IntNode*)malloc(sizeof(IntNode));    // Front of nodes list
    IntNode_Create(headObj, -1, NULL, NULL);
    lastObj = headObj;

    // Create and insert a new node after headObj
    currObj = (IntNode*)malloc(sizeof(IntNode));    // Allocate memory for the new node
    IntNode_InsertAfter(headObj, currObj);


    // When insert a new node, make sure if you need to update the lastobj

    // video: 1:35


}