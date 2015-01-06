#include "clist.h"

void clist_init(CList *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->destroy = destroy;
}
