#include "dlist.h"
#include <stdlib.h>


void dlist_init(DList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}

void dlist_destroy(DList *list)
{
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
	DListElmt *newElmt = (DListElmt *)malloc(sizeof(DListElmt));

	if (newElmt == NULL)
		return -1;

	newElmt->data = (void *)data;

	if (element == NULL) {
		list->head = newElmt;
		list->tail = newElmt;
		newElmt->next = NULL;
		newElmt->prev = NULL;
	} else {
		if (dlist_is_tail(element))
			list->tail = newElmt;

		newElmt->next = element->next;
		newElmt->prev = element;
		element->next = newElmt;

	}
	++list->size;
	return 0;
}
