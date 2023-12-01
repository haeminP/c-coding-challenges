   currObj = lastObj;                           // Print the list from the last node
   while (currObj != NULL) {
      IntNode_PrintNodeData(currObj);
      currObj = IntNode_GetPrevious(currObj);
   }

   currObj = headObj->nextNodePtr;
   IntNode_Delete(currObj);