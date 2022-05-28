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
