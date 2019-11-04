// Program for converting singly linked list 
// into circular linked list. 
#include <bits/stdc++.h> 

/* Linked list node */
 typedef  class node { 
 public:
	int data; 
	  node* next; 
}node; 

// Function that convert singly linked list 
// into circular linked list. 
  node* circular(  node* head) 
{ 
	
	  node* start = head; 

	while (head->next != NULL) 
		head = head->next; 
		
	// if head->next points to NULL then 
	// start assign to the head->next node. 
	head->next = start; 
	return start; 
} 

void push(  node** head, int data) 
{ 
	// Allocate dynamic memory for  temp. 
	  node*  temp = new node;

	// Assign the data into  temp. 
	 temp->data = data; 

	//  temp->next assign the address of 
	// head node. 
	 temp->next = (*head); 

	//  temp become the headnode. 
	(*head) =  temp; 
} 

// Function that display the elements of 
// circular linked list. 
void displayList(  node* head) 
{ 
	  node* start = head; 

	while (head->next != start) { 
		printf("%d ", head->data); 
		head = head->next; 
	} 
	
	// Display the last head of circular 
	// linked list. 
	printf("%d ", head->data); 
} 

// Drier program to test the functions 
int main() 
{ 
	// Start with empty list 
	  node* head = NULL; 

	// Using push() function to con  
	// singly linked list 
	// 17->22->13->14->15 
	push(&head, 15); 
	push(&head, 14); 
	push(&head, 13); 
	push(&head, 22); 
	push(&head, 17); 

	// Call the circular_list function that 
	// convert singly linked list to circular 
	// linked list. 
	circular(head); 

	printf("Display list: \n"); 
	displayList(head); 

	return 0; 
} 
