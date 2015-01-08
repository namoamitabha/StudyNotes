#include "queue.h"

int queue_enqueue(Queue *queue, const void *data)
{
	return list_ins_next(queue, queue->tail, data);
}


int queue_dequeue(Queue *queue, void **data)
{
	return list_rem_next(queue, NULL, data);
}
