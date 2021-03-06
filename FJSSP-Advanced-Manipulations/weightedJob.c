#include "weightedJob.h"

#include "weightedOperation.h"
#include "weightedProcess.h"
#include <stdlib.h>

/// <summary>
/// Creates a WeightedJob -> A Job containing Operations constituted by Processes with weights for measures
/// </summary>
/// <param name="job"></param>
/// <param name="processPercent"></param>
/// <returns></returns>
WeightedJob CreateWeightedJob(Job job, float processPercent) {

	WeightedJob weightedJob;
	float averageTime, probHTAverage, difWorstTimeAvg, jobWeight, taxedJobWeight;
	int maxDuration;

	weightedJob.jobId = job.jobIdentifier;
	weightedJob.weightedOperations = (List*)malloc(sizeof(List));
	
	/*				Intermediate calculus		*/
	averageTime = CalculateAverageOperationProcessTime(job.operations);
	probHTAverage = ProbWorstThanAverage(job.operations, averageTime);
	maxDuration = GetMaximumDurationOnOperationList(job.operations);
	difWorstTimeAvg = maxDuration - averageTime;

	jobWeight = averageTime + (difWorstTimeAvg * probHTAverage);

	// Convert % value into a number from 0 to 1
	processPercent = processPercent / 100;

	taxedJobWeight = jobWeight * ((1-processPercent) / 100);

	// Assignment to a variable with shorter name
	OperationList* operations = job.operations;
	WeightedOperation currentWeightedOperation;

	while (operations) {
		
		// Build a WeightOperation from an Operation from the list
		currentWeightedOperation = CreateWeightedOperation(operations->operation, job.jobIdentifier, processPercent, taxedJobWeight);

		// Insert new WeightOperation on the list related to the current WeightedJob
		weightedJob.weightedOperations = InsertListItem(weightedJob.weightedOperations, &currentWeightedOperation, CompareWeightedProcesses);
	}

	return weightedJob;
}

/// <summary>
/// Compares a WeightedJob's id with a given id,
/// provided from a generic list
/// </summary>
/// <param name="jobData"></param>
/// <param name="ptrId"></param>
/// <returns></returns>
int CompareWeightedJobs(void* jobData, void* ptrId) {

	// Data casts to desired type
	WeightedJob* job = (WeightedJob*)jobData;
	int id = (int)ptrId;

	// Data comparisons
	if (job->jobId == id) return 1;
	else return 0;
}

/// <summary>
/// Create all WeightedJobs from a list of jobs 
/// and group it on a list
/// </summary>
/// <param name="jobs"></param>
/// <param name="processPercent"></param>
/// <returns></returns>
List* GenerateWeightedJobs(List* jobs, float processPercent) {
	
	List* weightedJobs = NULL;
	WeightedJob generatedWeightedJob;
	Job* currentJob;

	while (jobs) {

		// Get element's Job from generic List
		currentJob = (Job*)jobs->data;

		// Create respective Weighted Job
		generatedWeightedJob = CreateWeightedJob(*currentJob, processPercent);

		// Insert generated WeightedJob on list
		weightedJobs = InsertListItem(weightedJobs, &generatedWeightedJob, CompareWeightedJobs);

		// Go to next job
		jobs = jobs->next;
	}

	return weightedJobs;
}
/// <summary>
/// Print values of a WeightedJob from a generic list
/// </summary>
/// <param name="data"></param>
void ShowWeightedJob(void* data) {

	WeightedJob* job = (WeightedJob*)data;

	// Discard empty job
	if (!job) return;

	printf("Job: %s\n", job->weightedOperations);

	if (job->weightedOperations) ShowElements(job->weightedOperations, ShowWeightedOperation);
}

