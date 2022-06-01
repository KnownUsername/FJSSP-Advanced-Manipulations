/*
	Student: João Rodrigues
	Student Number: 16928
	Lective year: 2021/2022

	Subject: Advanced Data Structures
	About: Second Practical Work

	File: tests.c
	Intent:
		- Test functions as they are implemented
*/

#include "list.h"
//#include "scheduledOperation.h"
#include <stdio.h>
//#include "scheduledJob.h"
#include "job.h"
#include"weightedJob.h"

int main() {

	int status;

	// Load of a csv with multiple Jobs
	List* jobs = LoadJobs("../template_data.csv", &status);

	ShowElements(jobs, ShowJob);

	printf("%d", status);
	List* weightedJobs = GenerateWeightedJobs(jobs, 60);

	ShowElements(weightedJobs, ShowWeightedJob);

	return 0;
}