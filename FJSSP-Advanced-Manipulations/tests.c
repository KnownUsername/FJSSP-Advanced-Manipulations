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
	//List* jobs = LoadJobs("../template_data.csv", &status);

	//ShowElements(jobs, ShowJob);

	List* jobs = NULL;
	Job job1 = CreateJob("first", NULL);

	job1.operations = InsertOperation(job1.operations, CreateOperation(1, NULL));
	job1.operations->operation.alternProcesses = InsertProcess(job1.operations->operation.alternProcesses, CreateProcess(1, 1));
	job1.operations->operation.alternProcesses = InsertProcess(job1.operations->operation.alternProcesses, CreateProcess(3, 4));

	Job job2 = CreateJob("second", NULL);

	job2.operations = InsertOperation(job2.operations, CreateOperation(1, NULL));
	job2.operations->operation.alternProcesses = InsertProcess(job2.operations->operation.alternProcesses, CreateProcess(1, 7));
	job2.operations->operation.alternProcesses = InsertProcess(job2.operations->operation.alternProcesses, CreateProcess(2, 9));

	jobs = InsertListItem(jobs, &job1, CompareJobs);
	jobs = InsertListItem(jobs, &job2, CompareJobs);

	ShowElements(jobs, ShowJob);

	jobs = RemoveElement(jobs, job2.jobIdentifier, CompareJobs, DeleteJobDataFromList);

	ShowElements(jobs, ShowJob);

	job1.operations = RemoveOperation(job1.operations, 1);

	ShowJob(job1);
	//printf("%d", status);
	//List* weightedJobs = GenerateWeightedJobs(jobs, 60);

	//ShowElements(weightedJobs, ShowWeightedJob);

	return 0;
}