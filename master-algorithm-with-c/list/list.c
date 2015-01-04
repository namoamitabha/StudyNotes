#include "list.h"
#include <stdlib.h>
#include <stdio.h>

void list_init(List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}

void list_destroy(List *list)
{
	/* ListElement *cur = list->head; */
	/* while (list->size > 0) { */
		
	/* } */
}

int list_ins_next(List *list, ListElmt *element, const void *data)
{
	ListElmt *newElement = (ListElmt *)malloc(sizeof(ListElmt));
	if (newElement == NULL)
		return -1;
	newElement->data = (void *)data;
	/* printf("%d\n", *((int *)data)); */
	if (element == NULL) {
		newElement->next = list->head;
		list->head = newElement;
	} else {
		if (list_is_tail(element))
			list->tail = newElement;

		newElement->next = element->next;
		element->next = newElement;
	}
	
	if (list->tail == NULL)
		list->tail = newElement;
	
	list->size++;
	
	return 0;
}
