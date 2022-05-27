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
int CompareScheduledOperationId(void* operationData, void* ptrId) {

	// Data casts to desired type
	ScheduledOperation* operation = (ScheduledOperation*)operationData;
	int id = (int)ptrId;

	// Data comparisons
	if (operation->operationID == id) return 1;
	else return 0;
}

/// <summary>
/// Compares two ScheduledOperations, based on both ids
/// </summary>
/// <param name="operationData1"></param>
/// <param name="operationDate2"></param>
/// <returns></returns>
int CompareScheduledOperations(void* operationData1, void* operationDate2) {

	// Data casts to desired type
	ScheduledOperation* operation1 = (ScheduledOperation*)operationData1;
	ScheduledOperation* operation2 = (ScheduledOperation*)operationDate2;

	// Data comparisons
	if (operation1->operationID == operation2->operationID) return 1;
	else return 0;
}