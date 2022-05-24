#ifndef SCHJOB
#define SCHJOB


#include "scheduledOperation.h"

/// <summary>
/// Defines a job with its operations scheduled 
/// </summary>
typedef struct JobScheduled {
	int jobId;
	ScheduledOperationList* operations;
	int duration;
}JobScheduled;

/// <summary>
/// Defines a list of jobs with scheduled operations
/// </summary>
typedef struct JobScheduledList {
	JobScheduled* jobScheduled;
	struct JobScheduledList* nextJob;
}JobScheduledList;

#endif