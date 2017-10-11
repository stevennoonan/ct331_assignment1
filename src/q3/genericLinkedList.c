#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "genericLinkedList.h"

typedef struct listElementStruct {
	void* data;
	size_t size;
	struct listElementStruct* next;
	void(*printFn)(void* data);
} listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size) {
	listElement* e = malloc(sizeof(listElement));
	if (e == NULL) {
		//malloc has had an error
		return NULL; //return NULL to indicate an error.
	}
	char* dataPointer = malloc(size);
	if (dataPointer == NULL) {
		//malloc has had an error
		free(e); //release the previously allocated memory
		return NULL; //return NULL to indicate an error.
	}
	memmove(dataPointer, data, size);
	e->data = dataPointer;
	e->size = size;
	e->next = NULL;
	return e;
}

//Prints out each element in the list
void traverse(listElement* start) {
	listElement* current = start;
	while (current != NULL) {
		current->printFn(current->data);
		current = current->next;
	}
}

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* el, void* data, size_t size) {
	listElement* newEl = createEl(data, size);
	listElement* next = el->next;
	newEl->next = next;
	el->next = newEl;
	return newEl;
}


//Delete the element after the given el
void deleteAfter(listElement* after) {
	listElement* delete = after->next;
	listElement* newNext = delete->next;
	after->next = newNext;
	//need to free the memory because we used malloc
	free(delete->data);
	free(delete);
}


//Returns the number of elements in a linked list
int length(listElement* list) {

	int count = 0;
	listElement* current = list;
	while (current != NULL) {
		count++;
		current = current->next;
	}
	return count;
}

//Push a new element to head of list and update list ref using side effects
void push(listElement** list, void* data, size_t size) {
	listElement* newEl = createEl(data, size);
	newEl->data = data;
	newEl->next = *list;
	*list = newEl;
}


//Pop an element from head of list and update list ref using side effects
listElement* pop(listElement** list) {
	listElement* head = *list;

	if (head) {
		*list = head->next;
		head->next = NULL;
	}
	return head;
}

//Enqueue a new element to the head of the list and update list ref using side effects
void enqueue(listElement** list, void* data, size_t size) {
	listElement* newEl = createEl(data, size);
	newEl->data = data;
	newEl->next = *list;
	*list = newEl;
}


//Dequeue an element from the tail of the list
listElement* dequeue(listElement* list) {
	listElement* current = list;
	listElement* temp;
	while (current != NULL) {
		if (current->next == NULL) {
			temp = current->next;
			free(temp);
		}
		current = current->next;
	}
	return temp;
}

void printChar(void* data) {
	printf("%c\n", *(char*)data);
}

void printStr(void* data) {
	printf("%s\n", (char*)data);
}

void printInt(void* data) {
	printf("%d\n", *(int*)data);
}

void printFloat(void* data) {
	printf("%f\n", *(float*)data);
}