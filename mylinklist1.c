
#include<stdlib.h>
#include <stdio.h>

struct mylist
	{
	int var;
	struct mylist *next_ptr;
	};

typedef struct mylist mylist;

mylist *create_list(void);
int add_element(mylist **head , int element);
mylist *search_for_element(mylist **head , int element, mylist **pprevious);
void delete_from_list(mylist **head , int element);
int print_list(mylist **head);
//mylist *head = NULL;
//mylist *last = NULL;
//mylist *previous = NULL;
int added = 0;

int main()
{
	mylist *head = NULL;
	mylist *found;
	mylist *previous;
	int element;
	int c;
	printf("hi,This program does basic linklist manupulation.\n");
	printf("what would you like to do?\n");
	printf("Press:\nc for creating a list.");
	printf("\na for appending an element to the list.");
	printf("\ns for searching for an element.");
	printf("\nd for deleting an element.");
	printf("\np for printing the list.");
	printf("\ne for exiting program.\n");
	while ((c = getchar())) {
		switch (c) {
			case 'c':
				head = create_list();
				printf("list created\n");
				break;
			case 'a':
				printf ("type in element to add\n");
				scanf ("%d",&element);
				added = add_element(&head , element);
				break;
			case 's':
				printf ("type in element to search for\n");
				scanf ("%d",&element);
				found = search_for_element(&head , element , &previous);
				if (found)
				printf("found: %d\n",found->var);
				else
				printf("not found\n");
				break;
			case 'd':
				printf ("type in element to delete\n");
				scanf ("%d",&element);
				delete_from_list(&head , element);
				break;
			case 'p':
				print_list(&head);
				break;
			case 'e':
				return 0;
		}
	}
	return 0;
}

mylist *create_list(void)
{
	mylist *ptr = (mylist*)malloc(sizeof(mylist*));
	return ptr;
}

int add_element(mylist **head , int element)
{
	mylist *ptr,*ptrtemp;
	ptr = *head;
	while (ptr) {
		if (ptr->next_ptr == NULL) {
			ptrtemp = (mylist*)malloc(sizeof(mylist));
			ptr->next_ptr = ptrtemp;
			ptr->var = element;
			return 1;
		}
		ptr = ptr->next_ptr;
	}
	
	return 0;
}

mylist *search_for_element(mylist** head , int element, mylist **pprevious)
{
	mylist *ptr;
	*pprevious = NULL;
	ptr = *head;
	while(ptr) {
		if(ptr->var == element)
		return ptr;
		*pprevious = ptr;
		ptr=ptr->next_ptr;
	}
	return NULL;
}

void delete_from_list(mylist **head , int element)
{
	mylist *previous;
	mylist *ptr;
	ptr = search_for_element(head , element, &previous);
		if (ptr) {
			if (previous) 
				previous->next_ptr = ptr->next_ptr;
			else {
				if(ptr->next_ptr == NULL) {
					*head = NULL;
					printf("list destroyed\n");
				}
				*head = ptr;
			}
		}
		else
		printf("could not find element");
}

int print_list(mylist** head)
{
	int i =0;
	mylist *ptr = *head;
	
	if (added == 0) {
		printf("add sth to the list first\n");
		return 0;
	}
	if (head == NULL) {
		printf("list hasnt been created yet\n");
	return 0;
	}
	while (ptr) {
		printf("%d variable is:%d\n",i,ptr->var);
		printf("%p\n",ptr->next_ptr);
		i++;
		ptr = ptr->next_ptr;
	}
	return 0;
}

/*delete_from_list_pointer(mylist **head , mylist **ptr , **ptodelete)
{
	
	mylist *ptr;
	*pprevious = NULL;
	ptr = *head;
	while(ptr) {
		if(ptr->nex == element)
		return ptr;
		*pprevious = ptr;
		ptr=ptr->next_ptr;
	}
	return NULL;
}*/