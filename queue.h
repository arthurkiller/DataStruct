#ifndef _STDAFX_H
#define _STDAFX_H
#include <stdlib.h>
#endif

#ifndef _link_node
#define _link_node
#include "link_node.h"
#endif


/* lind queue via a single link node list
 *
 * use the next represent the next dequeue element
 * use the rare represent the next enqueue element
 *
 * for example:
 *
 * next              rare
 *  @1 -> @2 -> @3 -> @4
 *
 * enqueue at @4
 * dequeue at @1
 */

struct queue {
	Node next;
	Node rare;
};

typedef queue* Queue ;

bool is_empty(Queue q) {
	return  q->next == q->rare;
}

int enqueue(Queue q, void* data) {
	Node node = new_node(data);
	if (NULL ==  q->rare->next) {
		q->rare = node;
		return 0;
	}

	q->rare->next = node;

	return 0;
}

Node dequeue(Queue q) {
	if (NULL == q->next) {
		return NULL;
	}

	Node elem = q->next;
	q->next = q->next->next;
	return elem;
}
