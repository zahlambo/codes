#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
	int val;
	struct node*prev,*next;

}node;
node* insert(node*first,int n){
	node*current;
	node*newnode=(node*)malloc(sizeof(node));
	newnode->val=n;
	newnode->prev=NULL;
	newnode->next=NULL;
	if(first==NULL){
		first=newnode;
	}
	else{
		current=first;
		while(current->next!=NULL){
			current=current->next;
		}
		current->next=newnode;
		newnode->prev=current;
	}
	return first;
}

void printreverse(node*last){

while (last != NULL)
	{
	     printf("%d  ",last->val);

		last = last->prev;
	}
}
void printlist(node* node)
{
	struct node* last;

	while (node != NULL)
	{
	    printf("%d  ",node->val);

		last = node;
		node = node->next;
	}
	printf("\n");

printreverse(last);

}
void deletenode( node** first_ref, node* del)
{

    if (*first_ref == NULL || del == NULL)
        return;

    if (*first_ref == del)
        *first_ref = del->next;


    if (del->next != NULL)
        del->next->prev = del->prev;


    if (del->prev != NULL)
        del->prev->next = del->next;


    free(del);
}
void deleteX( node** first_ref, int x)
{
    if ((*first_ref) == NULL)
        return;

     node* current = *first_ref;
     node* next;

    while (current != NULL) {

        if (current->val == x) {


            next = current->next;


            deletenode(first_ref, current);

            current = next;
        }

        else
            current = current->next;
    }
}


int findlen(node*first)
{
    if (first == NULL)
        return 0;

    return 1 + findlen(first->next);
}

int search(node* first, int x)
{
    node*current;
    current=first;
    while (current != NULL)
    {
        if (current->val == x)
            return 1;
        current = current->next;
    }
    return -1;
}
int main(int argc, char const *argv[])
{

node*first=NULL,*last=NULL,current;
   while(1) {
        int t;
        printf("Select operation:\n1.Insert 2.Delete 3.Search 4.Print 5.Exit \n");
        scanf("%d", &t);
        if(t == 1) {
            int x;
            printf("Insert a number: ");
            scanf("%d", &x);
             first = insert(first,x);;

        } else if(t == 2) {
            int x;
            printf("Delete a number: ");
            scanf("%d", &x);
             deleteX(&first,x);;


        } else if(t == 3) {
                int x;
                printf("Search number: ");
                scanf("%d", &x);
                 int y=search(first,x);
                if(y == -1)
                    printf("Not found.\n");
                else
                    printf("Found.\n");
        }
        else if(t == 4) {
            printlist(first);
        } else if(t == 5) {
            break;
        }}}
