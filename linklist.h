#ifndef LINKLIST_H
#define LINKLIST_H

struct node
{
    int info;
    struct node *link;
};
struct node *create_list(struct node *start);
void display(struct node *start);
void count(struct node *start);
struct node *addatbeg(struct node *start,int data);
struct node *addatend(struct node *start, int data);
void search(struct node *start,int data);
struct node *addbefore(struct node *start,int data,int item);
struct node *addafter(struct node *start,int data,int item);
struct node *addatpos(struct node *start,int data,int pos);





#endif 