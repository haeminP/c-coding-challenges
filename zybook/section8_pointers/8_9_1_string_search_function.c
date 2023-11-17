#include <stdio.h>
#include <string.h>

int main(){

    char orgName[100] = "The Dept. of Redundancy Dept.";
    char newText[100];
    char* subString = NULL;

    if (strchr(orgName, 'D') != NULL){      // 'D' exists in orgName?
        subString = strchr(orgName, 'D');   // Points to first 'D'
        strcpy(newText, subString);         // newText now "Dept. of Redundancy Dept."
    }

    if (strrchr(orgName, 'D') != NULL){
        subString = strrchr(orgName, 'D');  // Points to last 'D'
        strcpy(newText, subString);         // newText now "Dept."
    }

    subString = strchr(orgName, "Dept");    // Points to first D
    if (subString != NULL) {
        strcpy(newText, subString);     // newText now "Dept. of Redundancy Dept."
    }
    return 0;
}