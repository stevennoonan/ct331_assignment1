#ifndef CT331_ASSIGNMENT_GENERIC_LINKED_LIST
#define CT331_ASSIGNMENT_GENERIC_LINKED_LIST

typedef struct listElementStruct listElement;

//Creates a new linked list element with given content of size
//Returns a pointer to the element
listElement* createEl(void* data, size_t size);

//Print functions:
void printChar(void* data);
void printStr(void* data);
void printInt(void* data);
void printFloat(void* data);

//Prints out each element in the list
void traverse(listElement* start);

//Inserts a new element after the given el
//Returns the pointer to the new element
listElement* insertAfter(listElement* after, void* data, size_t size);

//Delete the element after the given el
void deleteAfter(listElement* after);

//Returns the number of elements in a linked list
int length(listElement* list);

//Push a new element to head of list and update list ref using side effects
void push(listElement** list, void* data, size_t size);

//Pop an element from head of list and update list ref using side effects
listElement* pop(listElement** list);

//Enqueue a new element to the head of the list and update list ref using side effects
void enqueue(listElement** list, void* data, size_t size);

//Dequeue an element from the tail of the list
listElement* dequeue(listElement* list);

#endif
