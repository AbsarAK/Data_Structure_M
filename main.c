/******************************************************************************

main.c

*******************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include"linklist.h"
int main()
{
    struct node *start=NULL;
    int choice=0,data=0,item=0,pos=0;
    while(1)
    {
        
        printf("1.create list\n");
        printf("2.display list\n");
        printf("3.count list\n");
        printf("4.add a node at beginning of the list\n");
        printf("5.add a node at end of the list\n");
        printf("6.search list\n");
        printf("7.add at before node\n");
        printf("8.add at after node\n");
        printf("9.add at position\n");
        printf("10.delete an elemnt\n");
        
        scanf("%d",&choice);
        
        switch(choice)
        {
            case 1:start=create_list(start);break;
            case 2:display(start);break;
            case 3:count(start);break;
            case 4:printf("enter the element to be add at the beginning of list\n");scanf("%d",&data);start=addatbeg(start,data);break;
            case 5:printf("enter the element to be add at the end of list\n");scanf("%d",&data);start=addatbeg(start,data);break;
            case 6:printf("enter the element to be searched\n");scanf("%d",&data);search(start,data);break;
            case 7:printf("enter the element to be inserted\n");scanf("%d",&data);printf("enter the element before which to be inserted\n");scanf("%d",&item);start=addbefore(start,data,item);break;
            case 8:printf("enter the element to be inserted\n");scanf("%d",&data);printf("enter the element after which to be inserted\n");scanf("%d",&item);start=addafter(start,data,item);break;
            case 9:printf("enter the element to be inserted\n");scanf("%d",&data);printf("enter the position \n");scanf("%d",&pos);start=addatpos(start,data,pos);break;
            case 10:printf("enter the element to be deleted\n");scanf("%d",&data);
            default:printf("wrong choice\n");start=del(start,data);break;
        }

    }
    return 0;
}