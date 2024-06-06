#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
    struct node *left;
};
struct node *newnode, *head = NULL, *temp;

void create()
{
    int num = 1;
    while(num)
    {
        newnode = (struct node*)malloc(sizeof(struct node));
        printf("enter new node value \n");
        scanf("%d",&newnode->value);
        newnode->next = NULL;
        newnode->left = NULL;

        if(head == NULL)
        {
            head = newnode;
        }
        else
        {
            temp = head;
            while(temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        printf(" do you want to create more node? 1 for yes, and 0 for no: ");
        scanf("%d",&num);
    }
}

void display()
{
    if(head == NULL)
    {
        printf("double linked list is empty \n");

    }
    else
    {
        temp = head;
        while(temp != NULL)
        {
            printf("%d=>",temp->value);
            temp = temp->next;
        }
    }
}

 void sort()
 {
     struct node *i, *j;
     int num;
     for(i = head; i->next != NULL; i=i->next)
     {
         for(j=i->next; j != NULL; j=j->next)
         {
             if(i->value > j->value)
             {
                 num = j->value;
                 j->value = i->value;
                 i->value = num;
             }
         }
     }
 }
int main()
{
    create();
    display();
    printf("\nsorted doubly linked list\n");
    sort();
    display();
    return 0;
}