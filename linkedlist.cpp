
#include<iostream>
#include <stdio.h>
using namespace std;
typedef struct node
{
    int data;
    node *next;

}node;
node*head,*tail;
void display();
void insertnumber(int value)
{
    node *temp=new node;
    temp->data=value;
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
void insert_first(int value)
{
    node *temp=new node;
    temp->data=value;
    temp->next=head;
    head=temp;

}
void delete_first()
{
    node *temp=new node;
    temp=head;
    head=head->next;
    delete temp;
}
void delete_last()
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
        if(temp->data == item)
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
    temp->data=value;
    pre->next=temp;
    temp->next=cur;
    cout<<endl<<"Inserted"<<endl;
   display();
}

void insert_end(node** head_ref,int item)
{
    node* new_node = new node();

    node *last = *head_ref;

    new_node->data = item;

    new_node->next = NULL;


    if (*head_ref == NULL)
    {
        *head_ref = new_node;
        return;
    }


    while (last->next != NULL)
        last = last->next;

    last->next = new_node;
    return;
}

int search_item(int item) {
    node* temp = head;
    while(temp != 0) {
        if(temp->data == item)
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
        cout<<temp->data<<"\t";
        temp=temp->next;
    }

    cout<<endl;
}
void print_list() {
    node* temp = head;
    while(temp != 0) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{

    while(1){
            int x;
    cout<<"Select an operation"endl<<"1.insert 2.insert 1st 3.insert at a position 4.delete 1st 5.delete last 6.delete an item. 7.Search .8 print 9.exit";
        cin>>x;

    }

    insertnumber(25);
    insertnumber(15);
    insertnumber(5);
    insertnumber(9);
    insert_first(6);
    display();
    delete_item(25);

    ;

  
    delete_first();
    delete_last();
    insert_position(3,8);
    insert_end(&head,3);

    display();
   int x= search_item(26);
   if (x==1){
        cout<<"found"<<endl;
   }
   else
        cout<<"not found"<<endl;
    



    return 0;

}
