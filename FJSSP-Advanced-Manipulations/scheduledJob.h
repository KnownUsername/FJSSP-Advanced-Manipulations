#ifndef SCHJOB
#define SCHJOB


#include "scheduledOperation.h"
#include "list.h"

/// <summary>
/// Defines a job with its operations scheduled 
/// </summary>
typedef struct JobScheduled {
	char* jobIdentifier;
	List* operations;
	int duration;
}JobScheduled;


#endif