#include <stdlib.h>
#include <stdio.h>

typedef struct listnode mynode;
struct listnode
{
    mynode *next;
    int number;
    int age;
};
mynode *addnode(mynode *prevnd, int number, int age)
{
    mynode *ndtemp = (mynode *)malloc(sizeof(mynode));
    prevnd->next = ndtemp;
    ndtemp->number = number;
    ndtemp->age = age;
    ndtemp->number = number;
    return ndtemp;
}
mynode *initlist()
{
    mynode *temp=(mynode*)malloc(sizeof(mynode));
    temp->age=0;
    temp->next=0;
    temp->number=0;
    return temp;
}
int main()
{
    mynode *mylist=initlist();
    mynode *mytempnd=mylist;
    int i=0;
    for(i=0;i<10;i++)
    {
        mytempnd=addnode(mytempnd,i,20+i);
    }

    for(mytempnd=mylist->next;mytempnd!=NULL;mytempnd=mytempnd->next)
    {
        printf("id:%d,age:%d\n",mytempnd->number,mytempnd->age);
    }

    mynode *oldtempnd;
    for(mytempnd=mylist->next;mytempnd!=NULL;)
    {
        printf("delete id:%d\n",mytempnd->number);
        oldtempnd=mytempnd;
        mytempnd=mytempnd->next;
        free(oldtempnd);
    }
    free(mylist);
    return 0;
}