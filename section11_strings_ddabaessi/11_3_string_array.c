#include <stdio.h>

int main()
{
    /* Arrays of Character Strings */

    const char* mythings[5] = {
        "Dancing in the rain",
        "Counting apples",
        "Watching movies with friends",
        "Writing sad letters",
        "Studying the C language"
    };

    char yourthings[5][40] = {
        "Studying the C++ language",
        "Eating",
        "Watching Netflix",
        "Walking around till dark",
        "Deleting spam emails"
    };

    const char* temp1 = "Dancing in the rain";
    const char* temp2 = "Studying the C++ language";

    // mythings[0] and temp1 will have the same address:
    // why?
    // mythings and temp1 are just pointing things, since the contents are the same one,
    // compiler will decide two of them in the same spot

    // Meanwhile, yourthings[0] and temp2 are different as they will have different memory space
    

    printf("%s %u %u\n", mythings[0], (unsigned)mythings[0], (unsigned)temp1);
    printf("%s %u %u\n", yourthings[0], (unsigned)yourthings[0], (unsigned)temp2);



    return 0;


}