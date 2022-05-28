#ifndef SCHJOB
#define SCHJOB


#include "scheduledOperation.h"
#include "list.h"

/// <summary>
/// Defines a job with its operations scheduled 
/// </summary>
typedef struct ScheduledJob {
	char* jobIdentifier;
	List* operations;
	int duration;
}ScheduledJob;


// Creates a ScheduledJob with given arguments
ScheduledJob CreateScheduledJob(char* jobIdentifier, List* operations, int duration);

#endif