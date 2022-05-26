#include "list.h"
#include "scheduledOperation.h"
#include <stdio.h>

/// <summary>
/// Creates a ScheduledOperation with given arguments
/// </summary>
/// <param name="operationID"></param>
/// <param name="process"></param>
/// <param name="startTime"></param>
/// <param name="endTime"></param>
/// <returns></returns>
ScheduledOperation CreateScheduledOperation(int operationID, Process* process, int startTime, int endTime) {

	ScheduledOperation newOperation;

	// Values' attribution
	newOperation.operationID = operationID;
	newOperation.process = process;
	newOperation.startTime = startTime;
	newOperation.endTime = endTime;

	return newOperation;
}

/// <summary>
/// Compares a ScheduledOperation's id with a given id, 
/// provided from a generic list
/// </summary>
/// <param name="operationData"></param>
/// <param name="id"></param>
/// <returns></returns>
int CompareScheduledOperationId(void* operationData, void* id) {

	// Data casts to desired type
	ScheduledOperation* operation = (ScheduledOperation*)operationData;
	int id = (int)&id;

	// Data comparisons
	if (operation->operationID == id) return 1;
	else return 0;
}


/// <summary>
/// Searches for a ScheduledOperation with given identifier
/// </summary>
/// <param name="operations"></param>
/// <param name="id"></param>
/// <returns></returns>
ScheduledOperation* SearchScheduledOperation(List* operations, void* id) {

	// Search on all elements
	while (operations) {

		// Compare ids for a match
		if (CompareScheduledOperationId(operations->data, id)) {
			
			// Return found operation
			return (ScheduledOperation*) operations;
		}
		// Pass to next element
		operations = operations->next;
	}

	// No match found
	return NULL;
}



/// <summary>
/// Verify if a ScheduledOperation exists on a list
/// </summary>
/// <param name="list"></param>
/// <param name="data"></param>
/// <returns> 1 -> True | 0 -> False </returns>
int ScheduledOperationExists(List* list, void* data) {

	// Search for ScheduledOperation -> If found, it exists
	if (SearchScheduledOperation(list, data)) return 1;

	return 0; // False
}