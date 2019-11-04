
#include<iostream>
#include <stdio.h>
using namespace std;
typedef struct node
{
    int val;
    node *next;

}node;
node*head,*tail;
void display();
void insert_first(int value)
{
    node *temp=new 9node;
    temp->val=value;
    temp->next=head;
    head=temp;

}
void insertnumber(int value)
{
    node *temp=new node;
    temp->val=value;
    temp->next=NULL;
    if(head==NULL)
    {
        head=temp;
        tail=temp;
        temp=NULL;
    }
    else
    {
        tail->next=temp;
        tail=temp;
    }

}

void insert_position(int pos, int value)
{
    node *pre=new node;
    node *cur=new node;
    node *temp=new node;
    cur=head;
    for(int i=1;i<pos;i++)
    {
        pre=cur;
        cur=cur->next;
    }
    temp->val=value;
    pre->next=temp;
    temp->next=cur;


}

void insert_end(node** head_ref,int item)
{
    node* new_node = new node();

    node *tail = *head_ref;

    new_node->val = item;

    new_node->next = NULL;


    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }


    while (tail->next != NULL)
        tail = tail->next;

    tail->next = new_node;
    return;
}


void delete_first()
{
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
}
void delete_tail()
{
    node *current=new node;
    node *previous=new node;
    current=head;
    while(current->next!=NULL)
    {
        previous=current;
        current=current->next;
    }
    tail=previous;
    previous->next=NULL;
    delete current;
}

int delete_item(int item) {
    node* temp = head;
    node* prev;

    while(temp != 0) {
        if(temp->val == item)
            break;
        prev = temp;
        temp = temp->next;
    }

    if(temp == NULL) {
        cout<<endl<<"list is empty"<<endl;
    }

    if(temp == head) {
        head = temp->next;
        delete temp;
        cout<<endl<<"deleted successfully"<<endl;
    }

    prev->next = temp->next;


    delete temp;
}


int search_item(int item) {
    node* temp = head;
    while(temp != 0) {
        if(temp->val == item)
            return 1;
        temp = temp->next;

    }
    return -1;
}
void display()
{
    node *temp=new node;
    temp=head;
    while(temp!=NULL)
    {
        cout<<temp->val<<"\t";
        temp=temp->next;
    }

    cout<<endl;
}


int main()
{

    while(1){
        int x;

    cout<<"1.insert 2.insert 1st 3.insert at a position 4.delete 1st 5.delete tail 6.delete an item. 7.Search .8 print 9.exit";
    cout<<endl;
        cin>>x;
        if(x==1){
            int n;
            cout<<"please enter a value"<<endl;
            cin>>n;
            insertnumber(n);
            cout<<"After Inserting"<<endl;
            display();
        }
        else if(x==2){
             int n;
            cout<<"please enter a value"<<endl;
            cin>>n;
            insert_first(n);
            cout<<"After Inserting"<<endl;
            display();
        }
        else if(x==3){
             int n,m;
             cout<<"1st enter the position, then the value"<<endl;
            cin>>n>>m;
            insert_position(n,m);
            cout<<"After Inserting"<<endl;
            display();
        }
        else if(x==4){
            int n;
           // cin>>n;
            delete_first();
            cout<<"After Deleting"<<endl;
            display();
        }
        else if(x==5){
             int n;
            //cin>>n;
            delete_tail();
            cout<<"After Deleting"<<endl;
            display();
        }
        else if(x==6){
             int n;
            cout<<"please enter a value"<<endl;
            cin>>n;
            delete_item(n);
            cout<<"After Deleting"<<endl;
            display();
        }
        else if(x==7){
           int n;
           cout<<"please enter a value"<<endl;
           cin>>n;
           int x= search_item(n);
            if (x==1){
                cout<<"found"<<endl;
            }
            else
                cout<<"not found"<<endl;
        }
        else if(x==8){
            display();
        }
        else if(x==9)
            break;

    }

    return 0;

}
