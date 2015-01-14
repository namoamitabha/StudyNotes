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
		return 1;

	return list_ins_next(set, NULL, data);
}


int set_remove(Set *set, void **data)
{
	ListElmt *current = list_head(set);
	ListElmt *prev = NULL;

	while (NULL != current) {
		if (set->match(list_data(current), *data)) {
			break;
		}
		prev = current;
		current = list_next(current);
	}

	if (NULL == current)
		return -1;

	/* free(*data);  */ /* it should be freed by user */

	return list_rem_next(set, prev, data);
}

int set_union(Set *setu, const Set *set1, const Set *set2)
{
	ListElmt *current = list_head(set1);

	set_init(setu, set1->match, NULL);

	while (NULL != current) {
		if (0 != set_insert(setu, list_data(current))) {
			set_destroy(setu);
			return -1;
		}
		current = list_next(current);
	}

	current = list_head(set2);
	while (NULL != current) {
		if (0 == set_is_member(setu, list_data(current))) {
			if (0 != set_insert(setu, list_data(current))) {
				set_destroy(setu);
				return -1;
			}
		}
		current = list_next(current);
	}

	return 0;
}

int set_intersection(Set *seti, const Set *set1, const Set *set2)
{
	set_init(seti, set1->match, NULL);

	ListElmt *current = list_head(set1);

	while (NULL != current) {
		if (set_is_member(set2, list_data(current))) {
			if (0 != set_insert(seti, list_data(current))) {
				set_destroy(seti);
				return -1;
			}
		}

		current = list_next(current);
	}

	return 0;
}

int set_difference(Set *setd, const Set *set1, const Set *set2)
{
	set_init(setd, set1->match, NULL);

	ListElmt *current = list_head(set1);

	while (NULL != current) {
		if (0 == set_is_member(set2, list_data(current))) {
			if (0 != set_insert(setd, list_data(current))) {
				set_destroy(setd);
				return -1;
			}
		}
		current = list_next(current);
	}
	return 0;
}

int set_is_subset(const Set *set1, const Set *set2)
{
	if (set_size(set1) > set_size(set2))
		return 0;

	ListElmt *current = list_head(set1);

	while (NULL != current) {
		if (0 == set_is_member(set2, list_data(current)))
			return 0;

		current = list_next(current);
	}
	return 1;
}

int set_is_equal(const Set *set1, const Set *set2)
{
	if (set_size(set1) != set_size(set2))
		return 0;

	return set_is_subset(set1, set2);
}
