/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: Second Practical Work

	File: scheduledJob.c
	Intent:
		- Implement functions to manipulate 1 or more Jobs scheduled
		  (1 Process for each Operation of the Job)
*/

#include "scheduledJob.h"
#include <string.h>
#include "list.h"

/// <summary>
/// Creates a ScheduledJob with given arguments
/// </summary>
/// <param name="jobIdentifier"></param>
/// <param name="operations"></param>
/// <param name="duration"></param>
/// <returns></returns>
ScheduledJob CreateScheduledJob(char* jobIdentifier, List* operations, int duration) {
	
	ScheduledJob newJob;

	// Values' attribution
	newJob.jobIdentifier = jobIdentifier;
	newJob.operations = operations;
	newJob.duration = duration;

	return newJob;
}

/// <summary>
/// Print values of a ScheduledOperation from a list
/// </summary>
/// <param name="data"></param>
void ShowScheduledJob(void* data) {
	
	// Data type cast
	ScheduledJob* job = (ScheduledJob*)data;

	// Empty data is discarded
	if (!job) return;

	printf("Identifier: %s\n", job->jobIdentifier);
	ShowElements(job->operations, ShowScheduledOperation);
	printf("Duration: %d\n", job->duration);
}

/// <summary>
/// Compares a ScheduledJob's id with a given id, 
/// provided from a generic list
/// </summary>
/// <param name="jobData"></param>
/// <param name="ptrId"></param>
/// <returns></returns>
int CompareScheduledJobId(void* jobData, void* ptrId) {

	// Data casts to desired type
	ScheduledJob* job = (ScheduledJob*)jobData;
	int id = (int)ptrId;

	// Data comparisons
	if (!strcmp(job->jobIdentifier, id)) return 1;
	else return 0;
}

/// <summary>
/// Free memory from a ScheduledJob structure from a list
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
void* DeleteScheduledJob(void* data) {

	// Data type cast
	ScheduledJob* job = (ScheduledJob*)data;

	// Free memory from process
	job->operations = DeleteList(job->operations, DeleteScheduledOperation);

	// Return file without memory allocated from mallocs
	return NULL;
}