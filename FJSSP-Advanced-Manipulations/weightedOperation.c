#include "weightedOperation.h"
#include "operation.h"
#include "weightedProcess.h"

/// <summary>
/// Compares a WeightedOperation's id with a given id,
/// provided from a generic list
/// </summary>
/// <param name="operationData"></param>
/// <param name="ptrId"></param>
/// <returns></returns>
int CompareWeightedOperations(void* operationData, void* ptrId) {

	// Data casts to desired type
	WeightedOperation* operation = (WeightedOperation*)operationData;
	int id = (int)ptrId;

	// Data comparisons
	if (operation->operationId == id) return 1;
	else return 0;
}

/// <summary>
/// Creates a WeightedOperation -> An Operation containing Processes with weights for measures
/// </summary>
/// <param name="operation"></param>
/// <param name="jobIdentifier"></param>
/// <param name="processPercent"> Percentage of how much consideration, the process must be over its job weight. 
/// It's value is already normalized from 0 to 1.</param>
/// <param name="jobFactor"> Weight from job </param>
/// <returns></returns>
WeightedOperation CreateWeightedOperation(Operation operation, char* jobIdentifier,float processPercent, float jobFactor) {

	WeightedOperation weightedOperation;
	weightedOperation.operationId = operation.opIdentifier;

	ProcessList* processes = weightedOperation.weightedProcesses;

	WeightedProcess currentWeightedProcess;

	while (processes)
	{
		// Build a WeightProcess from a Process from the list
		currentWeightedProcess = CreateWeightedProcess(jobIdentifier, operation.opIdentifier, &processes->process, processPercent, jobFactor);
		
		// Insert new WeightProcess on the list related to the current WeightedOperation
		weightedOperation.weightedProcesses = InsertListItem(weightedOperation.weightedProcesses, &currentWeightedProcess, CompareWeightedProcesses);
	
	}


	return weightedOperation;

}