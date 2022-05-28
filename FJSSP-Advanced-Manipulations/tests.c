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
#include "scheduledOperation.h"
#include <stdio.h>


int main() {

	List* scheduledOperations = NULL;

	ScheduledOperation scheduledOperation = CreateScheduledOperation(76, NULL, 0, 2);

	scheduledOperations = InsertListItem(scheduledOperations, &scheduledOperation,CompareScheduledOperations);

	ScheduledOperation scheduledOperation2 = CreateScheduledOperation(35, NULL, 3, 4);
	scheduledOperations = InsertListItem(scheduledOperations, &scheduledOperation2,CompareScheduledOperations);
	scheduledOperations = InsertListItem(scheduledOperations, &scheduledOperation2, CompareScheduledOperations);

	int number = 1;
	
	List* auxResult = SearchElement(scheduledOperations, number, CompareScheduledOperationId);
	if (auxResult) {
		ScheduledOperation* result = (ScheduledOperation*)auxResult->data;
	}
	else printf("Bye World\n");

	ShowElements(scheduledOperations, ShowScheduledOperation);
	printf("\n\n Ora viva!\n\n");
	scheduledOperations = RemoveElement(scheduledOperations, 35,CompareScheduledOperationId, DeleteScheduledOperation);

	ShowElements(scheduledOperations, ShowScheduledOperation);

	return 0;
}