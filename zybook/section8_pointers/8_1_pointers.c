// stack frame
// last in, first out = LIFO
// push new item -> it goes to the top of stack -> pop out first
// queue
// tail, head
// first in, first out

// inside the stack memory
// the very first stack frame will be created and dedicated to function main.c
// keep some local variable
// as soon as a function 'swap' is called in the main function
// new stack frame 'swap' will be created
// when we are done swapping the value inside the 'swap' function
// the stack frame 'swap' should be popped out (removed)


// pass by value: you only "copy" of the variable inside the main function (caller function) to the corresponding local variable inside the 'swap' function
// the value inside the main function does not change
// whatever you do inside 'swap' function won't change the original values inside the main function

// array is passed by 'reference'
// it means, that we send the whole array to a function
// and whatever we do will affect the original array inside the main


// pointers are passed by 'reference'
// whatever you send, if you change it, it will affect the original value


// &i = address of variable i
// int* a = it's not a integer, but pointer referring to the integer

// pointers will also be created inside hip
// int temp = *a : it means go to this address of *a
// *a = *b : it changes the original value in main, does not change something in Heap
// after function is ending, the values in stack/heap will be popped out
// address of the variable (&) and pointer variables (*)

#include <stdio.h>

int main()
{
    int someInt;
    int* valPointer;

    someInt = 5;
    printf("someInt address is %p\n", (void*) &someInt);

    valPointer = &someInt;
    printf("valPointer is %p\n", (void*) valPointer);

    int i;
    int* iPtr;

    i = 10;
    iPtr = &i;
    // &i or iPtr -> address of content of variable i
    
    /* dereferencing a pointer variable
    accessing to the content of the variable (in the memory)
    that the pointer is pointing or referring to */
    
    // *iPtr
    
    // how to show content of i?
    // *iPtr is referring to int data
    printf(" %d", i);
    printf(" %d", *iPtr);

    // how can I change the content of i?
    i = 15;
    *iPtr = 15;

    // Null pointer
    // every time you declare pointer variable, it should be initialized with null
    // Do not use pointer if it's Null or it's unknown (garbage)


}
