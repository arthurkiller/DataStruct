#ifndef _STDAFX_H
#define _STDAFX_H
#include <stdlib.h>
#endif

#ifndef _link_node
#define _link_node
#include "link_node.h"
#endif

/* link stack via a single link node list
 *
 * use the next represent the next element
 *
 * for example:
 *
 * next
 *  @1 -> @2 -> @3 -> @4
 *
 * push at @1
 * pop at @1
 */

struct stack {
	Node next;
};

typedef stack* Stack;

int push(Stack s,Node node) {
	if (NULL == s->next) {
		s->next = node;
	}

	node->next = s->next;
	s->next = node;
	return 1;
}

Node pop(Stack s) {
	if (NULL == s->next) {
		return NULL;
	}

	Node n = s->next;
	s->next = s->next->next;
	return n;
}
