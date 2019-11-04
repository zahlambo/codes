
#include <bits/stdc++.h>
using namespace std;

typedef class node
{
	public:
	int data;
	node* next;
	node* prev;
}node;


void push(node** head_ref, int new_data)
{
	node* new_node = new node();

	new_node->data = new_data;

	new_node->next = (*head_ref);
	new_node->prev = NULL;

	if ((*head_ref) != NULL)
		(*head_ref)->prev = new_node;

	(*head_ref) = new_node;
}

void insertAfter(node* prev_node, int new_data)
{       
    
	if (prev_node == NULL)
	{
		cout<<"the given previous node cannot be NULL";
		return;
	}

	node* new_node = new node();

	new_node->data = new_data;

	new_node->next = prev_node->next;

	prev_node->next = new_node;

	new_node->prev = prev_node;

	if (new_node->next != NULL)
		new_node->next->prev = new_node;
}

void append(node** head_ref, int new_data)
{
	node* new_node = new node();

	node* last = *head_ref;
	new_node->data = new_data;


	new_node->next = NULL;


	if (*head_ref == NULL)
	{
		new_node->prev = NULL;
		*head_ref = new_node;
		return;
	}


	while (last->next != NULL)
		last = last->next;


	last->next = new_node;

	new_node->prev = last;

	return;
}
void deletenode( node** head_ref, node* del)
{

    if (*head_ref == NULL || del == NULL)
        return;

    if (*head_ref == del)
        *head_ref = del->next;


    if (del->next != NULL)
        del->next->prev = del->prev;


    if (del->prev != NULL)
        del->prev->next = del->next;


    free(del);
}
void delete_at_pos(struct node** head_ref, int n)
{

    if (*head_ref == NULL || n <= 0)
        return;

    struct node* current = *head_ref;
    int i;


    for (int i = 1; current != NULL && i < n; i++)
        current = current->next;


    if (current == NULL)
        return;


    deletenode(head_ref, current);
}
void deleteAllX(struct node** head_ref, int x)
{
    if ((*head_ref) == NULL)
        return;

    struct node* current = *head_ref;
    struct node* next;

    while (current != NULL) {

        if (current->data == x) {


            next = current->next;


            deletenode(head_ref, current);

            current = next;
        }

        else
            current = current->next;
    }
}



void printList(node* node)
{
	struct node* last;
	cout<<"List is: \n";
	while (node != NULL)
	{
		cout<<" "<<node->data<<" ";
		last = node;
		node = node->next;
	}
	cout<<endl;

	//cout<<"reverse direction \n";
	//while (last != NULL)
	//{
	//	cout<<" "<<last->data<<" ";
	//	last = last->prev;
	//}
}


int main()
{
    node* head = NULL;
    while(1){
            int x;
        cout<<"Select An Operation "<<endl<<"1.insert first 2.insert 3.insert last 4.delete a number 5.delete at a position 6.print 7.exit"<<endl;
        cin>>x;
        if(x==1){
        int n;
        cin>>n;
        push(&head, n);
        printList(head);
        }
        else if(x==2){
        int n;
        cin>>n;
        insertAfter(head->next, n);
        printList(head);
        }
        else if(x==3){
        int n;
        cin>>n;
        append(&head, n);
        printList(head);
        }
        else if(x==4){
        int n;
        cin>>n;
        deleteAllX(&head,n);
        printList(head);
        }
        else if(x==5){
        int n;
        cin>>n;
        delete_at_pos(&head,n);
        printList(head);
        }
        else if(x==6){
        printList(head);
        }
        else if(x==7){
        break;
       }
    }









	return 0;
}

