#include "list.h"

void list_init(List *list, void (*destroy)(void *data))
{
	list->size = 0;
	list->head = NULL;
	list->tail = NULL;
	list->destroy = destroy;
}
