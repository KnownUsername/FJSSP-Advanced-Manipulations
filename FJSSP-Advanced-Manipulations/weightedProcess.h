#ifndef WEIGHT_PROCESS
#define WEIGHT_PROCESS

#include "process.h"

typedef struct WeightedProcess
{
	char* jobIdentifier; // To keep id when using only structures' address
	int operationId; // To keep id when using only structures' address
	Process* process;
	int referenceTime; // process->time + startTime
	float cedency; // percent * process->time + (1-percent) * job->jobWeight -- illustrative
}WeightedProcess;



#endif 