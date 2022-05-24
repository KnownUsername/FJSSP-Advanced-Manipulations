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
	ScheduledOperation* operation;
	ScheduledOperationList* nextOperation;
}ScheduledOperationList;
#endif