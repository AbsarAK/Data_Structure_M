/******************************************************************************

linklist.c

Having definitions of linlist related functions

*******************************************************************************/
#include<stdio.h>
#include<stdlib.h>
#include"linklist.h"

void display(struct node *start)
{
    struct node *pTrns;
    if(start == NULL)
    {
        printf("List is empty\n");
        return;
    }
    pTrns=start;
    printf("List is :\n");
    while(pTrns !=NULL)
    {
        printf("%d\t",pTrns->info);
        pTrns=pTrns->link;
    }
    printf("\n\n");
}

void count(struct node *start)
{
    struct node *pCount=NULL;
    int count=0;
    if(start == NULL)
    {
        printf("Number of element is 0\n");
    }
    pCount=start;
    while(pCount !=NULL)
    {
        pCount=pCount->link;
        count++;
        
    }
    
    printf("Number of element is %d\n",count);
}
struct node *addatbeg(struct node *start,int data)
{
    struct node *ptmp;
    ptmp=(struct node *)malloc(sizeof(struct node));
    ptmp->info=data;
    ptmp->link=start;
    start=ptmp;
    return start;
    
}
struct node *addatend(struct node *start, int data)
{
    struct node *p,*ptmp;
    ptmp=(struct node *)malloc(sizeof(struct node));
    ptmp->info=data;
    p=start;
    while(p->link != NULL)
    {
        p=p->link;
    }
    p->link=ptmp;
    ptmp->link=NULL;
    return start;
}
void search(struct node *start,int data)
{
    struct node *pSearch=start;
    int position=1;
    while(pSearch != NULL)
    {
        if(pSearch->info == data)
        {
            printf("item %d found at position %d\n",data,position);
            return;
        }
        pSearch=pSearch->link;
        position++;
    }
    
}

struct node *create_list(struct node *start)
{
    int i=0,n=0,data=0;
    printf("enter the number of nodes\n");
    scanf("%d",&n);
    start=NULL;
    if(n == 0)
    {
        return start;
    }
    printf("enter the element to be inserted:\n ");
    scanf("%d",&data);
    start=addatbeg(start,data);
    for(i=2;i<=n;i++)
    {
       printf("enter the element to be inserted:\n ");
       scanf("%d",&data); 
       start=addatend(start,data);
    }
    return start;
}

struct node *addbefore(struct node *start,int data,int item)
{
    struct node *ptmp=NULL,*p=NULL;
    if(start == NULL)
    {
        printf("List is empty\n");
        return start;
    }
    if(start->info == item)
    {
        ptmp=(struct node *)malloc(sizeof(struct node));
        ptmp->info=data;
        ptmp->link=start;
        start=ptmp;
        return start;
    }
    p=start;
    while(p->link != NULL)
    {
        if(p->link->info == item)
        {
            ptmp=(struct node *)malloc(sizeof(struct node));
            ptmp->info=data;
            ptmp->link=p->link;
            p->link=ptmp;
            return start;
        }
        
        p=p->link;
    }
    printf("%d is not present in the list",item);
    return start;
}
struct node *addafter(struct node *start,int data,int item)
{
    struct node *ptemp=NULL,*p=NULL;
    p=start;
    while(p != NULL)
    {
        if(p->info == item)
        {
        ptemp=(struct node * )malloc(sizeof(struct node));
        ptemp->info=data;
        ptemp->link=p->link;
        p->link=ptemp;
        return start;
        }
        p=p->link;
    }
    printf("%d item not present in the list\n",item);
    return start;
}

struct node *addatpos(struct node *start,int data,int pos)
{
    struct node *ptemp=NULL,*p=NULL;
    int i=0;
    p=start;
    for (i=1; i<pos-1 && p!= NULL; i++)
    {
        p=p->link;
    }
    if(p == NULL)
    {
        printf("There are less than %d element\n",pos);
        
    }else 
    {
        ptemp=(struct node *)malloc(sizeof(struct node));
        ptemp->info=data;
        if(pos == 1)
        {
            ptemp->link=start;
            start=ptemp;
        }else
        {
            ptemp->link=p->link;
            p->link=ptemp;
        }
        
    }
    
    return start;
}