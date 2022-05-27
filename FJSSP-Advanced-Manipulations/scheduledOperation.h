#ifndef SCHOP
#define SCHOP

#include "process.h"

/// <summary>
/// Defines an Operation scheduled
/// Has the Process used and time it starts and ends 
/// </summary>
typedef struct ScheduledOperation {
	int operationID;
	Process* process;
	int startTime;
	int endTime;
}ScheduledOperation;

/// <summary>
/// Defines a list of scheduled Operations
/// </summary>	
typedef struct ScheduledOperationList {
	ScheduledOperation operation;
	struct ScheduledOperationList* nextOperation;
}ScheduledOperationList;

// Creates a ScheduledOperation with given arguments
ScheduledOperation CreateScheduledOperation(int operationID, Process* process, int startTime, int endTime);


// Compares a ScheduledOperation's id with a given id, 
// provided from a generic list
int CompareScheduledOperationId(void* operationData, void* id);

// Verify if a ScheduledOperation exists on a list
int ScheduledOperationExists(List* list, void* data);

#endif