#ifndef LIST
#define LIST

/// <summary>
/// Defines a generic list
/// </summary>
typedef struct List {
	void* data;
	struct List* next;
}List;

// Insert a new element on a generic list
List* InsertListItem(List* list, void* newData, int (*compare)(void* data1, void* data2));

// Search for an element on the list
List* SearchElement(List* list, void* data, int (*compare)(void* data1, void* data2));

// Checks if an element exists on a generic list
int ElementExists(List* list, void* data, int (*compare)(void* data1, void* data2));

// Print elements of a list
void ShowElements(List* list, void (*show)(void* data));

// Removes an element from a list
List* RemoveElement(List* list, void* data, int (*compare)(void* data1, void* data2), void* (*delete)(void* data));

// Removes all elements on a List, leaving it empty
List* DeleteList(List* list, void* (*delete)(void* data));
#endif