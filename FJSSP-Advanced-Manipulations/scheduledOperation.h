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

// Creates a ScheduledOperation with given arguments
ScheduledOperation CreateScheduledOperation(int operationID, Process* process, int startTime, int endTime);


// Compares a ScheduledOperation's id with a given id, 
// provided from a generic list
int CompareScheduledOperationId(void* operationData, void* id);

#endif