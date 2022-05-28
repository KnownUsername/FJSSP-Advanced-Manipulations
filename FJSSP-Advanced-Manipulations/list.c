#include "list.h"
#include <stdio.h>
#include <stdlib.h>

// Search for an element on the list
List* SearchElement(List* list, void* data, int (*compare)(void* data1, void* data2)) {
	
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
/// Search the element before a given one
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="compare"></param>
/// <returns></returns>
List* SearchElementBefore(List* list, void* data, int (*compare)(void* data1, void* data2)) {

	// Empty list or element on 1st positions,
	// means there is no element before the desired one
	if(!list || (compare(list->data, data)) ) return NULL;

	// Walk through list
	while (list->next) {
		
		// Found the element before the desired one
		if (compare(list->next->data, data)) return list;
	
		// Go to next value
		list = list->next;
	}

	// Element not found
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

/// <summary>
/// Print elements of a list
/// </summary>
/// <param name="list"></param>
/// <param name="show"></param>
void ShowElements(List* list, void (*show)(void* data)) {

	while (list) {

		// Show data with given function
		show(list->data);

		// Pass to next element
		list = list->next;
	}
}

/// <summary>
/// Delete an Element of a List
/// </summary>
/// <param name="elementToRemove"></param>
/// <param name="data"></param>
/// <returns></returns>
List* DeleteElement(List* elementToRemove, void* (*delete)(void* data)) {

	// Disconnect element from the list
	elementToRemove->next = NULL;

	// Free memory from data
	elementToRemove->data = delete(elementToRemove->data);

	// Free memory from element being removed
	free(elementToRemove);

	// Retrieve NULL, no address to point to
	return NULL;

}

/// <summary>
/// Removes an element from a list
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <param name="compare"></param>
/// <param name="data"></param>
/// <returns></returns>
List* RemoveElement(List* list, void* data, int (*compare)(void* data1, void* data2), void* (*delete)(void* data)) {

	// Empty list has no element to remove
	if (!list) return NULL;

	List* elementToRemove;

	// Element on 1st position
	if (compare(list->data, data)) {

		elementToRemove = list;
		
		// Assign 1st position to next element
		list = list->next;

		// Delete data from element and free memory
		elementToRemove = DeleteElement(elementToRemove, delete);

	}

	// Element on 2nd to last position
	else {

		// Search for element before desired one
		List* elementBefore = SearchElementBefore(list, data, compare);

		// Element not found, then no element to remove
		if (!elementBefore) return list;

		// Pointer to element to remove
		elementToRemove = elementBefore->next;

		// Connect the element before with the element after the one to remove
		elementBefore->next = elementToRemove->next;

		// Delete data from element and free memory
		elementToRemove = DeleteElement(elementToRemove, delete);

	}
	
	// New state of list
	return list;
}

/// <summary>
/// Removes all elements on a List, leaving it empty
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <returns></returns>
List* DeleteList(List* list, void* (*delete)(void* data)) {

	if (list)
	{

		// Recursive till last element
		list->next = DeleteList(list->next, delete);

		// Delete current element
		list = DeleteElement(list, delete);

	}
	
	return list;
}