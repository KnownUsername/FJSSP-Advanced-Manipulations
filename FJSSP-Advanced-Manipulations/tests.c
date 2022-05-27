#include "list.h"
#include "scheduledOperation.h"
#include <stdio.h>


int main() {

	List* scheduledOperations = NULL;

	ScheduledOperation scheduledOperation = CreateScheduledOperation(1, NULL, 0, 2);

	scheduledOperations = InsertListItem(scheduledOperations, &scheduledOperation,CompareScheduledOperationId);

	ScheduledOperation scheduledOperation2 = CreateScheduledOperation(2, NULL, 3, 4);
	scheduledOperations = InsertListItem(scheduledOperations, &scheduledOperation2,CompareScheduledOperationId);
	scheduledOperations = InsertListItem(scheduledOperations, &scheduledOperation2, CompareScheduledOperations);

	int number = 1;
	
	List* auxResult = SearchElement(scheduledOperations, number, CompareScheduledOperationId);
	ScheduledOperation* result = (ScheduledOperation*)auxResult->data;
	
	
	if (result) printf("%d\n", result->operationID);
	else printf("NULL\n");

	int i = 0;
	while (scheduledOperations) {
		printf("\n%d\n", ++i);
		scheduledOperations = scheduledOperations->next;
	}

	return 0;
}