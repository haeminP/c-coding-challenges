#include <stdio.h>
#include <stdlib.h>

typedef struct IntNode_struct {
    int dataVal;
    struct IntNode_struct* nextNodePtr;
} IntNode;

// Allocate a node for initData
IntNode* IntNode_Create(int initData)
{
    IntNode* newNode = NULL;
    newNode = (IntNode*)malloc(sizeof(IntNode));
    
    newNode->dataVal = initData;
    newNode->nextNodePtr = NULL;

    return newNode;
}

// Insert newNode after node
void IntNode_InsertAfter(IntNode* thisNode, IntNode* newNode)
{
    IntNode* tempNext = NULL;
    tempNext = thisNode->nextNodePtr;
    thisNode->nextNodePtr = newNode;
    newNode->nextNodePtr = tempNext;
}

// Print dataVal
void IntNode_PrintNodeData(IntNode* thisNode)
{
    printf("%d ", thisNode->dataVal);
}

// Grab location pointed by nextNodePtr;
IntNode* IntNode_GetNext(IntNode* thisNode)
{
    return thisNode->nextNodePtr;
}

// Return the length of the list
int IntNode_Length(IntNode* firstNode)
{
    int length = 0;
    IntNode* currentNode;
    currentNode = firstNode;

    while (currentNode != NULL){
        ++length;
        currentNode = currentNode->nextNodePtr;
    }
    return length;
}

// Return the Nth element of the list. First node is 1.
IntNode* IntNode_GetNth(IntNode* firstNode, int pos)
{
    IntNode* currNode;
    currNode = (IntNode*)malloc(sizeof(IntNode));

    currNode = firstNode;
    for (int i = 1; i < pos; ++i)
    {
        currNode = IntNode_GetNext(currNode);
    }

    return currNode;

}

// Print the entire list starting at firstNode
void IntNode_PrintList(IntNode* firstNode)
{
    IntNode* currNode;
    currNode = (IntNode*)malloc(sizeof(IntNode));

    currNode = firstNode;

    while (currNode != NULL){
        IntNode_PrintNodeData(currNode);
        currNode = IntNode_GetNext(currNode);
    }
}

// Sum the numbers in the list
int IntNode_SumList(IntNode* firstNode)
{
    int sum = 0;
    IntNode* currNode;
    currNode = (IntNode*)malloc(sizeof(IntNode));

    currNode = firstNode;


    while(currNode != NULL)
    {
        sum += currNode->dataVal;
        currNode = IntNode_GetNext(currNode);
    }

    return sum;
}

int main(){
    IntNode* firstNode = NULL;
    IntNode* lastNode = NULL;
    IntNode* newNode = NULL;
    IntNode* curNode = NULL;

    int listSize;           // how many integers to read
    int increment;          // increment between consecutive node values
    int firstNum;           // first node value

    // New node for newNum will be inserted after position newPos (first node = 1)
    int newPos;
    int newNum;

    int i;

    // Input:
    scanf("%d %d %d %d %d", &listSize, &firstNum, &increment, &newNum, &newPos);

    // Create the list
    firstNode = IntNode_Create(firstNum);
    // Create node for first value
    // New list has just one node, so lastNode is same as firstNode
    lastNode = firstNode;

    // Add nodes to the list
    for (i = 1; i < listSize; ++i){
        // Create a new node for the next number
        newNode = IntNode_Create((increment * i) + firstNum);
        // Add the node to the end of the list
        IntNode_InsertAfter(lastNode, newNode);
        lastNode = newNode;
    }

    // Print the list
    printf("%d element list: ", IntNode_Length(firstNode));
    IntNode_PrintList(firstNode);
    printf("\n");

    // If list length > 1 print the list starting at the second element
    printf("From second element: ");
    if (IntNode_Length(firstNode) <= 1){
        printf("No second element\n");
    }
    else {
        IntNode_PrintList(IntNode_GetNext(firstNode));
        printf("\n");
    }

    // Print the sum
    printf("sum: %d\n", IntNode_SumList(firstNode));

    // Add a node after node newPos
    newNode = IntNode_Create(newNum);
    curNode = IntNode_GetNth(firstNode, newPos);
    IntNode_InsertAfter(curNode, newNode);
    printf("New list: ");
    IntNode_PrintList(firstNode);
    printf("\n");


    return 0;
}