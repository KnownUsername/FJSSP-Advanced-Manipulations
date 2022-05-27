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
	//int ptrid = (int*) ptrId;
	int id = (int)ptrId;

	// Data comparisons
	if (operation->operationID == id) return 1;
	else return 0;
}