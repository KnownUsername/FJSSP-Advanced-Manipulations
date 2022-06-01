#ifndef WEIGHT_PROCESS
#define WEIGHT_PROCESS

#include "process.h"

/// <summary>
/// Defines a Process with weights
/// </summary>
typedef struct WeightedProcess
{
	char* jobIdentifier; // To keep id when using only structures' address
	int operationId; // To keep id when using only structures' address
	Process* process;
	int referenceTime; // process->time + startTime
	float cedency; // percent * process->time + (1-percent) * job->jobWeight -- illustrative
}WeightedProcess;


// Creates a WeightedProcess -> A Process with weights for measures
WeightedProcess CreateWeightedProcess(char* jobIdentifier, int operationId, Process* process, float processPercent, float jobFactor);

// Compares a WeightedOperation's id with a given id,
// provided from a generic list
int CompareWeightedProcesses(void* data, void* ptrId);
#endif 