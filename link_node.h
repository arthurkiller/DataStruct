#ifndef _STDAFX_H
#define _STDAFX_H
#include <stdlib.h>
#endif

struct link_node {
	//struct link_node* pre;
	struct link_node* next;
	void* data;
};

typedef link_node* Node;

Node new_link() {
	Node header = (Node)malloc(sizeof(link_node));
	return header;
}


Node new_node(void* data) {
	Node node = (Node)malloc(sizeof(link_node));
	node->data = data;
	return node;
}

Node add(Node header, void* data) {
	// find last node
	while (NULL != header->next ) {
		header = header->next;
	}

	// generate the node
	header->next = (Node)malloc(sizeof(link_node));
	header->data = data;
	return header;
}

Node delete_node(Node node) {
	if (NULL == node->next) {
		free(node);
		return NULL;
	}

	// save the current node
	Node present_node = node;
	Node next_node = node->next;

	// change the link node, make the node out of link
	present_node->data = next_node->data;
	present_node->next = next_node->next;

	// remove the outline node
	free(next_node);
	return present_node;
}
