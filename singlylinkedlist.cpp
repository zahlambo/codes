#include<stdio.h>
#include <stdlib.h>
typedef struct node
{
int val;
struct node*next;
}node;
node*insert(node*first,int n){
	node*current;
	node*newnode=(node*)malloc(sizeof(node));
	newnode->val=n;
	newnode->next=NULL;
	if (first==NULL)
	{
		first=newnode;
	}
	else
	{
		current=first;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=newnode;
	}
	return first;
}
void printlist(node*first){
node*current;
current=first;
while(current!=NULL){
	printf("%d\n",current->val);
	current=current->next;
}
printf("\n");
}
void deletenode( node **first_ref, int key)
{
 
     node* current = *first_ref, *prev;
 while (current != NULL && current->val != key)
    {
        prev = current;
        current = current->next;
    } 
   
    if (current != NULL && current->val == key)
    {
        *first_ref = current->next;   
        free(current);               
        return;
    }

   
   
    if (current == NULL) return;

   
    prev->next = current->next;

    free(current);  
}

int findlen(node*first) 
{ 
    // Base case 
    if (first == NULL) 
        return 0; 
  
    // count is 1 + count of remaining list 
    return 1 + findlen(first->next); 
} 
int search(node* first, int x)  
{  
    node* current = first; // Initialize current  
    while (current != NULL)  
    {  
        if (current->val == x)  
            return 1;  
        current = current->next;  
    }  
    return -1;  
}
int main()
{
	node*first=NULL;
	first=insert(first,1);
	printlist(first);
	first=insert(first,4);
	printlist(first);
	first=insert(first,5);
	printlist(first);
	first=insert(first,3);
	printlist(first);

	deletenode(&first,1);
	printlist(first);
	int x=findlen(first);
	int y=search(first,1);
	printf("len of list is %d\n",x );
	if (y==1)
	{
		printf("found\n");
	}
	else
		printf("not found\n");
}
