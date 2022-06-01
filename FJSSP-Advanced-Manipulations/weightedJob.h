#ifndef WEIGHT_JOB
#define WEIGHT_JOB

#include "list.h"

typedef struct WeightedJob {
	char* jobId;
	List* weightedOperations;
};

#endif 
