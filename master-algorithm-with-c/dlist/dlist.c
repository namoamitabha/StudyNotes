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

	if (NULL == newElmt)
		return -1;

	newElmt->data = (void *)data;

	if (element == NULL) {
		newElmt->next = list->head;
		newElmt->prev = NULL;
		list->head = newElmt;

		if (NULL == dlist_tail(list))
			list->tail = newElmt;
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

int dlist_ins_prev(DList *list, DListElmt *element, const void *data)
{
	DListElmt *newElmt = (DListElmt *)malloc(sizeof(DListElmt));

	if (NULL == newElmt)
		return -1;

	newElmt->data = (void *)data;

	if (NULL == element || dlist_is_head(element)) {
		newElmt->next = list->head;
		newElmt->prev = NULL;

		list->head = newElmt;

		if (NULL == dlist_tail(list))
			list->tail = newElmt;
	} else {
		newElmt->prev = element->prev;
		element->prev = newElmt;
		newElmt->next = element;
	}
	++list->size;

	return 0;
}
