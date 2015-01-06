#include "dlist.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

void dlist_init(DList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}

void dlist_destroy(DList *list)
{
	if (NULL == list)
		return;

	int result;
	void *data;

	while (0 == (result = dlist_remove(list, list->head, &data))) {
		if (NULL != list->destroy)
			list->destroy(data);
	}

	memset(list, 0, sizeof(DList));
}

int dlist_ins_next(DList *list, DListElmt *element, const void *data)
{
	if (NULL == element && dlist_size(list) != 0)
		return -1;

	DListElmt *newElmt = (DListElmt *)malloc(sizeof(DListElmt));

	if (NULL == newElmt)
		return -1;

	newElmt->data = (void *)data;

	if (0 == dlist_size(list)) {
		newElmt->next = NULL;
		newElmt->prev = NULL;
		list->head = newElmt;
		list->tail = newElmt;
	} else {
		newElmt->next = element->next;
		newElmt->prev = element;
		element->next = newElmt;

		if (NULL != newElmt->next)
			newElmt->next->prev = newElmt;
		else
			list->tail = newElmt;
	}
	++list->size;
	return 0;
}

int dlist_ins_prev(DList *list, DListElmt *element, const void *data)
{
	if (NULL == element && dlist_size(list) > 0)
		return -1;

	DListElmt *newElmt = (DListElmt *)malloc(sizeof(DListElmt));

	if (NULL == newElmt)
		return -1;

	newElmt->data = (void *)data;

	if (0 == dlist_size(list)) {
		newElmt->next = NULL;
		newElmt->prev = NULL;

		list->head = newElmt;
		list->tail = newElmt;
	} else {
		newElmt->prev = element->prev;
		element->prev = newElmt;
		newElmt->next = element;

		if (NULL != newElmt->prev)
			newElmt->prev->next = newElmt;
		else
			list->head = newElmt;
	}
	++list->size;

	return 0;
}

int dlist_remove(DList *list, DListElmt *element, void **data)
{
	if (0 == dlist_size(list) || NULL == element)
		return -1;

	DListElmt *oldElmt = element;

	*data = dlist_data(oldElmt);
	
	if (NULL == dlist_next(element))
		list->tail = element->prev;
	else
		element->next->prev = element->prev;

	if (NULL == dlist_prev(element))
		list->head = element->next;
	else
		element->prev->next = element->next;

	--list->size;

	free(element);

	return 0;
}
