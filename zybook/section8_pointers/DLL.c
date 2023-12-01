#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
   int dataVal;
   struct IntNode_struct* nextNodePtr;
   struct IntNode_struct* previousNodePtr;
} IntNode;

IntNode* headObj  = NULL; // Create intNode objects
IntNode* lastObj  = NULL;

// Constructor
void IntNode_Create(IntNode* thisNode, int dataInit, IntNode* nextLoc, IntNode* previousLoc) {
   thisNode->dataVal = dataInit;
   thisNode->nextNodePtr = nextLoc;
   thisNode->previousNodePtr = previousLoc;
}

void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode) {   
	newNode->nextNodePtr = thisNode->nextNodePtr;
	if (thisNode->nextNodePtr != NULL)			// If the new node is adding to the end of the linkedlist
		thisNode->nextNodePtr->previousNodePtr = newNode;

	newNode->previousNodePtr = thisNode;
	thisNode->nextNodePtr = newNode;

	// If the new node is adding to the end of the linkedlist, update the node lastObj
	if (thisNode->nextNodePtr == NULL)
		lastObj = newNode;
}

void IntNode_InsertBefore(IntNode* thisNode, IntNode* newNode) {   
	newNode->previousNodePtr = thisNode->previousNodePtr;
   if(thisNode->previousNodePtr != NULL)    // if the new node is adding to the beginning of the list
         thisNode->previousNodePtr->nextNodePtr = newNode;
   
   newNode->nextNodePtr = thisNode;
   thisNode->previousNodePtr = newNode;

   // If the new node is added to the beginning of the linkedlist, update the node headOjb
   if(newNode->previousNodePtr == NULL)
      headObj = newNode;
}

void IntNode_Delete(IntNode* thisNode) {
	thisNode->previousNodePtr->nextNodePtr = thisNode->nextNodePtr;
	thisNode->nextNodePtr->previousNodePtr = thisNode->previousNodePtr;
	free(thisNode);
}


void IntNode_Clear()    // Clear the list completely

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode) {
   printf("%d\n", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr
IntNode* IntNode_GetNext(IntNode* thisNode) {
   return thisNode->nextNodePtr;
}

// Grab location pointed by previousNodePtr
IntNode* IntNode_GetPrevious(IntNode* thisNode) {
   return thisNode->previousNodePtr;
}

int main(void) {
   IntNode* currObj  = NULL;

   // Create the very first node with the name headObj and lastObj
   headObj = (IntNode*)malloc(sizeof(IntNode)); // Front of nodes list
   IntNode_Create(headObj, -1, NULL,NULL);
   lastObj = headObj;
     
   // Create and insert a new node after headObj
   currObj = (IntNode*)malloc(sizeof(IntNode)); // Allocate memory for the new node
   IntNode_Create(currObj, 8, NULL,NULL);
   IntNode_InsertAfter(headObj,currObj);

   // Create and insert a new node after headObj
   currObj = (IntNode*)malloc(sizeof(IntNode)); // Allocate memory for the new node
   IntNode_Create(currObj, 5, NULL,NULL);
   IntNode_InsertAfter(headObj,currObj);

   // Create and insert a new node after lastObj
   currObj = (IntNode*)malloc(sizeof(IntNode)); // Allocate memory for the new node
   IntNode_Create(currObj, 11, NULL,NULL);
   IntNode_InsertAfter(lastObj,currObj);

   currObj = headObj;                           // Print the list from the head node
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetNext(currObj);
   }

   puts("---------");
  
   currObj = lastObj;                           // Print the list from the last node
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetPrevious(currObj);
   }

  puts("---------");
  
   currObj = headObj->nextNodePtr;
   IntNode_Delete(currObj);

   currObj = headObj;                           // Print the list from the head node
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetNext(currObj);
   }
  
   return 0;
}