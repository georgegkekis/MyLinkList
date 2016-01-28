
#include<stdlib.h>
#include <stdio.h>

struct mylist
	{
	int var;
	struct mylist *next_ptr;
	};

typedef struct mylist mylist;

mylist *create_list(void);
mylist *add_element(int element);
mylist *search_for_element(int element, mylist **pprevious);
void delete_from_list(int element);
void print_list(void);
mylist *head = NULL;
mylist *last = NULL;
//mylist *previous = NULL;

int main()
{
	mylist *found;
	int element;
	int c;
	printf("hi,This program does basic linklist manupulation\n");
	printf("what would you like to do?\n");
	printf("Press:\nc for creating a list ");
	printf("\na for appending an element to the list");
	printf("\ns for searching for an element");
	printf("\nd for deleting an element");
	printf("\np for printing the list");
	printf("\ne for exiting program\n");
	while ((c = getchar())) {
		switch (c) {
			case 'c':
				head = create_list();
				printf("list created\n");
				break;
			case 'a':
				printf ("type in element to add\n");
				scanf ("%d",&element);
				last = add_element(element);
				break;
			case 's':
				printf ("type in element to search for\n");
				scanf ("%d",&element);
				{
				mylist *previous;
				found = search_for_element(element,&previous);
				}
				if (found)
				printf("found: %d\n",found->var);
				else
				printf("not found\n");
				break;
			case 'd':
				printf ("type in element to delete\n");
				scanf ("%d",&element);
				delete_from_list(element);
				break;
			case 'p':
				print_list();
				break;
			case 'e':return 0;
		}
	}
	printf("head: %d\n",head->var);
	printf("middle: %d\n",head->next_ptr->var);
	printf("last: %d\n",last->var);
	return (0);
}

mylist *create_list(void)
{
	mylist *ptr = (mylist*)malloc(sizeof(mylist));
	last=ptr;
	return ptr;
}

mylist *add_element(element)
{
	mylist *ptr =(mylist*)malloc(sizeof(mylist));
	if (last) {
		ptr->var= element;
		last->next_ptr = ptr;
		return ptr;
	}
	printf("error there are no elements in the list");
	return NULL;
}

mylist *search_for_element(int element, mylist **pprevious)
{
	
	mylist *ptr;
	*pprevious = NULL;
	ptr = head;
	while(ptr) {
		if(ptr->var == element)
		return ptr;
		*pprevious = ptr;
		ptr=ptr->next_ptr;
	}
	return NULL;
}

void delete_from_list(element)
{
	mylist *previous;
	mylist *ptr = head;
	ptr = search_for_element(element,&previous);
		if (ptr) {
			previous->next_ptr = ptr->next_ptr;
		}
		else
		printf("could not find element");
}
void print_list()
{
	int i =0;
	mylist *ptr = head;
	while (ptr) {
		printf("%d variable is:%d\n",i,ptr->var);
		i++;
		ptr = ptr->next_ptr;
	}
}