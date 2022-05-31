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