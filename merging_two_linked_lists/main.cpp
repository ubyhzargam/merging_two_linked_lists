//
//  main.cpp
//  merging_two_linked_lists
//
//  Created by Uby H on 21/07/23.
//

#include <iostream>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
}*first2=NULL,*first3=NULL,*first1=NULL;
void create1(int A[], int n)
{
    struct Node *last=NULL;
    struct Node *p=NULL;
    first1=(struct Node*)malloc(sizeof(struct Node));
    first1->data=A[0];
    first1->next=NULL;
    last=first1;
    for(int i=1;i<n;i++)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=A[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
}
void create2(int A[], int n)
{
    first2=(struct Node*)malloc(sizeof(struct Node));
    struct Node *last=NULL;
    struct Node *p=NULL;
    first2->data=A[0];
    first2->next=NULL;
    last=first2;
    for(int i=1;i<n;i++)
    {
        p=(struct Node*)malloc(sizeof(struct Node));
        p->data=A[i];
        p->next=NULL;
        last->next=p;
        last=p;
    }
}
void display(struct Node *p)
{
    while(p!=NULL)
    {
        cout<<p->data<<" ";
        p=p->next;
    }
    cout<<endl;
}
void merge(struct Node *p1, struct Node *p2)
{
    struct Node *p3=(struct Node*)malloc(sizeof(struct Node));
    struct Node *last=NULL;
    if(p1->data<p2->data)
    {
        p3->data=p1->data;
        p3->next=NULL;
        first3=p3;
        last=first3;
        p1=p1->next;
    }
    else
    {
        p3->data=p2->data;
        p3->next=NULL;
        first3=p3;
        last=first3;
        p2=p2->next;
    }
    while(p1!=NULL&&p2!=NULL)
    {
        p3=(struct Node*)malloc(sizeof(struct Node));
        if(p1->data<p2->data)
        {
            p3->data=p1->data;
            p3->next=NULL;
            p1=p1->next;
        }
        else
        {
            p3->data=p2->data;
            p3->next=NULL;
            p2=p2->next;
        }
        last->next=p3;
        last=p3;
    }
    while(p1!=NULL)
    {
        struct Node *p3=(struct Node*)malloc(sizeof(struct Node));
        p3->data=p1->data;
        p3->next=NULL;
        last->next=p3;
        last=p3;
        p1=p1->next;
    }
    while(p2!=NULL)
    {
        struct Node *p3=(struct Node*)malloc(sizeof(struct Node));
        p3->data=p2->data;
        p3->next=NULL;
        last->next=p3;
        last=p3;
        p2=p2->next;
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in linked list 1 : "<<endl;
    cin>>n;
    int A[n];
    cout<<"Enter the elements of linked list 1 : "<<endl;
    for(int i=0;i<n;i++)cin>>A[i];
    create1(A,n);
    cout<<"Enter the number of elements in linked list 2 : "<<endl;
    cin>>n;
    cout<<"Enter the elements of linked list 2 : "<<endl;
    int A1[n];
    for(int i=0;i<n;i++)cin>>A1[i];
    create2(A1,n);
    cout<<"Linked list 1 is given by : "<<endl;
    display(first1);
    cout<<"Linked list 2 is given by : "<<endl;
    display(first2);
    merge(first1,first2);
    cout<<"The merged array is given by : "<<endl;
    display(first3);
    return 0;
}
