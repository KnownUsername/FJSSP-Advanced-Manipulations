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

// Compares two ScheduledOperations, based on both ids
int CompareScheduledOperations(void* operationData1, void* operationDate2);

// Print values of a ScheduledOperation from a list
void ShowScheduledOperation(void* data);

// Free memory from a ScheduledOperation structure from a list
void* DeleteScheduledOperation(void* data);
#endif