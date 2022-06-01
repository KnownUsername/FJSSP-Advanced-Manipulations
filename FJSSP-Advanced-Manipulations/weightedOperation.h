#ifndef WEIGHT_OPERATION
#define WEIGHT_OPERATION
#include"list.h"
#include"operation.h"

/// <summary>
/// Defines an Operation constituded by Processes with weights
/// </summary>
typedef struct WeightedOperation{
	int operationId;
	List* weightedProcesses;
}WeightedOperation;

// Creates a WeightedProcess -> A Process with weights for measures
WeightedOperation CreateWeightedOperation(Operation operation, char* jobIdentifier, float processPercent, float jobFactor);

// Compares a WeightedProcess's id with a given id,
// provided from a generic list
int CompareWeightedProcesses(void* operationData, void* ptrId);

// Print values of a WeightedOperation from a generic list
void ShowWeightedOperation(void* data);
#endif