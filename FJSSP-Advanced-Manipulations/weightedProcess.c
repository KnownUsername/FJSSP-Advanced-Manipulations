#include "weightedProcess.h"

/// <summary>
/// Creates a WeightedProcess -> A Process with weights for measures
/// </summary>
/// <param name="jobIdentifier"></param>
/// <param name="operationId"></param>
/// <param name="process"></param>
/// <param name="processPercent"> Percentage value for Process to calculate cedency </param>
/// <param name="jobFactor"> Weight from job pondered </param>
/// <returns></returns>
WeightedProcess CreateWeightedProcess(char* jobIdentifier, int operationId, Process* process, float processPercent,float jobFactor) {

	WeightedProcess newWeightedProcess;

	// Values' attribution
	newWeightedProcess.jobIdentifier = jobIdentifier;
	newWeightedProcess.operationId = operationId;
	newWeightedProcess.process = process;
	newWeightedProcess.referenceTime = process->time;
	newWeightedProcess.cedency = processPercent*process->time + jobFactor;

	return newWeightedProcess;
}

/// <summary>
/// Compares a WeightedProcess's id with a given id,
/// provided from a generic list
/// </summary>
/// <param name="data"></param>
/// <param name="ptrId"></param>
/// <returns></returns>
int CompareWeightedProcesses(void* data, void* ptrId) {

	// Data casts to desired type
	WeightedProcess* process = (WeightedProcess*)data;
	int id = (int)ptrId;

	// Data comparisons
	if (process->jobIdentifier == id) return 1;
	else return 0;
}

/// <summary>
/// Print values of a WeightedProcess from a generic list
/// </summary>
/// <param name="data"></param>
void ShowWeightedProcess(void* data) {
	
	// Data type cast
	WeightedProcess* weightedProcess = (WeightedProcess*)data;

	// Empty data is discarded
	if (!weightedProcess) return;

	printf("Job: %s\n", weightedProcess->jobIdentifier);
	printf("Operation: %d\n", weightedProcess->operationId);

	// Print Process if exists
	if(weightedProcess->process) ShowProcess(*weightedProcess->process);

	printf("Reference Time: %d\n", weightedProcess->referenceTime);
	printf("Cedency: %f\n", weightedProcess->cedency);

}