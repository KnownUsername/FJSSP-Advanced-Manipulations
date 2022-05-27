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
List* InsertListItem(List* list, void* newData, int (*exists)(void* data1, void* data2));

// Search for an element on the list
void* SearchElement(List* list, void* data, int (*compare)(void* data1, void* data2));

// Checks if an element exists on a generic list
int ElementExists(List* list, void* data, int (*compare)(void* data1, void* data2));



#endif