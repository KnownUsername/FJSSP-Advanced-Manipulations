#ifndef WEIGHT_JOB
#define WEIGHT_JOB

#include "list.h"
#include "job.h"

/// <summary>
/// Defins a Job consituted by Processes with weights
/// </summary>
typedef struct WeightedJob {
	char* jobId;
	List* weightedOperations;
}WeightedJob;

// Creates a WeightedJob -> A Job containing Operations constituted by Processes with weights for measures
WeightedJob CreateWeightedJob(Job job, float processPercent);

// Compares a WeightedJob's id with a given id,
// provided from a generic list
int CompareWeightedJobs(void* jobData, void* ptrId);
#endif 
