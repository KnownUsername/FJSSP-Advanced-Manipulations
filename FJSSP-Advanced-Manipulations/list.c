#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Search for an element on the list
void* SearchElement(List* list, void* data, int (*compare)(void* data1, void* data2)) {
	
	// Compare all values on list with new element
	while (list) {

		// Compare both values with given function
		if (compare(list->data, data)) return list;

		// Pass to next element
		list = list->next;
	}

	return NULL;
}



/// <summary>
/// Checks if an element exists on a generic list
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="compare"></param>
/// <returns></returns>
int ElementExists(List* list, void* data, int (*compare)(void* data1, void* data2)) {

	// Search for element -> If found, it exists
	if (SearchElement(list, data, compare)) return 1;

	return 0; // False
}

/// <summary>
/// Inserts a new element on a generic list.
/// Insertion on tail -> New elements are inserted at the end of list
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="compare"></param>
/// <returns></returns>
List* InsertListItem(List* list, void* newData, int (*compare)(void* data1, void* data2)) {

	// Empty List
	if (!list) {

		// Unique element is the pointer to new element
		list = (List*)malloc(sizeof(List));
		list->data = newData;
		list->next = NULL;

	}

	// List with elements
	else {

		// Check if process is already on operation
		if (!ElementExists(list, newData,compare)) {

			List* lastElement = list;

			// Search last element on list
			while (lastElement->next) {
				lastElement = lastElement->next;
			}

			// Connect last element to new one
			lastElement->next = (List*)malloc(sizeof(List));
			lastElement->next->data = newData;
			lastElement->next->next = NULL;

		}
	}

	// Pointer to 1st element
	return list;

}

