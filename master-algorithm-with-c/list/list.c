#include "list.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void list_init(List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}

void list_destroy(List *list)
{
	void *data;

	if (list == NULL)
		return;

	while (list->size > 0) {
		if (list_rem_next(list, NULL, &data) == 0
		    && list->destroy != NULL) {
			list->destroy(data);
		}
	}
	memset(list, 0, sizeof(List));
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

int list_rem_next(List *list, ListElmt *element, void **data)
{
	if (list->size == 0)
		return -1;

	ListElmt *remElmt;

	if (element == NULL) {
		remElmt = list->head;
		list->head = list->head->next;
	} else {
		if (list_is_tail(element))
			return -1;

		remElmt = element->next;
		element->next = element->next->next;
	}
	*data = remElmt->data;

	if (list_is_tail(remElmt))
		list->tail = element;

	--list->size;

	free(remElmt);

	return 0;
}
