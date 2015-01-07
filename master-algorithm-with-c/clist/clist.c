#include "clist.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void clist_init(CList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->destroy = destroy;
}

void clist_destroy(CList *list)
{
	if (NULL == list)
		return;

	void *data;

	while (0 < clist_size(list)) {
		clist_rem_next(list, clist_head(list), &data);
		printf("destroy:%d\n", *((int *)data));
		if (NULL != list->destroy)
			list->destroy(data);
	}
	memset(list, 0, sizeof(CList));
}

int clist_ins_next(CList *list, CListElmt *element, const void *data)
{
	if (NULL == element && clist_size(list) > 0)
		return -1;

	CListElmt *newElmt = (CListElmt *)malloc(sizeof(CListElmt));

	if (NULL == newElmt)
		return -1;

	newElmt->data = (void *)data;

	if (0 == clist_size(list)) {
		list->head = newElmt;
		newElmt->next = list->head;
	} else {
		newElmt->next = element->next;
		element->next = newElmt;
	}

	++list->size;
	return 0;
}

int clist_rem_next(CList *list, CListElmt *element, void **data)
{
	if (element == NULL || 0 == clist_size(list))
		return -1;

	CListElmt *remElmt;

	if (element == element->next) {
		remElmt = clist_head(list);
		*data = clist_data(remElmt);
		list->head = NULL;
	} else {
		remElmt = element->next;
		*data = clist_data(remElmt);
		element->next = remElmt->next;
	}

	--list->size;
	free(remElmt);

	return 0;
}
