#include<iostream>
#include<stdio.h>
using namespace std;
//queue by doubly link list
class node
{
public:
    int info;
    node *next;
    node *prev;
};
node* create(int data)
{
    node *ptr=new node;
    ptr->info=data;
    ptr->next=NULL;
    ptr->prev=NULL;
    return ptr;
}
void display(node *head)
{
    node *ptr=head->next;
    while(ptr!=NULL)
    {
        cout<<" "<<ptr->info;
        ptr=ptr->next;
    }
}
void insert(node *head,int data)
{
    node *ptr=head->next;
    node *p1=create(data);
    while(ptr->next!=NULL)
    {

        ptr=ptr->next;
    }
    ptr->next=p1;
    p1->prev=ptr;
    p1->next=NULL;
}
void remove(node *head)
{
    head->next=head->next->next;
}
int main()
{
    node *head,*p1,*p2,*p3;
    head=new node;
    p1=create(10);
    p2=create(20);
    p3=create(30);
    head->next=p1;
    p1->prev=head;
    p1->next=p2;
    p2->prev=p1;
    p2->next=p3;
    p3->prev=p2;
    p3->next=NULL;
    cout<<"queue by doubly link list :"<<endl;
    display(head);
    cout<<endl;
    cout<<"after insert element: "<<endl;
    insert(head,40);
    display(head);
    cout<<endl;
    cout<<"after remove element :"<<endl;
    remove(head);
    display(head);
    return 0;
}