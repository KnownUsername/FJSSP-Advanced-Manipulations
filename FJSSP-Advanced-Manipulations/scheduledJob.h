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

// Print values of a ScheduledOperation from a list
void ShowScheduledJob(void* data);

// Compares a ScheduledJob's id with a given id, 
// provided from a generic list
int CompareScheduledJobId(void* jobData, void* ptrId);

// Free memory from a ScheduledJob structure from a list
void* DeleteScheduledJob(void* data);
#endif