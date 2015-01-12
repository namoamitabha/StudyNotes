#include "set.h"

void set_init(Set *set,
	      int (*match)(const void *key1, const void *key2),
	      void (*destroy)(void *data))
{
	list_init(set, destroy);
	set->match = match;
}

int set_is_member(const Set *set, const void *data)
{
	int result = 0;

	ListElmt *current = list_head(set);

	while (NULL != current) {
		if (set->match(list_data(current), data))
			return 1;

		current = list_next(current);
	}

	return 0;
}

int set_insert(Set *set, const void *data)
{
	if (set_is_member(set, data))
		return -1;

	return list_ins_next(set, NULL, data);
}


int set_remove(Set *set, void **data)
{
	ListElmt *current = list_head(set);
	ListElmt *prev = NULL;

	int exists = 0;
	while (NULL != current) {
		if (set->match(list_data(current), *data)) {
			exists = 1;
			break;
		}
		prev = current;
		current = list_next(current);
	}

	if (0 == exists)
		return -1;

	free(*data);

	return list_rem_next(set, prev, data);
}

int set_union(Set *setu, const Set *set1, const Set *set2)
{
	ListElmt *current = list_head(set1);

	while (NULL != current) {
		if (0 != set_insert(setu, list_data(current)))
			return -1;

		current = list_next(current);
	}

	current = list_head(set2);
	while (NULL != current) {
		if (0 != set_insert(setu, list_data(current)))
			return -1;

		current = list_next(current);
	}

	return 0;
}
