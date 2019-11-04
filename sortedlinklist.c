#include<stdio.h> 
#include<stdlib.h> 

 typedef struct node 
{ 
	int data; 
	struct node* next; 
}node; 

void sortedInsert( node** first_ref,  node* new_node) 
{ 
	 node* current; 
	if (*first_ref == NULL || (*first_ref)->data >= new_node->data) 
	{ 
		new_node->next = *first_ref; 
		*first_ref = new_node; 
	} 
	else
	{ 
		current = *first_ref; 
		while (current->next!=NULL && current->next->data < new_node->data) 
		{ 
			current = current->next; 
		} 
		new_node->next = current->next; 
		current->next = new_node; 
	} 
} 

 node *newnode(int new_data) 
{ 
	 node* new_node = 
		( node*) malloc(sizeof( node)); 

	new_node->data = new_data; 
	new_node->next = NULL; 

	return new_node; 
} 

void printList( node *head) 
{ 
	 node *temp = head; 
	while(temp != NULL) 
	{ 
		printf("%d ", temp->data); 
		temp = temp->next; 
	} 
} 

int main() 
{ 
	 node* head = NULL; 
	 node *new_node = newnode(5); 
	sortedInsert(&head, new_node); 
	new_node = newnode(10); 
	sortedInsert(&head, new_node); 
	new_node = newnode(7); 
	sortedInsert(&head, new_node); 
	new_node = newnode(3); 
	sortedInsert(&head, new_node); 
	new_node = newnode(1); 
	sortedInsert(&head, new_node); 
	new_node = newnode(9); 
	sortedInsert(&head, new_node); 
	printf("\n Created Linked List\n"); 
	printList(head); 

	return 0; 
} 
