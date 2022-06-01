/*
    Student: João Rodrigues
    Student Number: 16928
    Lective year: 2021/2022

    Subject: Advanced Data Structures
    About: First Practical Work

    File: job.c
    Intent:
        - Implement functions to manipulate 1 Job
*/

#include "job.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "list.h"
#pragma warning(disable: 4996)

/// <summary>
/// Inserts values of 1 Job from a file
/// status takes value 1 if it loaded with success
///                 or 0 if file not found
/// </summary>
/// <param name="filename"></param>
/// <returns>Loaded Job from file </returns>
Job LoadJob(char filename[], int* status) {

    Job job;
    job.operations = NULL;

    Operation* operationElement;
    Process process;

    Operation operation;

	FILE* fp;
    char processPlan[100], column2[100], column3[100], column4[100];
    int operationId;

    // Read file
	fp = fopen(filename, "r");

    // Verify if file exists
    if (!fp) {
        *status = 0;
        return job;
    }

    // Skip 1st line (columns' names)
    if (!feof(fp)) fscanf(fp, "%[^\,],%[^\,],%[^\,]\,%[^\n]\n", processPlan, column2, column3, column4);

    // Walk through file
    while (!feof(fp)) {

        fscanf(fp, "%[^\,]\,%d\,%d\,%d\n", processPlan, &operationId, &process.machine, &process.time); // Get fields from each line

        // Job ID
        job.jobIdentifier = strdup(processPlan);

        // On operations that are already present on a job, simply add the new Process to it
        if (OperationExists(job.operations, operationId)) {

            // Find pointer to Operation inputted
            operationElement = SearchOperation(job.operations, operationId);

            // Insert new process on Operation
            operationElement->alternProcesses = InsertProcess(operationElement->alternProcesses, process);
        }

        // Add new Operation
        else {
            // Create new operation with associated Process on same file line
            operation = CreateOperation(operationId, InsertProcess(NULL, process));

            // Add new operation to the job
            job.operations = InsertOperation(job.operations, operation);
        }

    }

    // Delete file's buffer
    fclose(fp);

    return job;
}

/// <summary>
/// Calculates the minimum duration for a job and its respective path
/// Path is defined by the set of Processes with less duration on each Operation
/// </summary>
/// <param name="job"></param>
/// <returns></returns>
JobProcess GetMinimumJobProcessLine(Job job) {
    JobProcess jobProcess;
    jobProcess.fullDuration = 0;
    jobProcess.job.jobIdentifier = job.jobIdentifier;
    jobProcess.job.operations = (OperationList*)malloc(sizeof(Operation));
    jobProcess.job.operations = NULL;

    ProcessList* minimumTimeProcess = (ProcessList*)malloc(sizeof(ProcessList));
    minimumTimeProcess->nextProcess = NULL;

    // On empty list, duration becomes -1, in signal of error
    if (!job.operations) jobProcess.fullDuration = -1;

    // Cycle through operations
    while (job.operations) {

        // Get Process with minimal duration
        minimumTimeProcess->process = GetMinimumDurationProcess(job.operations->operation.alternProcesses);
        
        
        // Insert new Operation with respective Process with minimum time consumption
        jobProcess.job.operations = InsertOperation(jobProcess.job.operations, CreateOperation(job.operations->operation.opIdentifier, minimumTimeProcess));
    
        // Add duration from Process with less time of current operation
        jobProcess.fullDuration += minimumTimeProcess->process.time;
    
    
         // Go to next Operation
        job.operations = job.operations->nextOperation;
    }

    return jobProcess;
}

/// <summary>
/// Calculates the maximum duration for a job and its respective path
/// Path is defined by the set of Processes with higher duration on each Operation
/// </summary>
/// <param name="job"></param>
/// <returns></returns>
JobProcess GetMaximumJobProcessLine(Job job) {
    JobProcess jobProcess;

               /*      Initializations         */
    jobProcess.fullDuration = 0;
    jobProcess.job.jobIdentifier = job.jobIdentifier;
    jobProcess.job.operations = (OperationList*)malloc(sizeof(Operation));
    jobProcess.job.operations = NULL;

    // Pointer to a copy of the Process with maximum time on each Operation
    ProcessList* maximumTimeProcess = (ProcessList*)malloc(sizeof(ProcessList));
    maximumTimeProcess->nextProcess = NULL;

    // On empty list, duration becomes -1, in signal of error
    if (!job.operations) jobProcess.fullDuration = -1;


    // Cycle through operations
    while (job.operations) {

        // Get Process with maximum duration
        maximumTimeProcess->process = GetMaximumDurationProcess(job.operations->operation.alternProcesses);


        // Insert new Operation with respective Process with maximum time consumption
        jobProcess.job.operations = InsertOperation(jobProcess.job.operations, CreateOperation(job.operations->operation.opIdentifier, maximumTimeProcess));

        // Add duration from Process with less time of current operation
        jobProcess.fullDuration += maximumTimeProcess->process.time;


        // Go to next Operation
        job.operations = job.operations->nextOperation;
    }

    return jobProcess;
}

/// <summary>
/// Saves job data into a csv file
/// </summary>
/// <param name="job"></param>
/// <param name="filename"></param>
/// <returns></returns>
int SaveJob(Job job, char filename[]) {

    FILE* fp;

    fp = fopen(filename, "w");

    // 0 in case of error on opening file
    if (!fp) return 0;

    // Header
    fprintf(fp, "%s,%s,%s,%s\n", "process_plan", "operation", "machine", "time");

    // Navigate through Operations
    for (OperationList* operationList = job.operations; operationList ; operationList = operationList->nextOperation) {

        // Navigate through Processes
        for (ProcessList* processList = operationList->operation.alternProcesses; processList ; processList = processList->nextProcess) {

            // Job id | Operation id | machine | process time
            fprintf(fp, "%s,%d,%d,%d\n", job.jobIdentifier, operationList->operation.opIdentifier, processList->process.machine, processList->process.time);
        }
    }
    
    // Clean buffer from file data
    fclose(fp);

    return 1;
}

/// <summary>
/// Prints values of a Job
/// </summary>
/// <param name="job"></param>
void ShowJob(Job job) {

    printf("--> Job ID: %s\n\n", job.jobIdentifier);
    ShowOperationList(job.operations);
}

/// <summary>
/// Prints values of a JobProcess
/// </summary>
/// <param name="jobProcess"></param>
void ShowJobProcess(JobProcess jobProcess) {

    ShowOperationList(jobProcess.job.operations);
    printf("Total time: %d", jobProcess.fullDuration);
}

/// <summary>
/// Compares a Job's id with a given id,
/// from a list
/// </summary>
/// <param name="jobData"></param>
/// <param name="ptrId"></param>
/// <returns></returns>
int CompareJobs(void* jobData, char* ptrId) {

    // Data cast to desired type
    Job* job = (Job*)jobData;

    // Data comparisons
    if (!strcmp(job->jobIdentifier,ptrId)) return 1;
    else return 0;
}

/// <summary>
/// Print values from a Job from a generic list
/// </summary>
/// <param name="data"></param>
void ShowJobFromList(void* data) {

    // Data type cast
    Job* job = (Job*)data;

    // Discard empty jobs
    if (!job) return;

    ShowJob(*job);
}

/// <summary>
/// Free memory from a Job structure from a generic list
/// </summary>
/// <param name="data"></param>
/// <returns></returns>
void* DeleteJobDataFromList(void* data) {

    // Data type cast
    Job* job = (Job*)data;

    // Free memory from job's operations
    job->operations = DeleteOperationList(job->operations);

    // Return job without memory allocated from mallocs
    return job;
}

/// <summary>
/// Creates a job with given values
/// </summary>
/// <param name="jobIdentifier"></param>
/// <param name="operations"></param>
/// <returns></returns>
Job CreateJob(char* jobIdentifier, OperationList* operations) {

    Job job;

    // Values' attribution
    job.jobIdentifier = jobIdentifier;
    job.operations = operations;

    return job;
}

/// <summary>
/// Inserts values of multiple Jobs from a file
/// status takes value 1 if it loaded with success
///                 or 0 if file not found
/// </summary>
/// <param name="filename">Path of the file</param>
/// <returns>Loaded Job from file </returns>
List* LoadJobs(char filename[], int* status) {

    Job* jobToAdd;
    List* jobs = NULL, * jobListPtr = NULL;


    Operation* operationElement = NULL;
    Process process;

    Operation operation;

    FILE* fp;
    char processPlan[100], column2[100], column3[100], column4[100];
    int operationId;

    // Read file
    fp = fopen(filename, "r");

    // Verify if file exists
    if (!fp) {
        *status = 0;
        return jobs;
    }

    // Skip 1st line (columns' names)
    if (!feof(fp)) fscanf(fp, "%[^\,],%[^\,],%[^\,]\,%[^\n]\n", processPlan, column2, column3, column4);

    // Walk through file
    while (!feof(fp)) {

        Job job;
        job.operations = NULL;

        fscanf(fp, "%[^\,]\,%d\,%d\,%d\n", processPlan, &operationId, &process.machine, &process.time); // Get fields from each line

        printf("%s, %d, %d, %d\n", processPlan, operationId, process.machine, process.time);
        // Create a Job with received identifier 
        job = CreateJob(processPlan, NULL);

        // Insert Job if there's no job with received identifier 
        jobs = InsertListItem(jobs, &job, CompareJobs);

        // Get address from allocated Job on list
        jobListPtr = SearchElement(jobs, processPlan, CompareJobs);

        // Get Address of wanted Job
        jobToAdd = (Job*)jobListPtr->data;

        // On operations that are already present on a job, simply add the new Process to it
        if (OperationExists(jobToAdd->operations, operationId)) {

            // Find pointer to Operation inputted
            operationElement = SearchOperation(jobToAdd->operations, operationId);

            // Insert new process on Operation
            operationElement->alternProcesses = InsertProcess(operationElement->alternProcesses, process);
        }

        // Add new Operation
        else {
            // Create new operation with associated Process on same file line
            operation = CreateOperation(operationId, InsertProcess(NULL, process));

            // Add new operation to the job
            job.operations = InsertOperation(job.operations, operation);
        }
    }

    // Delete file's buffer
    fclose(fp);

    *status = 1;
    return jobs;
}